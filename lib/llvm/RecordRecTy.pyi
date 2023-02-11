from typing import List
from .RecTy import RecTy
from .Record import Record

class RecordRecTy(RecTy):

    @staticmethod
    def classof(RT: RecTy) -> bool:
        pass

    def getClasses(self) -> List[Record]:
        pass

    def isSubClassOf(self, Class: Record) -> bool:
        pass
