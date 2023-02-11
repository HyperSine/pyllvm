#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, Tuple

import weakref

from .stub_generator import StubGenerator
from ..pybind11_funcsig import Pybind11FunctionSignature

if TYPE_CHECKING:
    from ..generator_manager import GeneratorManager

class PropertyStubGenerator(StubGenerator):

    def __init__(self, manager: GeneratorManager, prop: property, prop_name: str, parent_stubgen: StubGenerator):
        from .class_stub_generator import ClassStubGenerator

        assert prop_name.isidentifier()
        assert isinstance(parent_stubgen, ClassStubGenerator)

        super().__init__(manager)

        self.prop = prop
        self.prop_name = prop_name
        self.prop_path = parent_stubgen.path() + (prop_name,)
        self.prop_qualname = '.'.join(self.prop_path)

        self.parent_stubgen = weakref.ref(parent_stubgen)

    def name(self) -> str:
        return self.prop_name

    def path(self) -> Tuple[str, ...]:
        return self.prop_path

    def qualname(self) -> str:
        return self.prop_qualname

    def run(self):
        parent_stubgen = self.parent_stubgen()
        parent_type_manager = parent_stubgen.get_type_manager()
        indent = self.manager().indent

        assert self.prop.fget is not None
        getter_doclines = self.prop.fget.__doc__.splitlines()
        if len(getter_doclines) == 1:
            getter_sig = Pybind11FunctionSignature(getter_doclines[0])

            for typepath in getter_sig.referred_typepaths():
                parent_type_manager.import_(typepath)

            parent_stubgen.push_line(indent, '@property')
            parent_stubgen.push_line(indent, getter_sig.make_defstring(parent_type_manager, func_name = self.prop_name))
            parent_stubgen.push_line(indent, '    pass')
            parent_stubgen.push_line(indent, '')
        else:
            raise NotImplementedError('todo: maybe multiple overload')

        if self.prop.fset is not None:
            setter_doclines = self.prop.fset.__doc__.splitlines()
            if len(setter_doclines) == 1:
                setter_sig = Pybind11FunctionSignature(setter_doclines[0])

                for typepath in setter_sig.referred_typepaths():
                    parent_type_manager.import_(typepath)

                parent_stubgen.push_line(indent, '@{}.setter'.format(self.prop_name))
                parent_stubgen.push_line(indent, setter_sig.make_defstring(parent_type_manager, func_name = self.prop_name))
                parent_stubgen.push_line(indent, '    pass')
                parent_stubgen.push_line(indent, '')
            else:
                raise NotImplementedError('todo: maybe multiple overload')

        assert self.prop.fdel is None
