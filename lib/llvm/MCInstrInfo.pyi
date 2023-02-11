from .MCInstrDesc import MCInstrDesc

class MCInstrInfo:

    def get(self, Opcode: int) -> MCInstrDesc:
        pass

    def getName(self, Opcode: int) -> str:
        pass

    def getNumOpcodes(self) -> int:
        pass
