from typing import BinaryIO, Optional
from .MCAssemblerFlag import MCAssemblerFlag
from .MCFixupKind import MCFixupKind
from .MCInst import MCInst
from .MCSubtargetInfo import MCSubtargetInfo
from ..CxxWrapper import CxxWrapper

class MCAsmBackend:

    def allowAutoPadding(self) -> bool:
        pass

    def allowEnhancedRelaxation(self) -> bool:
        pass

    def createObjectTargetWriter(self) -> CxxWrapper:
        pass

    def getFixupKind(self, Name: str) -> Optional[MCFixupKind]:
        pass

    def getMaximumNopSize(self, STI: MCSubtargetInfo) -> int:
        pass

    def getMinimumNopSize(self) -> int:
        pass

    def getNumFixupKinds(self) -> int:
        pass

    def handleAssemblerFlag(self, arg0: MCAssemblerFlag) -> None:
        pass

    def mayNeedRelaxation(self, arg0: MCInst, arg1: MCSubtargetInfo) -> bool:
        pass

    def relaxInstruction(self, arg0: MCInst, arg1: MCSubtargetInfo) -> None:
        pass

    def reset(self) -> None:
        pass

    def writeNopData(self, OS: BinaryIO, Count: int, STI: Optional[MCSubtargetInfo]) -> bool:
        pass
