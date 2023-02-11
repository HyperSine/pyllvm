#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, Tuple, Set, Callable, Optional

import importlib.resources

import lark
import lark.grammars
import lark.visitors

if TYPE_CHECKING:
    from .type_manager import TypeManager

class Pybind11FunctionSignature:

    @classmethod
    def parser(cls) -> lark.Lark:
        if not hasattr(cls, '__parser__'):
            with importlib.resources.open_text(lark.grammars, 'python.lark') as f:
                grammar = f.read() + \
                    '''
                    pybind11_funcsig: [name] "(" [parameters] ")" ["->" test]
                    '''
                cls.__parser__ = lark.Lark(grammar, start = 'pybind11_funcsig', parser = 'lalr', maybe_placeholders = True)

        # noinspection PyUnresolvedReferences
        return cls.__parser__

    class TypepathVisitor(lark.visitors.Interpreter):

        def __init__(self, callback: Callable[[Tuple[str, ...]], None]):
            self._user_callback = callback

        def __default__(self, ast: lark.Tree):
            raise NotImplementedError('todo: {}'.format(ast))

        def const_none(self, ast: lark.Tree):
            pass

        def ellipsis(self, ast: lark.Tree):
            pass

        def getattr(self, ast: lark.Tree):
            self._user_callback(self._resolve_typepath(ast))

        def getitem(self, ast: lark.Tree):
            ast_expr, ast_subscriptlist = ast.children

            self.visit(ast_expr)
            if ast_subscriptlist.data == 'subscript_tuple':
                self.visit_children(ast_subscriptlist)
            else:
                self.visit(ast_subscriptlist)

        def list(self, ast: lark.Tree):
            self.visit_children(ast)

        def var(self, ast: lark.Tree):
            self._user_callback(self._resolve_typepath(ast))

        def typedparam(self, ast: lark.Tree):
            ast_name, ast_type = ast.children
            self.visit(ast_type)

        def paramvalue(self, ast: lark.Tree):
            ast_typedparam, ast_default = ast.children
            if ast_typedparam.data == 'typedparam':
                self.visit(ast_typedparam)

        def pybind11_funcsig(self, ast: lark.Tree):
            _, ast_params, ast_rettype = ast.children

            if ast_params is not None:
                assert ast_params.data == 'parameters'
                for ast_param in filter(lambda t: t is not None, ast_params.children):
                    self.visit(ast_param)

            if ast_rettype is not None:
                self.visit(ast_rettype)

        def _resolve_typepath(self, tree: lark.Tree) -> Tuple[str, ...]:
            if tree.data == 'getattr':
                ast_expr, ast_name = tree.children
                assert ast_name.data == 'name'

                tkn_NAME, = ast_name.children
                assert tkn_NAME.type == 'NAME'

                return self._resolve_typepath(ast_expr) + (tkn_NAME.value,)
            elif tree.data == 'var':
                ast_name, = tree.children
                assert ast_name.data == 'name'

                tkn_NAME, = ast_name.children
                assert tkn_NAME.type == 'NAME'

                return tkn_NAME.value,
            else:
                raise NotImplementedError('todo: {}'.format(tree))

    class LiteralStringTransformer(lark.visitors.Interpreter):

        def __default__(self, ast: lark.Tree):
            raise NotImplementedError('todo: {}'.format(ast))

        def const_false(self, ast: lark.Tree):
            return 'False'

        def const_true(self, ast: lark.Tree):
            return 'True'

        def const_none(self, ast: lark.Tree):
            return 'None'

        def number(self, ast: lark.Tree):
            tkn_NUMBER, = ast.children
            assert any(tkn_NUMBER.type == t for t in ('DEC_NUMBER', 'HEX_NUMBER', 'BIN_NUMBER', 'OCT_NUMBER', 'FLOAT_NUMBER', 'IMAG_NUMBER'))
            return tkn_NUMBER.value

        def string(self, ast: lark.Tree):
            tkn_STRING, = ast.children
            assert tkn_STRING.type == 'STRING'
            return tkn_STRING.value

    class TypeStringTransformer(lark.visitors.Interpreter):

        def __init__(self, type_manager: TypeManager):
            self._type_manager = type_manager

        def __default__(self, ast: lark.Tree):
            raise NotImplementedError('todo: {}'.format(ast))

        def const_none(self, ast: lark.Tree):
            return 'None'

        def ellipsis(self, ast: lark.Tree):
            return '...'

        def getattr(self, ast: lark.Tree):
            return self._type_manager.repr_of(self._resolve_typepath(ast))

        def getitem(self, ast: lark.Tree):
            ast_expr, ast_subscriptlist = ast.children
            return '{}[{}]'.format(self.visit(ast_expr), self.visit(ast_subscriptlist))

        def subscript_tuple(self, ast: lark.Tree):
            return ', '.join(self.visit_children(ast))

        def list(self, ast: lark.Tree):
            return '[{}]'.format(', '.join(self.visit_children(ast)))

        def var(self, ast: lark.Tree):
            return self._type_manager.repr_of(self._resolve_typepath(ast))

        def _resolve_typepath(self, ast: lark.Tree) -> Tuple[str, ...]:
            if ast.data == 'getattr':
                ast_expr, ast_name = ast.children
                assert ast_name.data == 'name'

                tkn_NAME, = ast_name.children
                assert tkn_NAME.type == 'NAME'

                return self._resolve_typepath(ast_expr) + (tkn_NAME.value,)
            elif ast.data == 'var':
                ast_name, = ast.children
                assert ast_name.data == 'name'

                tkn_NAME, = ast_name.children
                assert tkn_NAME.type == 'NAME'

                return tkn_NAME.value,
            else:
                raise NotImplementedError('todo: {}'.format(ast))

    class DefStringTransformer(lark.visitors.Interpreter):

        def __init__(self, type_manager: TypeManager, **kwargs):
            super().__init__()

            self._type_manager = type_manager

            if 'func_name' in kwargs:
                self._override_func_name = True
                self._func_name = kwargs['func_name']
                assert isinstance(self._func_name, str)
            else:
                self._override_func_name = False

            self._keep_cls_type = kwargs.get('keep_cls_type', False)
            self._keep_self_type = kwargs.get('keep_self_type', False)

        def __default__(self, tree):
            raise NotImplementedError('todo: {}'.format(tree))

        def pybind11_funcsig(self, ast: lark.Tree):
            ast_name, ast_params, ast_rettype = ast.children

            if ast_name is None:
                s_name = ''
            else:
                assert ast_name.data == 'name'

                tkn_NAME, = ast_name.children
                assert tkn_NAME.type == 'NAME'

                s_name = tkn_NAME.value

            if ast_params is None:
                s_params = ''
            else:
                assert ast_params.data == 'parameters'
                s_params = ', '.join(self._param_visit(ast_param, i == 0) for i, ast_param in enumerate(filter(lambda t: t is not None, ast_params.children)))

            if ast_rettype is None:
                s_rettype = ''
            else:
                s_rettype = Pybind11FunctionSignature.TypeStringTransformer(self._type_manager).visit(ast_rettype)

            if self._override_func_name:
                s_name = self._func_name

            assert s_name.isidentifier()

            if len(s_rettype) > 0:
                return 'def {}({}) -> {}:'.format(s_name, s_params, s_rettype)
            else:
                return 'def {}({}):'.format(s_name, s_params)

        def _param_visit(self, ast: lark.Tree, is_first: bool) -> str:
            if ast.data == 'typedparam':
                ast_name, ast_type = ast.children
                assert ast_name.data == 'name'

                tkn_NAME, = ast_name.children
                assert tkn_NAME.type == 'NAME'

                s_name = tkn_NAME.value
                if is_first and s_name == 'cls' and not self._keep_cls_type:
                    return s_name
                elif is_first and s_name == 'self' and not self._keep_self_type:
                    return s_name
                else:
                    return '{}: {}'.format(s_name, Pybind11FunctionSignature.TypeStringTransformer(self._type_manager).visit(ast_type))
            elif ast.data == 'paramvalue':
                ast_typedparam, ast_default = ast.children
                if ast_typedparam.data == 'typedparam':
                    s1 = self._param_visit(ast_typedparam, is_first)
                    s2 = Pybind11FunctionSignature.LiteralStringTransformer().visit(ast_default)
                    return '{} = {}'.format(s1, s2)
                else:
                    raise NotImplementedError('todo: {}'.format(ast))
            else:
                raise NotImplementedError('todo: {}'.format(ast))

    def __init__(self, sig_string: str):
        self._ast = self.parser().parse(sig_string)
        assert self._ast.data == 'pybind11_funcsig' and len(self._ast.children) == 3

        self._ast_name = self._ast.children[0]  # type: Optional[lark.Tree]

        if self._ast.children[1] is None:
            self._ast_params = ()  # type: Tuple[lark.Tree, ...]
        else:
            self._ast_params = tuple(filter(lambda t: t is not None, self._ast.children[1].children)) # type: Tuple[lark.Tree, ...]

        self._ast_rettype = self._ast.children[2]    # type: Optional[lark.Tree]

    def func_name(self) -> Optional[str]:
        if self._ast_name is None:
            return None
        else:
            assert self._ast_name.data == 'name'

            tkn_NAME, = self._ast_name.children   # type: lark.Token
            assert tkn_NAME.type == 'NAME'

            return tkn_NAME.value

    def func_argname(self, i: int) -> str:
        ast_param = self._ast_params[i]
        if ast_param.data == 'typedparam':
            ast_name, _ = ast_param.children
            assert ast_name.data == 'name'

            tkn_NAME, = ast_name.children
            assert tkn_NAME.type == 'NAME'

            return tkn_NAME.value
        else:
            raise NotImplementedError('todo: {}'.format(ast_param))

    def referred_typepaths(self) -> Set[Tuple[str, ...]]:
        typepaths = set()
        self.TypepathVisitor(typepaths.add).visit(self._ast)
        return typepaths

    def make_defstring(self, type_manager: TypeManager, **kwargs) -> str:
        return self.DefStringTransformer(type_manager, **kwargs).visit(self._ast)
