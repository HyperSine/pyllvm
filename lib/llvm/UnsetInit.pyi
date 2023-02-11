from .Init import Init
from .RecordKeeper import RecordKeeper

class UnsetInit(Init):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(RK: RecordKeeper) -> UnsetInit:
        pass

    def getRecordKeeper(self) -> RecordKeeper:
        pass
