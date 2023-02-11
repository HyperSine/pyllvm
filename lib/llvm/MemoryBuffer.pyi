from typing import Any, ByteString, ClassVar, Optional
from ..CxxWrapper import CxxWrapper

class MemoryBuffer:

    class BufferKind:

        MMap: ClassVar[MemoryBuffer.BufferKind]
        Malloc: ClassVar[MemoryBuffer.BufferKind]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: MemoryBuffer.BufferKind) -> int:
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
    def getFile(Filename: str, IsText: bool = False, RequiresNullTerminator: bool = True, IsVolatile: bool = False) -> CxxWrapper[MemoryBuffer]:
        pass

    @staticmethod
    def getFileAsStream(Filename: str) -> CxxWrapper[MemoryBuffer]:
        pass

    @staticmethod
    def getFileOrSTDIN(Filename: str, IsText: bool = False, RequiresNullTerminator: bool = True) -> CxxWrapper[MemoryBuffer]:
        pass

    @staticmethod
    def getFileSlice(Filename: str, MapSize: int, Offset: int, IsVolatile: bool = False) -> CxxWrapper[MemoryBuffer]:
        pass

    @staticmethod
    def getMemBufferCopy(InputData: ByteString, BufferName: str = '') -> CxxWrapper[MemoryBuffer]:
        pass

    @staticmethod
    def getSTDIN() -> CxxWrapper[MemoryBuffer]:
        pass

    def dontNeedIfMmap(self) -> None:
        pass

    def getBuffer(self) -> memoryview:
        pass

    def getBufferEnd(self) -> Optional[Any]:
        pass

    def getBufferIdentifier(self) -> str:
        pass

    def getBufferKind(self) -> MemoryBuffer.BufferKind:
        pass

    def getBufferSize(self) -> int:
        pass

    def getBufferStart(self) -> Optional[Any]:
        pass
