from typing import overload
from .Init import Init
from .RecTy import RecTy
from .TypedInit import TypedInit

class VarInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @overload
    @staticmethod
    def get(VN: str, T: RecTy) -> VarInit:
        pass

    @overload
    @staticmethod
    def get(VN: Init, T: RecTy) -> VarInit:
        pass

    def getName(self) -> str:
        pass

    def getNameInit(self) -> Init:
        pass

    def getNameInitAsString(self) -> str:
        pass
