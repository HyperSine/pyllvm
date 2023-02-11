from .MCSection import MCSection

class MCSymbol:

    def declareCommon(self, Size: int, Align: int, Target: bool = False) -> bool:
        pass

    def getCommonAlignment(self) -> int:
        pass

    def getCommonSize(self) -> int:
        pass

    def getIndex(self) -> int:
        pass

    def getName(self) -> str:
        pass

    def getOffset(self) -> int:
        pass

    def getSection(self) -> MCSection:
        pass

    def isAbsolute(self) -> bool:
        pass

    def isCOFF(self) -> bool:
        pass

    def isCommon(self) -> bool:
        pass

    def isDefined(self) -> bool:
        pass

    def isELF(self) -> bool:
        pass

    def isExternal(self) -> bool:
        pass

    def isGOFF(self) -> bool:
        pass

    def isInSection(self) -> bool:
        pass

    def isMachO(self) -> bool:
        pass

    def isPrivateExtern(self) -> bool:
        pass

    def isRedefinable(self) -> bool:
        pass

    def isRegistered(self) -> bool:
        pass

    def isTargetCommon(self) -> bool:
        pass

    def isTemporary(self) -> bool:
        pass

    def isUndefined(self, arg0: bool) -> bool:
        pass

    def isUnset(self) -> bool:
        pass

    def isUsed(self) -> bool:
        pass

    def isUsedInReloc(self) -> bool:
        pass

    def isVariable(self) -> bool:
        pass

    def isWasm(self) -> bool:
        pass

    def isXCOFF(self) -> bool:
        pass

    def redefineIfPossible(self) -> None:
        pass

    def setCommon(self, Size: int, Align: int, Target: bool = False) -> None:
        pass

    def setExternal(self, arg0: bool) -> None:
        pass

    def setIndex(self, arg0: int) -> None:
        pass

    def setIsRegistered(self, arg0: bool) -> None:
        pass

    def setOffset(self, arg0: int) -> None:
        pass

    def setPrivateExtern(self, arg0: bool) -> None:
        pass

    def setRedefinable(self, arg0: bool) -> None:
        pass

    def setUndefined(self) -> None:
        pass

    def setUsedInReloc(self) -> None:
        pass
