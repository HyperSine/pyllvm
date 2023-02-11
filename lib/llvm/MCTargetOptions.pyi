from typing import Any, ClassVar
from .EmitDwarfUnwindType import EmitDwarfUnwindType

class MCTargetOptions:

    class AsmInstrumentation:

        Address: ClassVar[MCTargetOptions.AsmInstrumentation]
        Null: ClassVar[MCTargetOptions.AsmInstrumentation]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: MCTargetOptions.AsmInstrumentation) -> int:
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

    class DwarfDirectory:

        Default: ClassVar[MCTargetOptions.DwarfDirectory]
        Disable: ClassVar[MCTargetOptions.DwarfDirectory]
        Enable: ClassVar[MCTargetOptions.DwarfDirectory]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: MCTargetOptions.DwarfDirectory) -> int:
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

    @property
    def ABIName(arg0: MCTargetOptions) -> str:
        pass

    @ABIName.setter
    def ABIName(arg0: MCTargetOptions, arg1: str) -> None:
        pass

    @property
    def AsmVerbose(arg0: MCTargetOptions) -> bool:
        pass

    @AsmVerbose.setter
    def AsmVerbose(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def AssemblyLanguage(arg0: MCTargetOptions) -> str:
        pass

    @AssemblyLanguage.setter
    def AssemblyLanguage(arg0: MCTargetOptions, arg1: str) -> None:
        pass

    @property
    def Dwarf64(arg0: MCTargetOptions) -> bool:
        pass

    @Dwarf64.setter
    def Dwarf64(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def DwarfVersion(arg0: MCTargetOptions) -> int:
        pass

    @DwarfVersion.setter
    def DwarfVersion(arg0: MCTargetOptions, arg1: int) -> None:
        pass

    @property
    def EmitDwarfUnwind(arg0: MCTargetOptions) -> EmitDwarfUnwindType:
        pass

    @EmitDwarfUnwind.setter
    def EmitDwarfUnwind(arg0: MCTargetOptions, arg1: EmitDwarfUnwindType) -> None:
        pass

    @property
    def MCFatalWarnings(arg0: MCTargetOptions) -> bool:
        pass

    @MCFatalWarnings.setter
    def MCFatalWarnings(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def MCIncrementalLinkerCompatible(arg0: MCTargetOptions) -> bool:
        pass

    @MCIncrementalLinkerCompatible.setter
    def MCIncrementalLinkerCompatible(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def MCNoDeprecatedWarn(arg0: MCTargetOptions) -> bool:
        pass

    @MCNoDeprecatedWarn.setter
    def MCNoDeprecatedWarn(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def MCNoExecStack(arg0: MCTargetOptions) -> bool:
        pass

    @MCNoExecStack.setter
    def MCNoExecStack(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def MCNoTypeCheck(arg0: MCTargetOptions) -> bool:
        pass

    @MCNoTypeCheck.setter
    def MCNoTypeCheck(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def MCNoWarn(arg0: MCTargetOptions) -> bool:
        pass

    @MCNoWarn.setter
    def MCNoWarn(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def MCRelaxAll(arg0: MCTargetOptions) -> bool:
        pass

    @MCRelaxAll.setter
    def MCRelaxAll(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def MCSaveTempLabels(arg0: MCTargetOptions) -> bool:
        pass

    @MCSaveTempLabels.setter
    def MCSaveTempLabels(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def MCUseDwarfDirectory(arg0: MCTargetOptions) -> MCTargetOptions.DwarfDirectory:
        pass

    @MCUseDwarfDirectory.setter
    def MCUseDwarfDirectory(arg0: MCTargetOptions, arg1: MCTargetOptions.DwarfDirectory) -> None:
        pass

    @property
    def PreserveAsmComments(arg0: MCTargetOptions) -> bool:
        pass

    @PreserveAsmComments.setter
    def PreserveAsmComments(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def ShowMCEncoding(arg0: MCTargetOptions) -> bool:
        pass

    @ShowMCEncoding.setter
    def ShowMCEncoding(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def ShowMCInst(arg0: MCTargetOptions) -> bool:
        pass

    @ShowMCInst.setter
    def ShowMCInst(arg0: MCTargetOptions, arg1: bool) -> None:
        pass

    @property
    def SplitDwarfFile(arg0: MCTargetOptions) -> str:
        pass

    @SplitDwarfFile.setter
    def SplitDwarfFile(arg0: MCTargetOptions, arg1: str) -> None:
        pass

    def __init__(self) -> None:
        pass

    def getABIName(self) -> str:
        pass

    def getAssemblyLanguage(self) -> str:
        pass
