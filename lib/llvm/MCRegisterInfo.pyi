from typing import Optional
from .MCRegister import MCRegister
from .MCRegisterClass import MCRegisterClass
from .MCRegisterDesc import MCRegisterDesc

class MCRegisterInfo:

    def __getitem__(self, arg0: MCRegister) -> MCRegisterDesc:
        pass

    def getCodeViewRegNum(self, arg0: MCRegister) -> int:
        pass

    def getDwarfRegNum(self, arg0: MCRegister, arg1: bool) -> int:
        pass

    def getDwarfRegNumFromDwarfEHRegNum(self, arg0: int) -> int:
        pass

    def getEncodingValue(self, arg0: MCRegister) -> int:
        pass

    def getLLVMRegNum(self, arg0: int, arg1: bool) -> Optional[int]:
        pass

    def getMatchingSuperReg(self, Reg: MCRegister, SubIdx: int, RC: MCRegisterClass) -> MCRegister:
        pass

    def getName(self, arg0: MCRegister) -> str:
        pass

    def getNumRegClasses(self) -> int:
        pass

    def getNumRegUnits(self) -> int:
        pass

    def getNumRegs(self) -> int:
        pass

    def getNumSubRegIndices(self) -> int:
        pass

    def getProgramCounter(self) -> MCRegister:
        pass

    def getRARegister(self) -> MCRegister:
        pass

    def getRegClass(self, arg0: int) -> MCRegisterClass:
        pass

    def getRegClassName(self, arg0: MCRegisterClass) -> str:
        pass

    def getSEHRegNum(self, arg0: MCRegister) -> int:
        pass

    def getSubReg(self, Reg: MCRegister, Idx: int) -> MCRegister:
        pass

    def getSubRegIdxOffset(self, arg0: int) -> int:
        pass

    def getSubRegIdxSize(self, arg0: int) -> int:
        pass

    def getSubRegIndex(self, RegNo: MCRegister, SubRegNo: MCRegister) -> int:
        pass

    def isSubRegister(self, RegA: MCRegister, RegB: MCRegister) -> bool:
        pass

    def isSubRegisterEq(self, RegA: MCRegister, RegB: MCRegister) -> bool:
        pass

    def isSuperOrSubRegisterEq(self, RegA: MCRegister, RegB: MCRegister) -> bool:
        pass

    def isSuperRegister(self, RegA: MCRegister, RegB: MCRegister) -> bool:
        pass

    def isSuperRegisterEq(self, RegA: MCRegister, RegB: MCRegister) -> bool:
        pass

    def mapLLVMRegToCVReg(self, LLVMReg: MCRegister, CVReg: int) -> None:
        pass

    def mapLLVMRegToSEHReg(self, LLVMReg: MCRegister, SEHReg: int) -> None:
        pass
