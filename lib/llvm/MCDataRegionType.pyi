from typing import Any, ClassVar

class MCDataRegionType:

    DataRegion: ClassVar[MCDataRegionType]
    DataRegionEnd: ClassVar[MCDataRegionType]
    DataRegionJT16: ClassVar[MCDataRegionType]
    DataRegionJT32: ClassVar[MCDataRegionType]
    DataRegionJT8: ClassVar[MCDataRegionType]

    @property
    def name(self) -> str:
        pass

    @property
    def value(arg0: MCDataRegionType) -> int:
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
