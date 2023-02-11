from .Init import Init
from .RecTy import RecTy
from .Record import Record
from .TypedInit import TypedInit

class FoldOpInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(Start: Init, List: Init, A: Init, B: Init, Expr: Init, Type: RecTy) -> FoldOpInit:
        pass

    def Fold(self, CurRec: Record) -> Init:
        pass
