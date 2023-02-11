from typing import BinaryIO, List, Tuple
from .SMLoc import SMLoc
from .SourceMgr import SourceMgr

class SMDiagnostic:

    def getFilename(self) -> str:
        pass

    def getKind(self) -> SourceMgr.DiagKind:
        pass

    def getLineContents(self) -> str:
        pass

    def getLineNo(self) -> int:
        pass

    def getLoc(self) -> SMLoc:
        pass

    def getMessage(self) -> str:
        pass

    def getRanges(self) -> List[Tuple[int, int]]:
        pass

    def getSourceMgr(self) -> SourceMgr:
        pass

    def print(self, ProgName: str, S: BinaryIO, ShowColors: bool = True, ShowKindLabel: bool = True) -> None:
        pass
