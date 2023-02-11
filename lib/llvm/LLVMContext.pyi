from typing import Optional

class LLVMContext:

    def __init__(self) -> None:
        pass

    def disableDebugTypeODRUniquing(self) -> None:
        pass

    def enableDebugTypeODRUniquing(self) -> None:
        pass

    def getDiagnosticsHotnessRequested(self) -> bool:
        pass

    def getDiagnosticsHotnessThreshold(self) -> int:
        pass

    def getDiagnosticsMisExpectTolerance(self) -> int:
        pass

    def getMDKindID(self, Name: str) -> int:
        pass

    def getMisExpectWarningRequested(self) -> bool:
        pass

    def getOperandBundleTagID(self, Tag: str) -> int:
        pass

    def hasSetOpaquePointersValue(self) -> bool:
        pass

    def isDiagnosticsHotnessThresholdSetFromPSI(self) -> bool:
        pass

    def isODRUniquingDebugTypes(self) -> bool:
        pass

    def setDiagnosticsHotnessRequested(self, Requested: bool) -> None:
        pass

    def setDiagnosticsHotnessThreshold(self, Threshold: Optional[int]) -> None:
        pass

    def setDiagnosticsMisExpectTolerance(self, Tolerance: Optional[int]) -> None:
        pass

    def setDiscardValueNames(self, Discard: bool) -> None:
        pass

    def setMisExpectWarningRequested(self, Requested: bool) -> None:
        pass

    def setOpaquePointers(self, Enable: bool) -> None:
        pass

    def shouldDiscardValueNames(self) -> bool:
        pass

    def supportsTypedPointers(self) -> bool:
        pass

    def yield(self) -> None:
        pass
