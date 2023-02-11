from .RecTy import RecTy
from .RecordKeeper import RecordKeeper

class BitRecTy(RecTy):

    @staticmethod
    def classof(RT: RecTy) -> bool:
        pass

    @staticmethod
    def get(RK: RecordKeeper) -> BitRecTy:
        pass
