#!/usr/bin/env python3
from __future__ import annotations
from typing import TYPE_CHECKING, Tuple

import abc
import weakref

if TYPE_CHECKING:
    from ..generator_manager import GeneratorManager

class StubGenerator(abc.ABC):

    def __init__(self, manager: GeneratorManager):
        self.manager = weakref.ref(manager)

    @abc.abstractmethod
    def name(self) -> str:
        pass

    @abc.abstractmethod
    def path(self) -> Tuple[str, ...]:
        pass

    @abc.abstractmethod
    def qualname(self) -> str:
        pass

    @abc.abstractmethod
    def run(self):
        pass
