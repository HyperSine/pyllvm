from typing import List
from .Init import Init
from .RecTy import RecTy
from .Record import Record
from .TypedInit import TypedInit

class CondOpInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(C: List[Init], V: List[Init], Type: RecTy) -> CondOpInit:
        pass

    def Fold(self, CurRec: Record) -> Init:
        pass

    def getCond(self, Num: int) -> Init:
        pass

    def getConds(self) -> List[Init]:
        pass

    def getNumConds(self) -> int:
        pass

    def getVal(self, Num: int) -> Init:
        pass

    def getValType(self) -> RecTy:
        pass

    def getVals(self) -> List[Init]:
        pass
