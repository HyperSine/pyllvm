from .Init import Init
from .RecTy import RecTy
from .RecordKeeper import RecordKeeper

class RecordVal:

    def getName(self) -> str:
        pass

    def getNameInit(self) -> Init:
        pass

    def getNameInitAsString(self) -> str:
        pass

    def getRecordKeeper(self) -> RecordKeeper:
        pass

    def getType(self) -> RecTy:
        pass

    def getValue(self) -> Init:
        pass

    def isNonconcreteOK(self) -> bool:
        pass

    def isTemplateArg(self) -> bool:
        pass

    def isUsed(self) -> bool:
        pass

    def setUsed(self, arg0: bool) -> None:
        pass
