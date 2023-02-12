from .MCFixupKind import MCFixupKind
from .SMLoc import SMLoc

class MCFixup:

    @staticmethod
    def getKindForSize(Size: int, IsPCRel: bool) -> MCFixupKind:
        pass

    @staticmethod
    def getKindForSizeInBits(Size: int, IsPCRel: bool) -> MCFixupKind:
        pass

    def getKind(self) -> MCFixupKind:
        pass

    def getLoc(self) -> SMLoc:
        pass

    def getOffset(self) -> int:
        pass

    def getTargetKind(self) -> int:
        pass

    def setOffset(self, Value: int) -> None:
        pass
