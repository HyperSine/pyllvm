from typing import Any, ClassVar, overload
from .Init import Init
from .RecordKeeper import RecordKeeper
from .TypedInit import TypedInit

class StringInit(TypedInit):

    class StringFormat:

        Code: ClassVar[StringInit.StringFormat]
        String: ClassVar[StringInit.StringFormat]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: StringInit.StringFormat) -> int:
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
    def determineFormat(Fmt1: StringInit.StringFormat, Fmt2: StringInit.StringFormat) -> StringInit.StringFormat:
        pass

    @overload
    @staticmethod
    def get(RK: RecordKeeper, V: str) -> None:
        pass

    @overload
    @staticmethod
    def get(RK: RecordKeeper, V: str, Fmt: StringInit.StringFormat) -> None:
        pass

    def getFormat(self) -> StringInit.StringFormat:
        pass

    def getValue(self) -> str:
        pass

    def hasCodeFormat(self) -> bool:
        pass
