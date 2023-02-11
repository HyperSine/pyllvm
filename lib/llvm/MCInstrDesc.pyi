from typing import List
from .MCInst import MCInst
from .MCOperandInfo import MCOperandInfo
from .MCRegisterInfo import MCRegisterInfo

class MCInstrDesc:

    @property
    def Flags(arg0: MCInstrDesc) -> int:
        pass

    @property
    def ImplicitDefs(arg0: MCInstrDesc) -> List[int]:
        pass

    @property
    def ImplicitUses(arg0: MCInstrDesc) -> List[int]:
        pass

    @property
    def NumDefs(arg0: MCInstrDesc) -> int:
        pass

    @property
    def NumOperands(arg0: MCInstrDesc) -> int:
        pass

    @property
    def Opcode(arg0: MCInstrDesc) -> int:
        pass

    @property
    def OperandInfos(arg0: MCInstrDesc) -> List[MCOperandInfo]:
        pass

    @property
    def SchedClass(arg0: MCInstrDesc) -> int:
        pass

    @property
    def Size(arg0: MCInstrDesc) -> int:
        pass

    def canFoldAsLoad(self) -> bool:
        pass

    def findFirstPredOperandIdx(self) -> int:
        pass

    def getNumImplicitDefs(self) -> int:
        pass

    def getNumImplicitUses(self) -> int:
        pass

    def hasDefOfPhysReg(self, MI: MCInst, Reg: int, RI: MCRegisterInfo) -> bool:
        pass

    def hasDelaySlot(self) -> bool:
        pass

    def hasExtraDefRegAllocReq(self) -> bool:
        pass

    def hasExtraSrcRegAllocReq(self) -> bool:
        pass

    def hasImplicitDefOfPhysReg(self, Reg: int, MRI: MCRegisterInfo) -> bool:
        pass

    def hasImplicitUseOfPhysReg(self, Reg: int) -> bool:
        pass

    def hasOptionalDef(self) -> bool:
        pass

    def hasPostISelHook(self) -> bool:
        pass

    def hasUnmodeledSideEffects(self) -> bool:
        pass

    def isAdd(self) -> bool:
        pass

    def isAsCheapAsAMove(self) -> bool:
        pass

    def isAuthenticated(self) -> bool:
        pass

    def isBarrier(self) -> bool:
        pass

    def isBitcast(self) -> bool:
        pass

    def isBranch(self) -> bool:
        pass

    def isCall(self) -> bool:
        pass

    def isCommutable(self) -> bool:
        pass

    def isCompare(self) -> bool:
        pass

    def isConditionalBranch(self) -> bool:
        pass

    def isConvergent(self) -> bool:
        pass

    def isConvertibleTo3Addr(self) -> bool:
        pass

    def isExtractSubregLike(self) -> bool:
        pass

    def isIndirectBranch(self) -> bool:
        pass

    def isInsertSubregLike(self) -> bool:
        pass

    def isMoveImmediate(self) -> bool:
        pass

    def isMoveReg(self) -> bool:
        pass

    def isNotDuplicable(self) -> bool:
        pass

    def isPreISelOpcode(self) -> bool:
        pass

    def isPredicable(self) -> bool:
        pass

    def isPseudo(self) -> bool:
        pass

    def isRegSequenceLike(self) -> bool:
        pass

    def isRematerializable(self) -> bool:
        pass

    def isReturn(self) -> bool:
        pass

    def isSelect(self) -> bool:
        pass

    def isTerminator(self) -> bool:
        pass

    def isTrap(self) -> bool:
        pass

    def isUnconditionalBranch(self) -> bool:
        pass

    def isVariadic(self) -> bool:
        pass

    def mayAffectControlFlow(self, MI: MCInst, RI: MCRegisterInfo) -> bool:
        pass

    def mayLoad(self) -> bool:
        pass

    def mayRaiseFPException(self) -> bool:
        pass

    def mayStore(self) -> bool:
        pass

    def usesCustomInsertionHook(self) -> bool:
        pass

    def variadicOpsAreDefs(self) -> bool:
        pass
