from .Init import Init
from .RecTy import RecTy
from .RecordKeeper import RecordKeeper

class TypedInit(Init):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    def getRecordKeeper(self) -> RecordKeeper:
        pass

    def getType(self) -> RecTy:
        pass
