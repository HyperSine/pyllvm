#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, Tuple

import weakref

from .stub_generator import StubGenerator

if TYPE_CHECKING:
    from ..generator_manager import GeneratorManager

class AttributeStubGenerator(StubGenerator):

    def __init__(self, manager: GeneratorManager, attr, attr_name: str, parent_stubgen: StubGenerator):
        from .module_stub_generator import ModuleStubGenerator
        from .class_stub_generator import ClassStubGenerator

        assert attr_name.isidentifier()
        assert isinstance(parent_stubgen, (ModuleStubGenerator, ClassStubGenerator))

        super().__init__(manager)

        self.attr = attr
        self.attr_name = attr_name
        self.attr_path = parent_stubgen.path() + (attr_name,)
        self.attr_qualname = '.'.join(self.attr_path)

        self.parent_stubgen = weakref.ref(parent_stubgen)

    def name(self) -> str:
        return self.attr_name

    def path(self) -> Tuple[str, ...]:
        return self.attr_path

    def qualname(self) -> str:
        return self.attr_qualname

    def run(self):
        from .class_stub_generator import ClassStubGenerator
        from .module_stub_generator import ModuleStubGenerator

        parent_stubgen = self.parent_stubgen()
        parent_type_manager = parent_stubgen.get_type_manager()
        indent = self.manager().indent

        attr_type = type(self.attr)
        attr_typepath = tuple(attr_type.__module__.split('.')) + tuple(attr_type.__qualname__.split('.'))

        parent_type_manager.import_(attr_typepath)
        if isinstance(parent_stubgen, ClassStubGenerator):
            parent_type_manager.import_(('typing', 'ClassVar'))
            parent_stubgen.push_line(indent, '{}: ClassVar[{}]'.format(self.attr_name, parent_type_manager.repr_of(attr_typepath)))
        elif isinstance(parent_stubgen, ModuleStubGenerator):
            parent_stubgen.push_line(0, '{}: {}'.format(self.attr_name, parent_type_manager.repr_of(attr_typepath)))
        else:
            parent_stubgen.push_line(indent, '{}: {}'.format(self.attr_name, parent_type_manager.repr_of(attr_typepath)))
