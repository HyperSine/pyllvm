from typing import Any, ClassVar
from .Init import Init
from .OpInit import OpInit
from .RecTy import RecTy
from .Record import Record
from .TypedInit import TypedInit

class BinOpInit(OpInit):

    class BinaryOp:

        ADD: ClassVar[BinOpInit.BinaryOp]
        AND: ClassVar[BinOpInit.BinaryOp]
        CONCAT: ClassVar[BinOpInit.BinaryOp]
        EQ: ClassVar[BinOpInit.BinaryOp]
        GE: ClassVar[BinOpInit.BinaryOp]
        GT: ClassVar[BinOpInit.BinaryOp]
        INTERLEAVE: ClassVar[BinOpInit.BinaryOp]
        LE: ClassVar[BinOpInit.BinaryOp]
        LISTCONCAT: ClassVar[BinOpInit.BinaryOp]
        LISTSPLAT: ClassVar[BinOpInit.BinaryOp]
        LT: ClassVar[BinOpInit.BinaryOp]
        MUL: ClassVar[BinOpInit.BinaryOp]
        NE: ClassVar[BinOpInit.BinaryOp]
        OR: ClassVar[BinOpInit.BinaryOp]
        SETDAGOP: ClassVar[BinOpInit.BinaryOp]
        SHL: ClassVar[BinOpInit.BinaryOp]
        SRA: ClassVar[BinOpInit.BinaryOp]
        SRL: ClassVar[BinOpInit.BinaryOp]
        STRCONCAT: ClassVar[BinOpInit.BinaryOp]
        SUB: ClassVar[BinOpInit.BinaryOp]
        XOR: ClassVar[BinOpInit.BinaryOp]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: BinOpInit.BinaryOp) -> int:
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
    def get(opc: BinOpInit.BinaryOp, lhs: Init, rhs: Init, Type: RecTy) -> BinOpInit:
        pass

    @staticmethod
    def getListConcat(lhs: TypedInit, rhs: Init) -> Init:
        pass

    @staticmethod
    def getStrConcat(lhs: Init, rhs: Init) -> Init:
        pass

    def Fold(self, CurRec: Record) -> Init:
        pass

    def getLHS(self) -> Init:
        pass

    def getOpcode(self) -> BinOpInit.BinaryOp:
        pass

    def getRHS(self) -> Init:
        pass
