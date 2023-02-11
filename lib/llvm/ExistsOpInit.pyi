from .Init import Init
from .RecTy import RecTy
from .Record import Record
from .TypedInit import TypedInit

class ExistsOpInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(CheckType: RecTy, Expr: Init) -> ExistsOpInit:
        pass

    def Fold(self, CurRec: Record, IsFinal: bool = False) -> Init:
        pass
