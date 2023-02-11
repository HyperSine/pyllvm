from .Init import Init
from .Record import Record
from .TypedInit import TypedInit

class DefInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(arg0: Record) -> DefInit:
        pass

    def getDef(self) -> Record:
        pass
