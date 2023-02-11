from typing import List, overload
from .Init import Init
from .Record import Record

class RecordKeeper:

    def __init__(self) -> None:
        pass

    @overload
    def getAllDerivedDefinitions(self, ClassName: str) -> List[Record]:
        pass

    @overload
    def getAllDerivedDefinitions(self, ClassNames: List[str]) -> List[Record]:
        pass

    def getClass(self, Name: str) -> Record:
        pass

    def getDef(self, Name: str) -> Record:
        pass

    def getGlobal(self, Name: str) -> Init:
        pass

    def getInputFilename(self) -> str:
        pass

    def getNewAnonymousName(self) -> Init:
        pass

    def saveInputFilename(self, Filename: str) -> None:
        pass

    def startBackendTimer(self, Name: str) -> None:
        pass

    def startPhaseTiming(self) -> None:
        pass

    def startTimer(self, Name: str) -> None:
        pass

    def stopBackendTimer(self) -> None:
        pass

    def stopPhaseTiming(self) -> None:
        pass

    def stopTimer(self) -> None:
        pass
