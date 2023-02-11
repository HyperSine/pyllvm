from .RecTy import RecTy
from .RecordKeeper import RecordKeeper

class DagRecTy(RecTy):

    @staticmethod
    def classof(RT: RecTy) -> bool:
        pass

    @staticmethod
    def get(RK: RecordKeeper) -> DagRecTy:
        pass
