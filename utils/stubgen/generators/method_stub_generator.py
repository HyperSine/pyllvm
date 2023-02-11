#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, Tuple

import weakref
import re

from .stub_generator import StubGenerator
from ..pybind11_funcsig import Pybind11FunctionSignature

if TYPE_CHECKING:
    from ..generator_manager import GeneratorManager

class MethodStubGenerator(StubGenerator):

    def __init__(self, manager: GeneratorManager, method, method_name: str, parent_stubgen: StubGenerator):
        from .class_stub_generator import ClassStubGenerator

        assert method_name.isidentifier()
        assert isinstance(parent_stubgen, ClassStubGenerator)

        super().__init__(manager)

        self.method = method
        self.method_name = method_name
        self.method_path = parent_stubgen.path() + (method_name,)
        self.method_qualname = '.'.join(self.method_path)

        self.parent_stubgen = weakref.ref(parent_stubgen)

    def name(self) -> str:
        return self.method_name

    def path(self) -> Tuple[str, ...]:
        return self.method_path

    def qualname(self) -> str:
        return self.method_qualname

    def run(self):
        parent_stubgen = self.parent_stubgen()
        parent_type_manager = parent_stubgen.get_type_manager()
        indent = self.manager().indent

        doclines = self.method.__doc__.splitlines()
        if len(doclines) == 1:
            if self.method_name == '__init__' and doclines[0] == 'Initialize self.  See help(type(self)) for accurate signature.':
                return

            sig = Pybind11FunctionSignature(doclines[0])
            assert sig.func_argname(0) == 'self'

            for typepath in sig.referred_typepaths():
                parent_type_manager.import_(typepath)

            parent_stubgen.push_line(indent, sig.make_defstring(parent_type_manager))
            parent_stubgen.push_line(indent, '    pass')
            parent_stubgen.push_line(indent, '')
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
                assert sig.func_argname(0) == 'self'

                for typepath in sig.referred_typepaths():
                    parent_type_manager.import_(typepath)

                parent_stubgen.push_line(indent, '@overload')
                parent_stubgen.push_line(indent, sig.make_defstring(parent_type_manager))
                parent_stubgen.push_line(indent, '    pass')
                parent_stubgen.push_line(indent, '')
