from .Init import Init
from .RecordKeeper import RecordKeeper
from .StringInit import StringInit
from .TypedInit import TypedInit

class AnonymousNameInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(RK: RecordKeeper, unused: int) -> AnonymousNameInit:
        pass

    def getAsString(self) -> str:
        pass

    def getNameInit(self) -> StringInit:
        pass

    def getValue(self) -> int:
        pass
