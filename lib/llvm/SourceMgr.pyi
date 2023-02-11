from typing import Any, BinaryIO, Callable, ClassVar, List, Optional, Tuple
from .MemoryBuffer import MemoryBuffer
from .SMDiagnostic import SMDiagnostic
from .SMLoc import SMLoc
from ..CxxWrapper import CxxWrapper

class SourceMgr:

    class DiagKind:

        Error: ClassVar[SourceMgr.DiagKind]
        Note: ClassVar[SourceMgr.DiagKind]
        Remark: ClassVar[SourceMgr.DiagKind]
        Warning: ClassVar[SourceMgr.DiagKind]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: SourceMgr.DiagKind) -> int:
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

    def AddNewSourceBuffer(self, F: CxxWrapper[MemoryBuffer], IncludeLoc: SMLoc) -> int:
        pass

    def FindBufferContainingLoc(self, Loc: SMLoc) -> int:
        pass

    def FindLineNumber(self, Loc: SMLoc, BufferID: int = 0) -> int:
        pass

    def FindLocForLineAndColumn(self, BufferID: int, LineNo: int, ColNo: int) -> SMLoc:
        pass

    def PrintIncludeStack(self, IncludeLoc: SMLoc, OS: BinaryIO) -> None:
        pass

    def __init__(self) -> None:
        pass

    def getDiagContext(self) -> Any:
        pass

    def getDiagHandler(self) -> Callable[[SMDiagnostic, Any], None]:
        pass

    def getFormattedLocationNoOffset(self, Loc: SMLoc, IncludePath: bool = False) -> str:
        pass

    def getIncludeDirs(self) -> List[str]:
        pass

    def getLineAndColumn(self, Loc: SMLoc, BufferID: int = 0) -> Tuple[int, int]:
        pass

    def getMainFileID(self) -> int:
        pass

    def getNumBuffers(self) -> int:
        pass

    def getParentIncludeLoc(self, i: int) -> SMLoc:
        pass

    def setDiagHandler(self, DH: Callable[[SMDiagnostic, Any], None], Ctx: Any) -> None:
        pass

    def setIncludeDirs(self, Dirs: List[str]) -> None:
        pass

    def takeSourceBuffersFrom(self, SrcMgr: SourceMgr, MainBufferIncludeLoc: Optional[SMLoc] = None) -> None:
        pass
