from .RecTy import RecTy
from .RecordKeeper import RecordKeeper

class BitsRecTy(RecTy):

    @staticmethod
    def classof(RT: RecTy) -> bool:
        pass

    @staticmethod
    def get(RK: RecordKeeper, Sz: int) -> BitsRecTy:
        pass

    def getNumBits(self) -> int:
        pass
