from .Init import Init
from .Record import Record
from .StringInit import StringInit
from .TypedInit import TypedInit

class FieldInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(R: Init, FN: StringInit) -> FieldInit:
        pass

    def Fold(self, CurRec: Record) -> Init:
        pass

    def getFieldName(self) -> StringInit:
        pass

    def getRecord(self) -> Init:
        pass
