from typing import Any, ClassVar

class MCVersionMinType:

    IOSVersionMin: ClassVar[MCVersionMinType]
    OSXVersionMin: ClassVar[MCVersionMinType]
    TvOSVersionMin: ClassVar[MCVersionMinType]
    WatchOSVersionMin: ClassVar[MCVersionMinType]

    @property
    def name(self) -> str:
        pass

    @property
    def value(arg0: MCVersionMinType) -> int:
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
