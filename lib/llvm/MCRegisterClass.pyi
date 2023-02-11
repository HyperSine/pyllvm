from typing import Iterator
from .MCRegister import MCRegister

class MCRegisterClass:

    def __contains__(self, arg0: MCRegister) -> bool:
        pass

    def __getitem__(self, i: int) -> MCRegister:
        pass

    def __iter__(self) -> Iterator:
        pass

    def __len__(self) -> int:
        pass

    def getCopyCost(self) -> int:
        pass

    def getID(self) -> int:
        pass

    def getNumRegs(self) -> int:
        pass

    def getRegister(self, arg0: int) -> int:
        pass

    def getSizeInBits(self) -> int:
        pass

    def isAllocatable(self) -> bool:
        pass
