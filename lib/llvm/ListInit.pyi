from typing import Iterator, List
from .Init import Init
from .RecTy import RecTy
from .Record import Record
from .TypedInit import TypedInit

class ListInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    def __iter__(self) -> Iterator:
        pass

    def empty(self) -> bool:
        pass

    def getElement(self, i: int) -> Init:
        pass

    def getElementAsRecord(self, i: int) -> Record:
        pass

    def getElementType(self) -> RecTy:
        pass

    def getValues(self) -> List[Init]:
        pass

    def size(self) -> int:
        pass
