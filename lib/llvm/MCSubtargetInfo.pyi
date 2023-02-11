from typing import Optional, overload
from .Triple import Triple

class MCSubtargetInfo:

    def checkFeatures(self, FS: str) -> bool:
        pass

    def enableWritePrefetching(self) -> bool:
        pass

    def getCPU(self) -> str:
        pass

    def getCacheAssociativity(self, Level: int) -> Optional[int]:
        pass

    @overload
    def getCacheLineSize(self) -> int:
        pass

    @overload
    def getCacheLineSize(self, Level: int) -> Optional[int]:
        pass

    def getCacheSize(self, Level: int) -> Optional[int]:
        pass

    def getFeatureString(self) -> str:
        pass

    def getHwMode(self) -> int:
        pass

    def getMaxPrefetchIterationsAhead(self) -> int:
        pass

    def getMinPrefetchStride(self, NumMemAccesses: int, NumStridedMemAccesses: int, NumPrefetches: int, HasCall: bool) -> int:
        pass

    def getPrefetchDistance(self) -> int:
        pass

    def getTargetTriple(self) -> Triple:
        pass

    def getTuneCPU(self) -> str:
        pass

    def hasFeature(self, Feature: int) -> bool:
        pass

    def isCPUStringValid(self, CPU: str) -> bool:
        pass

    def setDefaultFeatures(self, CPU: str, TuneCPU: str, FS: str) -> None:
        pass
