#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, List, Tuple, Optional

import os, itertools, weakref
import logging
import inspect

from .stub_generator import StubGenerator
from ..type_manager import TypeManager

if TYPE_CHECKING:
    from ..generator_manager import GeneratorManager

__logger__ = logging.getLogger(__name__)

class ModuleStubGenerator(StubGenerator):

    __ignored_attributes__ = {
        '__doc__',
        '__file__',
        '__loader__',
        '__name__',
        '__package__',
        '__spec__'
    }

    def __init__(self, manager: GeneratorManager, module, parent_stubgen: Optional[StubGenerator] = None):
        from .attribute_stub_generator import AttributeStubGenerator
        from .class_stub_generator import ClassStubGenerator
        from .function_stub_generator import FunctionStubGenerator

        super().__init__(manager)

        self.module = module
        self.module_qualname = module.__name__

        self.module_path = tuple(module.__name__.split('.'))   # type: Tuple[str, ...]
        assert all(n.isidentifier() for n in self.module_path)

        self.module_name = self.module_path[-1]

        if parent_stubgen is not None:
            assert isinstance(parent_stubgen, ModuleStubGenerator)
            self.parent_stubgen = weakref.ref(parent_stubgen)

        self.submodule_stubgens = []
        self.class_stubgens = []
        self.function_stubgens = []
        self.attribute_stubgens = []

        self._type_manager = TypeManager(self.module_path + ('__init__',), self)
        self._output_lines = []  # type: List[str]

        for member_name, member in inspect.getmembers(self.module):
            if member_name in self.__ignored_attributes__:
                __logger__.debug('Skip attribute `{}.{}`'.format(self.module_qualname, member_name))
            elif inspect.ismodule(member):
                next_module = member
                next_module_qualname = next_module.__name__ # type: str

                if next_module_qualname in self.manager().skip_qualnames:
                    __logger__.debug('Skip module `{}`'.format(next_module_qualname))
                else:
                    assert next_module_qualname.startswith(self.module_qualname)
                    self.submodule_stubgens.append(ModuleStubGenerator(self.manager(), member, self))
            elif inspect.isclass(member):
                next_class = member
                next_class_name = next_class.__name__ # type: str
                next_class_qualname = '{}.{}'.format(self.module_qualname, next_class_name)

                if next_class_qualname in self.manager().skip_qualnames:
                    __logger__.debug('Skip class `{}`'.format(next_class_qualname))
                else:
                    self.class_stubgens.append(ClassStubGenerator(self.manager(), next_class, next_class_name, self))
            elif inspect.isbuiltin(member) or inspect.isfunction(member):
                next_func = member
                next_func_name = next_func.__name__
                next_func_qualname = '{}.{}'.format(self.module_qualname, next_func_name)

                if next_func_qualname in self.manager().skip_qualnames:
                    __logger__.debug('Skip function `{}`'.format(next_func_qualname))
                else:
                    self.function_stubgens.append(FunctionStubGenerator(self.manager(), next_func, next_func_name, self))
            else:
                self.attribute_stubgens.append(AttributeStubGenerator(self.manager(), member, member_name, self))
                #raise NotImplementedError('Unexpected member `{}.{}`: {}'.format(self.module_qualname, member_name, member))

    def name(self) -> str:
        return self.module_name

    def path(self) -> Tuple[str, ...]:
        return self.module_path

    def qualname(self) -> str:
        return self.module_qualname

    def run(self):
        for stubgen in self.submodule_stubgens:
            stubgen.run()

        for stubgen in self.class_stubgens:
            stubgen.run()

        for stubgen in itertools.chain(self.attribute_stubgens, self.function_stubgens):
            stubgen.run()

        for stubgen in self.class_stubgens:
            self._type_manager.import_(stubgen.path(), True)

        self.emit_file(os.path.join(self.manager().output_dir, *self.module_path[1:], '__init__.pyi'))

    def get_type_manager(self) -> TypeManager:
        return self._type_manager

    def get_line(self, i: int) -> str:
        return self._output_lines[i]

    def get_line_num(self) -> int:
        return len(self._output_lines)

    def push_line(self, indent: int, line: str) -> int:
        i = len(self._output_lines)
        if len(line) > 0:
            self._output_lines.append(' ' * indent + line)
        else:
            self._output_lines.append(line)
        return i

    def pop_line(self, i: int = -1) -> str:
        return self._output_lines.pop(i)

    def emit_file(self, filepath: str):
        with open(filepath, 'w') as f:
            for stubgen in self.submodule_stubgens:
                f.write('from . import {0:} as {0:}'.format(stubgen.name()))

            for l in self._type_manager.make_import_strings():
                f.write(l)
                f.write('\n')

            for i, line in enumerate(self._output_lines):
                if i != 0 or f.tell() > 0:
                    f.write('\n')
                f.write(line)
