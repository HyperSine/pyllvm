from typing import Any, ClassVar

class MCFixupKind:

    DTPRel_4: ClassVar[MCFixupKind]
    DTPRel_8: ClassVar[MCFixupKind]
    Data_1: ClassVar[MCFixupKind]
    Data_2: ClassVar[MCFixupKind]
    Data_4: ClassVar[MCFixupKind]
    Data_6b: ClassVar[MCFixupKind]
    Data_8: ClassVar[MCFixupKind]
    FirstLiteralRelocationKind: ClassVar[MCFixupKind]
    FirstTargetFixupKind: ClassVar[MCFixupKind]
    GPRel_1: ClassVar[MCFixupKind]
    GPRel_2: ClassVar[MCFixupKind]
    GPRel_4: ClassVar[MCFixupKind]
    GPRel_8: ClassVar[MCFixupKind]
    MaxFixupKind: ClassVar[MCFixupKind]
    NONE: ClassVar[MCFixupKind]
    PCRel_1: ClassVar[MCFixupKind]
    PCRel_2: ClassVar[MCFixupKind]
    PCRel_4: ClassVar[MCFixupKind]
    PCRel_8: ClassVar[MCFixupKind]
    SecRel_1: ClassVar[MCFixupKind]
    SecRel_2: ClassVar[MCFixupKind]
    SecRel_4: ClassVar[MCFixupKind]
    SecRel_8: ClassVar[MCFixupKind]
    TPRel_4: ClassVar[MCFixupKind]
    TPRel_8: ClassVar[MCFixupKind]

    @property
    def name(self) -> str:
        pass

    @property
    def value(arg0: MCFixupKind) -> int:
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
