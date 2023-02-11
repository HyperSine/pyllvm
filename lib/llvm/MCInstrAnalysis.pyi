from .MCInst import MCInst

class MCInstrAnalysis:

    def isBranch(self, Inst: MCInst) -> bool:
        pass

    def isCall(self, Inst: MCInst) -> bool:
        pass

    def isConditionalBranch(self, Inst: MCInst) -> bool:
        pass

    def isIndirectBranch(self, Inst: MCInst) -> bool:
        pass

    def isReturn(self, Inst: MCInst) -> bool:
        pass

    def isTerminator(self, Inst: MCInst) -> bool:
        pass

    def isUnconditionalBranch(self, Inst: MCInst) -> bool:
        pass
