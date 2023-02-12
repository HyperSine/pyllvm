from typing import BinaryIO
from .MCInst import MCInst
from .MCSubtargetInfo import MCSubtargetInfo

class MCCodeEmitter:

    def emitPrefix(self, Inst: MCInst, OS: BinaryIO, STI: MCSubtargetInfo) -> None:
        pass

    def reset(self) -> None:
        pass
