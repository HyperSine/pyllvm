from typing import BinaryIO, Optional
from .MCRegisterInfo import MCRegisterInfo

class MCOperand:

    @staticmethod
    def createDFPImm(Val: int) -> MCOperand:
        pass

    @staticmethod
    def createImm(Val: int) -> MCOperand:
        pass

    @staticmethod
    def createReg(Reg: int) -> MCOperand:
        pass

    @staticmethod
    def createSFPImm(Val: int) -> MCOperand:
        pass

    @property
    def DFPImm(arg0: MCOperand) -> int:
        pass

    @DFPImm.setter
    def DFPImm(arg0: MCOperand, arg1: int) -> None:
        pass

    @property
    def Imm(arg0: MCOperand) -> int:
        pass

    @Imm.setter
    def Imm(arg0: MCOperand, arg1: int) -> None:
        pass

    @property
    def Reg(arg0: MCOperand) -> int:
        pass

    @Reg.setter
    def Reg(arg0: MCOperand, arg1: int) -> None:
        pass

    @property
    def SFPImm(arg0: MCOperand) -> int:
        pass

    @SFPImm.setter
    def SFPImm(arg0: MCOperand, arg1: int) -> None:
        pass

    def __init__(self) -> None:
        pass

    def evaluateAsConstantImm(self) -> Optional[int]:
        pass

    def isBareSymbolRef(self) -> bool:
        pass

    def isDFPImm(self) -> bool:
        pass

    def isExpr(self) -> bool:
        pass

    def isImm(self) -> bool:
        pass

    def isInst(self) -> bool:
        pass

    def isReg(self) -> bool:
        pass

    def isSFPImm(self) -> bool:
        pass

    def isValid(self) -> bool:
        pass

    def print(self, OS: BinaryIO, RegInfo: Optional[MCRegisterInfo] = None) -> None:
        pass
