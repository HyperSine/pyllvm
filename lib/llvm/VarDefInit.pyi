from typing import List
from .Init import Init
from .Record import Record
from .TypedInit import TypedInit

class VarDefInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(Class: Record, Args: List[Init]) -> VarDefInit:
        pass

    def Fold(self) -> Init:
        pass

    def args(self) -> List[Init]:
        pass

    def args_empty(self) -> bool:
        pass

    def args_size(self) -> int:
        pass

    def getArg(self, i: int) -> Init:
        pass
