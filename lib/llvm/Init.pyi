from typing import List
from .RecTy import RecTy
from .RecordKeeper import RecordKeeper

class Init:

    def __str__(self) -> str:
        pass

    def convertInitListSlice(self, Elements: List[int]) -> Init:
        pass

    def convertInitializerBitRange(self, Bits: List[int]) -> Init:
        pass

    def convertInitializerTo(self, Ty: RecTy) -> Init:
        pass

    def getAsString(self) -> str:
        pass

    def getAsUnquotedString(self) -> str:
        pass

    def getBit(self, Bit: int) -> Init:
        pass

    def getCastTo(self, Ty: RecTy) -> Init:
        pass

    def getRecordKeeper(self) -> RecordKeeper:
        pass

    def isComplete(self) -> bool:
        pass

    def isConcrete(self) -> bool:
        pass
