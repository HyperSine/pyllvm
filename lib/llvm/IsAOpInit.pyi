from .Init import Init
from .RecTy import RecTy
from .TypedInit import TypedInit

class IsAOpInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(CheckType: RecTy, Expr: Init) -> IsAOpInit:
        pass

    def Fold(self) -> Init:
        pass
