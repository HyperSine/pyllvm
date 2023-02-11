from typing import Any, ClassVar, Iterator
from .SectionKind import SectionKind

class MCSection:

    class BundleLockStateType:

        BundleLocked: ClassVar[MCSection.BundleLockStateType]
        BundleLockedAlignToEnd: ClassVar[MCSection.BundleLockStateType]
        NotBundleLocked: ClassVar[MCSection.BundleLockStateType]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: MCSection.BundleLockStateType) -> int:
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

    class SectionVariant:

        COFF: ClassVar[MCSection.SectionVariant]
        ELF: ClassVar[MCSection.SectionVariant]
        GOFF: ClassVar[MCSection.SectionVariant]
        MachO: ClassVar[MCSection.SectionVariant]
        Wasm: ClassVar[MCSection.SectionVariant]
        XCOFF: ClassVar[MCSection.SectionVariant]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: MCSection.SectionVariant) -> int:
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
    def BundleGroupBeforeFirstInst(arg0: MCSection) -> bool:
        pass

    @BundleGroupBeforeFirstInst.setter
    def BundleGroupBeforeFirstInst(arg0: MCSection, arg1: bool) -> None:
        pass

    @property
    def BundleLockState(arg0: MCSection) -> MCSection.BundleLockStateType:
        pass

    @BundleLockState.setter
    def BundleLockState(arg0: MCSection, arg1: MCSection.BundleLockStateType) -> None:
        pass

    @property
    def HasInstructions(arg0: MCSection) -> bool:
        pass

    @HasInstructions.setter
    def HasInstructions(arg0: MCSection, arg1: bool) -> None:
        pass

    @property
    def IsRegistered(arg0: MCSection) -> bool:
        pass

    @IsRegistered.setter
    def IsRegistered(arg0: MCSection, arg1: bool) -> None:
        pass

    @property
    def LayoutOrder(arg0: MCSection) -> int:
        pass

    @LayoutOrder.setter
    def LayoutOrder(arg0: MCSection, arg1: int) -> None:
        pass

    @property
    def NonUniqueID(arg0: object) -> int:
        pass

    @property
    def Ordinal(arg0: MCSection) -> int:
        pass

    @Ordinal.setter
    def Ordinal(arg0: MCSection, arg1: int) -> None:
        pass

    def __iter__(self) -> Iterator:
        pass

    def flushPendingLabels(self) -> None:
        pass

    def getAlignment(self) -> int:
        pass

    def getKind(self) -> SectionKind:
        pass

    def getName(self) -> str:
        pass

    def getVariant(self) -> MCSection.SectionVariant:
        pass

    def getVirtualSectionKind(self) -> str:
        pass

    def hasEnded(self) -> bool:
        pass

    def isBundleLocked(self) -> bool:
        pass

    def isVirtualSection(self) -> bool:
        pass

    def useCodeAlign(self) -> bool:
        pass
