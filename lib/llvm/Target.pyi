from .MCAsmInfo import MCAsmInfo
from .MCContext import MCContext
from .MCDisassembler import MCDisassembler
from .MCInstPrinter import MCInstPrinter
from .MCInstrAnalysis import MCInstrAnalysis
from .MCInstrInfo import MCInstrInfo
from .MCObjectFileInfo import MCObjectFileInfo
from .MCRegisterInfo import MCRegisterInfo
from .MCSubtargetInfo import MCSubtargetInfo
from .MCTargetOptions import MCTargetOptions
from .Triple import Triple

class Target:

    def createMCAsmInfo(self, MRI: MCRegisterInfo, TheTriple: str, Options: MCTargetOptions) -> MCAsmInfo:
        pass

    def createMCDisassembler(self, STI: MCSubtargetInfo, Ctx: MCContext) -> MCDisassembler:
        pass

    def createMCInstPrinter(self, T: Triple, SyntaxVariant: int, MAI: MCAsmInfo, MII: MCInstrInfo, MRI: MCRegisterInfo) -> MCInstPrinter:
        pass

    def createMCInstrAnalysis(self, Info: MCInstrInfo) -> MCInstrAnalysis:
        pass

    def createMCInstrInfo(self) -> MCInstrInfo:
        pass

    def createMCObjectFileInfo(self, Ctx: MCContext, PIC: bool, LargeCodeModel: bool = False) -> MCObjectFileInfo:
        pass

    def createMCRegInfo(self, TT: str) -> MCRegisterInfo:
        pass

    def createMCSubtargetInfo(self, TheTriple: str, CPU: str, Features: str) -> MCSubtargetInfo:
        pass

    def getBackendName(self) -> str:
        pass

    def getName(self) -> str:
        pass

    def getNext(self) -> Target:
        pass

    def getShortDescription(self) -> str:
        pass

    def hasJIT(self) -> bool:
        pass

    def hasMCAsmBackend(self) -> bool:
        pass

    def hasMCAsmParser(self) -> bool:
        pass

    def hasTargetMachine(self) -> bool:
        pass
