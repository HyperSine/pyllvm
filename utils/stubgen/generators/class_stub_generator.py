#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, List, Tuple

import os, itertools, weakref
import logging
import inspect

from .stub_generator import StubGenerator
from ..type_manager import TypeManager

if TYPE_CHECKING:
    from ..generator_manager import GeneratorManager

__logger__ = logging.getLogger(__name__)

class ClassStubGenerator(StubGenerator):

    __ignored_base_typepaths__ = {
        ('builtins', 'object'),
        ('pybind11_builtins', 'pybind11_object'),
    }

    __ignored_properties__ = {
        '__doc__',
        '__members__',
    }

    __ignored_data_attributes__ = {
        '__entries',
        '__dict__',
        '__weakref__',
    }

    def __init__(self, manager: GeneratorManager, cls, cls_name: str, parent_stubgen: StubGenerator):
        from .attribute_stub_generator import AttributeStubGenerator
        from .classmethod_stub_generator import ClassMethodStubGenerator
        from .method_stub_generator import MethodStubGenerator
        from .module_stub_generator import ModuleStubGenerator
        from .property_stub_generator import PropertyStubGenerator
        from .staticmethod_stub_generator import StaticMethodStubGenerator

        assert inspect.isclass(cls)
        assert cls_name.isidentifier()
        assert isinstance(parent_stubgen, (ModuleStubGenerator, ClassStubGenerator))

        super().__init__(manager)

        self.cls = cls
        self.cls_name = cls_name
        self.cls_path = parent_stubgen.path() + (cls_name,)
        self.cls_qualname = '.'.join(self.cls_path)

        self.parent_stubgen = weakref.ref(parent_stubgen)

        self.class_stubgens = []
        self.classmethod_stubgens = []
        self.staticmethod_stubgens = []
        self.property_stubgens = []
        self.method_stubgens = []
        self.attribute_stubgens = []

        if isinstance(parent_stubgen, ClassStubGenerator):
            self._nest_level = parent_stubgen._nest_level + 1
        else:
            self._nest_level = 0

            assert self.cls_path not in self.manager().outer_classes
            self.manager().outer_classes.add(self.cls_path)

            self._type_manager = TypeManager(self.cls_path, self)
            self._output_lines = []  # type: List[str]

        for attr in inspect.classify_class_attrs(self.cls):
            if attr.defining_class is not self.cls:
                assert issubclass(self.cls, attr.defining_class)
                continue

            if attr.kind == 'class method':
                assert isinstance(attr.object, classmethod)
                raise NotImplementedError('stubgen for classmethod is not supported.')
            elif attr.kind == 'static method':
                assert isinstance(attr.object, staticmethod)
                if attr.name.startswith('__') and attr.name.endswith('__'):
                    __logger__.warning('staticmethod stubgen for preserved name `{}.{}`'.format(self.cls_qualname, attr.name))
                self.staticmethod_stubgens.append(StaticMethodStubGenerator(self.manager(), attr.object, attr.name, self))
            elif attr.kind == 'property':
                assert isinstance(attr.object, property)
                if attr.name not in self.__ignored_properties__:
                    if attr.name.startswith('__') and attr.name.endswith('__'):
                        __logger__.warning('property stubgen for preserved name `{}.{}`'.format(self.cls_qualname, attr.name))
                    self.property_stubgens.append(PropertyStubGenerator(self.manager(), attr.object, attr.name, self))
            elif attr.kind == 'method':
                if attr.name.startswith('__') and attr.name.endswith('__'):
                    __logger__.debug('method stubgen for preserved name `{}.{}`'.format(self.cls_qualname, attr.name))
                self.method_stubgens.append(MethodStubGenerator(self.manager(), attr.object, attr.name, self))
            else:
                assert attr.kind == 'data'
                if attr.name != '__class__' and inspect.isclass(attr.object):
                    next_cls = attr.object
                    next_cls_name = attr.name
                    next_cls_qualname = '{}.{}'.format(self.qualname(), next_cls_name)

                    if next_cls_qualname in self.manager().skip_qualnames:
                        __logger__.info('Skip class `{}`'.format(next_cls_qualname))
                    else:
                        self.class_stubgens.append(ClassStubGenerator(self.manager(), next_cls, next_cls_name, self))
                elif isinstance(attr.object, self.cls):
                    self.attribute_stubgens.append(AttributeStubGenerator(self.manager(), attr.object, attr.name, self))
                elif attr.name == '__doc__':
                    pass    # skip for now
                elif attr.name == '__module__':
                    assert isinstance(attr.object, str)

                    stubgen = self.parent_stubgen()
                    while not isinstance(stubgen, ModuleStubGenerator):
                        stubgen = stubgen.parent_stubgen()

                    assert stubgen.qualname() == attr.object
                elif attr.name in self.__ignored_data_attributes__:
                    pass
                else:
                    raise NotImplementedError('Unexpected attribute `{}.{}`: {}'.format(self.qualname(), attr.name, attr.object))

    def name(self) -> str:
        return self.cls_name

    def path(self) -> Tuple[str, ...]:
        return self.cls_path

    def qualname(self) -> str:
        return self.cls_qualname

    def run(self):
        base_typepaths = \
            list(map(lambda b: tuple(b.__module__.split('.') + b.__name__.split('.')), self.cls.__bases__))

        base_typepaths = \
            list(filter(lambda tp: tp not in self.__ignored_base_typepaths__, base_typepaths))

        if len(base_typepaths) == 0:
            i0 = self.push_line(0, 'class {}:'.format(self.cls_name))
            i1 = self.push_line(0, '')
        else:
            type_manager = self.get_type_manager()
            for typepath in base_typepaths:
                type_manager.import_(typepath)
            i0 = self.push_line(0, 'class {}({}):'.format(self.cls_name, ', '.join(map(type_manager.repr_of, base_typepaths))))
            i1 = self.push_line(0, '')

        for stubgen in self.class_stubgens:
            stubgen.run()

        if len(self.attribute_stubgens) > 0:
            for stubgen in self.attribute_stubgens:
                stubgen.run()
            self.push_line(0, '')

        for stubgen in itertools.chain(self.classmethod_stubgens,
                                       self.staticmethod_stubgens,
                                       self.property_stubgens,
                                       self.method_stubgens):
            stubgen.run()

        if i1 + 1 == self.get_line_num():
            self.pop_line()
            self.push_line(0, '    pass')
            self.push_line(0, '')

        if self._nest_level == 0:
            self.emit_file(os.path.join(self.manager().output_dir, *self.cls_path[1:-1], '{}.pyi'.format(self.cls_name)))

    def get_type_manager(self) -> TypeManager:
        if self._nest_level == 0:
            return self._type_manager
        else:
            return self.parent_stubgen().get_type_manager()

    def get_line(self, i: int) -> str:
        if self._nest_level == 0:
            return self._output_lines[i]
        else:
            return self.parent_stubgen().get_line(i)

    def get_line_num(self) -> int:
        if self._nest_level == 0:
            return len(self._output_lines)
        else:
            return self.parent_stubgen().get_line_num()

    def push_line(self, indent: int, line: str) -> int:
        if self._nest_level == 0:
            i = len(self._output_lines)
            if len(line) > 0:
                self._output_lines.append(' ' * indent + line)
            else:
                self._output_lines.append(line)
            return i
        else:
            return self.parent_stubgen().push_line(indent + self.manager().indent, line)

    def pop_line(self, i: int = -1) -> str:
        if self._nest_level == 0:
            return self._output_lines.pop(i)
        else:
            return self.parent_stubgen().pop_line(i)

    def emit_file(self, filepath: str):
        os.makedirs(os.path.dirname(filepath), exist_ok = True)

        with open(filepath, 'w') as f:
            for l in self._type_manager.make_import_strings():
                f.write(l)
                f.write('\n')

            for i, line in enumerate(self._output_lines):
                if i != 0 or f.tell() > 0:
                    f.write('\n')
                f.write(line)
