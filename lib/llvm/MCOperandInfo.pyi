class MCOperandInfo:

    @property
    def Constraints(self) -> int:
        pass

    @Constraints.setter
    def Constraints(self, arg0: int) -> None:
        pass

    @property
    def Flags(self) -> int:
        pass

    @Flags.setter
    def Flags(self, arg0: int) -> None:
        pass

    @property
    def OperandType(self) -> int:
        pass

    @OperandType.setter
    def OperandType(self, arg0: int) -> None:
        pass

    @property
    def RegClass(self) -> int:
        pass

    @RegClass.setter
    def RegClass(self, arg0: int) -> None:
        pass

    def getGenericImmIndex(self) -> int:
        pass

    def getGenericTypeIndex(self) -> int:
        pass

    def isBranchTarget(self) -> bool:
        pass

    def isGenericImm(self) -> bool:
        pass

    def isGenericType(self) -> bool:
        pass

    def isLookupPtrRegClass(self) -> bool:
        pass

    def isOptionalDef(self) -> bool:
        pass

    def isPredicate(self) -> bool:
        pass
