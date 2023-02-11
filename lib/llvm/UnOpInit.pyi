from typing import Any, ClassVar
from .Init import Init
from .OpInit import OpInit
from .RecTy import RecTy
from .Record import Record

class UnOpInit(OpInit):

    class UnaryOp:

        CAST: ClassVar[UnOpInit.UnaryOp]
        EMPTY: ClassVar[UnOpInit.UnaryOp]
        GETDAGOP: ClassVar[UnOpInit.UnaryOp]
        HEAD: ClassVar[UnOpInit.UnaryOp]
        NOT: ClassVar[UnOpInit.UnaryOp]
        SIZE: ClassVar[UnOpInit.UnaryOp]
        TAIL: ClassVar[UnOpInit.UnaryOp]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: UnOpInit.UnaryOp) -> int:
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
    def get(opc: UnOpInit.UnaryOp, lhs: Init, Type: RecTy) -> UnOpInit:
        pass

    def Fold(self, CurRec: Record, IsFinal: bool = False) -> Init:
        pass

    def getOpcode(self) -> UnOpInit.UnaryOp:
        pass

    def getOperand(self) -> UnOpInit.UnaryOp:
        pass
