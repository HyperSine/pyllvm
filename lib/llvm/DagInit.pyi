from typing import List, Tuple, overload
from .Init import Init
from .StringInit import StringInit
from .TypedInit import TypedInit

class DagInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @overload
    @staticmethod
    def get(V: Init, VN: StringInit, ArgRange: List[Init], NameRange: List[StringInit]) -> DagInit:
        pass

    @overload
    @staticmethod
    def get(V: Init, VN: StringInit, Args: List[Tuple[Init, StringInit]]) -> DagInit:
        pass

    def arg_empty(self) -> bool:
        pass

    def arg_size(self) -> int:
        pass

    def getArg(self, Num: int) -> Init:
        pass

    def getArgName(self, Num: int) -> StringInit:
        pass

    def getArgNameStr(self, Num: int) -> str:
        pass

    def getArgNames(self) -> List[StringInit]:
        pass

    def getArgs(self) -> List[Init]:
        pass

    def getName(self) -> StringInit:
        pass

    def getNameStr(self) -> str:
        pass

    def getNumArgs(self) -> int:
        pass

    def getOperator(self) -> Init:
        pass

    def name_empty(self) -> bool:
        pass

    def name_size(self) -> int:
        pass
