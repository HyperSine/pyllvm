from typing import List
from .Init import Init
from .TypedInit import TypedInit

class OpInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    def clone(self, Operands: List[Init]) -> OpInit:
        pass

    def getNumOperands(self) -> int:
        pass

    def getOperand(self, i: int) -> Init:
        pass
