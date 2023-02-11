from .Init import Init
from .TypedInit import TypedInit

class VarListElementInit(TypedInit):

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(T: TypedInit, E: int) -> VarListElementInit:
        pass

    def getElementNum(self) -> int:
        pass

    def getVariable(self) -> TypedInit:
        pass
