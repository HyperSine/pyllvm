from typing import Any, ClassVar, overload
from .MCAsmInfo import MCAsmInfo
from .MCAsmMacro import MCAsmMacro
from .MCInst import MCInst
from .MCObjectFileInfo import MCObjectFileInfo
from .MCRegisterInfo import MCRegisterInfo
from .MCSectionMachO import MCSectionMachO
from .MCSubtargetInfo import MCSubtargetInfo
from .MCSymbol import MCSymbol
from .MCTargetOptions import MCTargetOptions
from .SectionKind import SectionKind
from .SourceMgr import SourceMgr
from .Triple import Triple

class MCContext:

    class Environment:

        IsCOFF: ClassVar[MCContext.Environment]
        IsELF: ClassVar[MCContext.Environment]
        IsGOFF: ClassVar[MCContext.Environment]
        IsMachO: ClassVar[MCContext.Environment]
        IsWasm: ClassVar[MCContext.Environment]
        IsXCOFF: ClassVar[MCContext.Environment]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: MCContext.Environment) -> int:
            pass

        def __eq__(self, other: object) -> bool:
            pass

        def __getstate__(self) -> int:
            pass

        def __hash__(self) -> int:
            pass

        def __index__(self) -> int:
            pass

        def __init__(self, value: int) -> None:
            pass

        def __int__(self) -> int:
            pass

        def __ne__(self, other: object) -> bool:
            pass

        def __repr__(self) -> str:
            pass

        def __setstate__(self, state: int) -> None:
            pass

        def name(self) -> str:
            pass

    def __init__(self, TheTriple: Triple, MAI: MCAsmInfo, MRI: MCRegisterInfo, MSTI: MCSubtargetInfo, Mgr: SourceMgr = None, TargetOpts: MCTargetOptions = None, DoAutoReset: bool = True, Swift5ReflSegmentName: str = '') -> None:
        pass

    def clearDwarfLocSeen(self) -> None:
        pass

    def createDirectionalLocalSymbol(self, arg0: int) -> MCSymbol:
        pass

    def createLinkerPrivateTempSymbol(self) -> MCSymbol:
        pass

    def createMCInst(self) -> MCInst:
        pass

    @overload
    def createNamedTempSymbol(self) -> MCSymbol:
        pass

    @overload
    def createNamedTempSymbol(self, Name: str) -> MCSymbol:
        pass

    @overload
    def createTempSymbol(self) -> MCSymbol:
        pass

    @overload
    def createTempSymbol(self, Name: str, AlwaysAddSuffix: bool = True) -> MCSymbol:
        pass

    def defineMacro(self, arg0: str, arg1: MCAsmMacro) -> None:
        pass

    def getAsmInfo(self) -> MCAsmInfo:
        pass

    def getDirectionalLocalSymbol(self, arg0: int, arg1: bool) -> MCSymbol:
        pass

    def getDwarfCompileUnitID(self) -> int:
        pass

    def getDwarfLocSeen(self) -> bool:
        pass

    def getGenDwarfFileNumber(self) -> int:
        pass

    def getGenDwarfForAssembly(self) -> bool:
        pass

    def getInlineSourceManager(self) -> SourceMgr:
        pass

    @overload
    def getMachOSection(self, Segment: str, Section: str, TypeAndAttributes: int, Reserved2: int, K: SectionKind, BeginSymName: str = None) -> MCSectionMachO:
        pass

    @overload
    def getMachOSection(self, Segment: str, Section: str, TypeAndAttributes: int, K: SectionKind, BeginSymName: str = None) -> MCSectionMachO:
        pass

    def getObjectFileInfo(self) -> MCObjectFileInfo:
        pass

    def getObjectFileType(self) -> MCContext.Environment:
        pass

    def getRegisterInfo(self) -> MCRegisterInfo:
        pass

    def getSecureLogFile(self) -> str:
        pass

    def getSecureLogUsed(self) -> bool:
        pass

    def getSourceManager(self) -> SourceMgr:
        pass

    def getSubtargetInfo(self) -> MCSubtargetInfo:
        pass

    def getSwift5ReflectionSegmentName(self) -> str:
        pass

    def getTargetTriple(self) -> Triple:
        pass

    def hadError(self) -> bool:
        pass

    def initInlineSourceManager(self) -> None:
        pass

    def isDwarfMD5UsageConsistent(self, arg0: int) -> bool:
        pass

    def lookupMacro(self, arg0: str) -> MCAsmMacro:
        pass

    def reset(self) -> None:
        pass

    def setAllowTemporaryLabels(self, arg0: bool) -> None:
        pass

    def setCurrentDwarfLoc(self, arg0: int, arg1: int, arg2: int, arg3: int, arg4: int, arg5: int) -> None:
        pass

    def setDwarfCompileUnitID(self, arg0: int) -> None:
        pass

    def setDwarfDebugFlags(self, arg0: str) -> None:
        pass

    def setDwarfDebugProducer(self, arg0: str) -> None:
        pass

    def setDwarfVersion(self, v: int) -> None:
        pass

    def setGenDwarfFileNumber(self, arg0: int) -> None:
        pass

    def setGenDwarfForAssembly(self, arg0: bool) -> None:
        pass

    def setSecureLogUsed(self, arg0: bool) -> None:
        pass

    def setUseNamesOnTempLabels(self, arg0: bool) -> None:
        pass

    def undefineMacro(self, arg0: str) -> None:
        pass
