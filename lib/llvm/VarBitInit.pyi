from .Init import Init
from .TypedInit import TypedInit

class VarBitInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(T: TypedInit, B: int) -> VarBitInit:
        pass

    def getBitNum(self) -> int:
        pass

    def getBitVar(self) -> Init:
        pass
