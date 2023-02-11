from typing import Any, ClassVar
from .Init import Init
from .OpInit import OpInit
from .RecTy import RecTy
from .Record import Record

class TernOpInit(OpInit):

    class TernaryOp:

        DAG: ClassVar[TernOpInit.TernaryOp]
        FILTER: ClassVar[TernOpInit.TernaryOp]
        FIND: ClassVar[TernOpInit.TernaryOp]
        FOREACH: ClassVar[TernOpInit.TernaryOp]
        IF: ClassVar[TernOpInit.TernaryOp]
        SUBST: ClassVar[TernOpInit.TernaryOp]
        SUBSTR: ClassVar[TernOpInit.TernaryOp]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: TernOpInit.TernaryOp) -> int:
            pass

        def __eq__(self, other: object) -> bool:
            pass

        def __getstate__(self) -> int:
            pass

        def __hash__(self) -> int:
            pass

        def __index__(self) -> int:
            pass

        def __init__(self, value: int) -> None:
            pass

        def __int__(self) -> int:
            pass

        def __ne__(self, other: object) -> bool:
            pass

        def __repr__(self) -> str:
            pass

        def __setstate__(self, state: int) -> None:
            pass

        def name(self) -> str:
            pass

    @staticmethod
    def classof(I: Init) -> bool:
        pass

    @staticmethod
    def get(opc: TernOpInit.TernaryOp, lhs: Init, mhs: Init, rhs: Init, Type: RecTy) -> TernOpInit:
        pass

    def Fold(self, CurRec: Record) -> Init:
        pass

    def getLHS(self) -> Init:
        pass

    def getMHS(self) -> Init:
        pass

    def getOpcode(self) -> TernOpInit.TernaryOp:
        pass

    def getRHS(self) -> Init:
        pass
