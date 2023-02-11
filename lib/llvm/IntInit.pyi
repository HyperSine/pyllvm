from .Init import Init
from .RecordKeeper import RecordKeeper
from .TypedInit import TypedInit

class IntInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(RK: RecordKeeper, V: int) -> IntInit:
        pass

    def getValue(self) -> int:
        pass
