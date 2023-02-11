#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, Tuple

from .stub_generator import StubGenerator

if TYPE_CHECKING:
    from .. generator_manager import GeneratorManager

class ClassMethodStubGenerator(StubGenerator):

    def __init__(self, manager: GeneratorManager, method: classmethod, method_name: str, parent_stubgen: StubGenerator):
        super().__init__(manager)
        raise NotImplementedError('todo')

    def name(self) -> str:
        raise NotImplementedError('todo')

    def path(self) -> Tuple[str, ...]:
        raise NotImplementedError('todo')

    def qualname(self) -> str:
        raise NotImplementedError('todo')

    def run(self):
        raise NotImplementedError('todo')
