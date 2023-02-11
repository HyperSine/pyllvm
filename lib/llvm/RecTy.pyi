from typing import Any, ClassVar
from .RecordKeeper import RecordKeeper

class RecTy:

    class RecTyKind:

        Bit: ClassVar[RecTy.RecTyKind]
        Bits: ClassVar[RecTy.RecTyKind]
        Dag: ClassVar[RecTy.RecTyKind]
        Int: ClassVar[RecTy.RecTyKind]
        List: ClassVar[RecTy.RecTyKind]
        Record: ClassVar[RecTy.RecTyKind]
        String: ClassVar[RecTy.RecTyKind]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: RecTy.RecTyKind) -> int:
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

    def __str__(self) -> str:
        pass

    def getRecTyKind(self) -> RecTy.RecTyKind:
        pass

    def getRecordKeeper(self) -> RecordKeeper:
        pass

    def typeIsA(self, RHS: RecTy) -> bool:
        pass

    def typeIsConvertibleTo(self, RHS: RecTy) -> bool:
        pass
