class MCRegister:

    @staticmethod
    def isPhysicalRegister(Reg: int) -> bool:
        pass

    @staticmethod
    def isStackSlot(Reg: int) -> bool:
        pass

    def __eq__(self, arg0: MCRegister) -> bool:
        pass

    def __hash__(self) -> int:
        pass

    def __init__(self, Val: int = 0) -> None:
        pass

    def __int__(self) -> int:
        pass

    def __ne__(self, arg0: MCRegister) -> bool:
        pass

    def __repr__(self) -> str:
        pass

    def isValid(self) -> bool:
        pass
