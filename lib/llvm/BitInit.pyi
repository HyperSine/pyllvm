from .Init import Init
from .RecordKeeper import RecordKeeper
from .TypedInit import TypedInit

class BitInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(RK: RecordKeeper, V: bool) -> BitInit:
        pass

    def getValue(self) -> bool:
        pass
