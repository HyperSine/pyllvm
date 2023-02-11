from typing import Iterator, overload
from .Target import Target
from .Triple import Triple

class TargetRegistry:

    @overload
    @staticmethod
    def lookupTarget(Triple: str) -> Target:
        pass

    @overload
    @staticmethod
    def lookupTarget(ArchName: str, TheTriple: Triple) -> Target:
        pass

    @staticmethod
    def targets() -> Iterator:
        pass
