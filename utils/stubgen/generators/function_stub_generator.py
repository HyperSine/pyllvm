#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, Tuple

import weakref
import re

from .stub_generator import StubGenerator
from ..pybind11_funcsig import Pybind11FunctionSignature

if TYPE_CHECKING:
    from ..generator_manager import GeneratorManager

class FunctionStubGenerator(StubGenerator):

    def __init__(self, manager: GeneratorManager, func, func_name: str, parent_stubgen: StubGenerator):
        from .module_stub_generator import ModuleStubGenerator

        assert func_name.isidentifier()
        assert isinstance(parent_stubgen, ModuleStubGenerator)

        super().__init__(manager)

        self.func = func
        self.func_name = func_name
        self.func_path = parent_stubgen.path() + (func_name,)
        self.func_qualname = '.'.join(self.func_path)

        self.parent_stubgen = weakref.ref(parent_stubgen)

    def name(self) -> str:
        return self.func_name

    def path(self) -> Tuple[str, ...]:
        return self.func_path

    def qualname(self) -> str:
        return self.func_qualname

    def run(self):
        parent_stubgen = self.parent_stubgen()
        parent_type_manager = parent_stubgen.get_type_manager()

        doclines = self.func.__doc__.splitlines()
        if len(doclines) == 1:
            sig = Pybind11FunctionSignature(doclines[0])

            for typepath in sig.referred_typepaths():
                parent_type_manager.import_(typepath)

            parent_stubgen.push_line(0, sig.make_defstring(parent_type_manager))
            parent_stubgen.push_line(0, '    pass')
            parent_stubgen.push_line(0, '')
        else:
            assert doclines[1] == 'Overloaded function.'

            sigs = []
            for line in doclines[2:]:
                match = re.fullmatch(r'\d+\. (.*)', line)
                if match is not None:
                    sigs.append(Pybind11FunctionSignature(match[1]))

            assert len(sigs) > 1

            parent_type_manager.import_(('typing', 'overload'))
            for sig in sigs:
                for typepath in sig.referred_typepaths():
                    parent_type_manager.import_(typepath)

                parent_stubgen.push_line(0, '@overload')
                parent_stubgen.push_line(0, sig.make_defstring(parent_type_manager))
                parent_stubgen.push_line(0, '    pass')
                parent_stubgen.push_line(0, '')
