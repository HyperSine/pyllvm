from .Init import Init
from .TypedInit import TypedInit

class BitsInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    def allInComplete(self) -> bool:
        pass

    def getNumBits(self) -> int:
        pass
