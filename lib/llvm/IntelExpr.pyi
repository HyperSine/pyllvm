class IntelExpr:

    def emitImm(self) -> bool:
        pass

    def hasBaseReg(self) -> bool:
        pass

    def hasIndexReg(self) -> bool:
        pass

    def hasOffset(self) -> bool:
        pass

    def hasRegs(self) -> bool:
        pass

    def isValid(self) -> bool:
        pass
