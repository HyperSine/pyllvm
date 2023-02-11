from .RecTy import RecTy
from .RecordKeeper import RecordKeeper

class StringRecTy(RecTy):

    @staticmethod
    def classof(RT: RecTy) -> bool:
        pass

    @staticmethod
    def get(RK: RecordKeeper) -> StringRecTy:
        pass
