from typing import List
from .MCOperand import MCOperand
from .MCRegisterInfo import MCRegisterInfo
from .SMLoc import SMLoc

class MCInst:

    @property
    def Flags(arg0: MCInst) -> int:
        pass

    @Flags.setter
    def Flags(arg0: MCInst, arg1: int) -> None:
        pass

    @property
    def Loc(arg0: MCInst) -> SMLoc:
        pass

    @Loc.setter
    def Loc(arg0: MCInst, arg1: SMLoc) -> None:
        pass

    @property
    def Opcode(arg0: MCInst) -> int:
        pass

    @Opcode.setter
    def Opcode(arg0: MCInst, arg1: int) -> None:
        pass

    @property
    def Operands(arg0: MCInst) -> List[MCOperand]:
        pass

    def __init__(self) -> None:
        pass

    def clear(self) -> None:
        pass

    def getNumOperands(self) -> int:
        pass

    def getOperand(self, arg0: int) -> MCOperand:
        pass

    def print(self, OS: object, RegInfo: MCRegisterInfo = None) -> None:
        pass
