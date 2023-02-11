from typing import Any, ClassVar

class ExceptionHandling:

    AIX: ClassVar[ExceptionHandling]
    ARM: ClassVar[ExceptionHandling]
    DwarfCFI: ClassVar[ExceptionHandling]
    Null: ClassVar[ExceptionHandling]
    SjLj: ClassVar[ExceptionHandling]
    Wasm: ClassVar[ExceptionHandling]
    WinEH: ClassVar[ExceptionHandling]

    @property
    def name(self) -> str:
        pass

    @property
    def value(arg0: ExceptionHandling) -> int:
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
