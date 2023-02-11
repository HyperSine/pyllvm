class SectionKind:

    @staticmethod
    def getBSS() -> SectionKind:
        pass

    @staticmethod
    def getBSSExtern() -> SectionKind:
        pass

    @staticmethod
    def getBSSLocal() -> SectionKind:
        pass

    @staticmethod
    def getCommon() -> SectionKind:
        pass

    @staticmethod
    def getData() -> SectionKind:
        pass

    @staticmethod
    def getExecuteOnly() -> SectionKind:
        pass

    @staticmethod
    def getMergeable1ByteCString() -> SectionKind:
        pass

    @staticmethod
    def getMergeable2ByteCString() -> SectionKind:
        pass

    @staticmethod
    def getMergeable4ByteCString() -> SectionKind:
        pass

    @staticmethod
    def getMergeableConst16() -> SectionKind:
        pass

    @staticmethod
    def getMergeableConst32() -> SectionKind:
        pass

    @staticmethod
    def getMergeableConst4() -> SectionKind:
        pass

    @staticmethod
    def getMergeableConst8() -> SectionKind:
        pass

    @staticmethod
    def getMetadata() -> SectionKind:
        pass

    @staticmethod
    def getReadOnly() -> SectionKind:
        pass

    @staticmethod
    def getReadOnlyWithRel() -> SectionKind:
        pass

    @staticmethod
    def getText() -> SectionKind:
        pass

    @staticmethod
    def getThreadBSS() -> SectionKind:
        pass

    @staticmethod
    def getThreadBSSLocal() -> SectionKind:
        pass

    @staticmethod
    def getThreadData() -> SectionKind:
        pass

    def isBSS(self) -> bool:
        pass

    def isBSSExtern(self) -> bool:
        pass

    def isBSSLocal(self) -> bool:
        pass

    def isCommon(self) -> bool:
        pass

    def isData(self) -> bool:
        pass

    def isExecuteOnly(self) -> bool:
        pass

    def isGlobalWriteableData(self) -> bool:
        pass

    def isMergeable1ByteCString(self) -> bool:
        pass

    def isMergeable2ByteCString(self) -> bool:
        pass

    def isMergeable4ByteCString(self) -> bool:
        pass

    def isMergeableCString(self) -> bool:
        pass

    def isMergeableConst(self) -> bool:
        pass

    def isMergeableConst16(self) -> bool:
        pass

    def isMergeableConst32(self) -> bool:
        pass

    def isMergeableConst4(self) -> bool:
        pass

    def isMergeableConst8(self) -> bool:
        pass

    def isMetadata(self) -> bool:
        pass

    def isReadOnly(self) -> bool:
        pass

    def isReadOnlyWithRel(self) -> bool:
        pass

    def isText(self) -> bool:
        pass

    def isThreadBSS(self) -> bool:
        pass

    def isThreadBSSLocal(self) -> bool:
        pass

    def isThreadData(self) -> bool:
        pass

    def isThreadLocal(self) -> bool:
        pass

    def isWriteable(self) -> bool:
        pass
