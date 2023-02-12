from .MCAsmBackend import MCAsmBackend
from .MCAsmInfo import MCAsmInfo
from .MCAsmParser import MCAsmParser
from .MCCodeEmitter import MCCodeEmitter
from .MCContext import MCContext
from .MCDisassembler import MCDisassembler
from .MCInstPrinter import MCInstPrinter
from .MCInstrAnalysis import MCInstrAnalysis
from .MCInstrInfo import MCInstrInfo
from .MCObjectFileInfo import MCObjectFileInfo
from .MCRegisterInfo import MCRegisterInfo
from .MCSubtargetInfo import MCSubtargetInfo
from .MCTargetAsmParser import MCTargetAsmParser
from .MCTargetOptions import MCTargetOptions
from .Triple import Triple

class Target:

    def createMCAsmBackend(self, STI: MCSubtargetInfo, MRI: MCRegisterInfo, Options: MCTargetOptions) -> MCAsmBackend:
        pass

    def createMCAsmInfo(self, MRI: MCRegisterInfo, TheTriple: str, Options: MCTargetOptions) -> MCAsmInfo:
        pass

    def createMCAsmParser(self, STI: MCSubtargetInfo, Parser: MCAsmParser, MII: MCInstrInfo, Options: MCTargetOptions) -> MCTargetAsmParser:
        pass

    def createMCCodeEmitter(self, II: MCInstrInfo, Ctx: MCContext) -> MCCodeEmitter:
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
