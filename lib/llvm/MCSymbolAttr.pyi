from typing import Any, ClassVar

class MCSymbolAttr:

    AltEntry: ClassVar[MCSymbolAttr]
    Cold: ClassVar[MCSymbolAttr]
    ELF_TypeCommon: ClassVar[MCSymbolAttr]
    ELF_TypeFunction: ClassVar[MCSymbolAttr]
    ELF_TypeGnuUniqueObject: ClassVar[MCSymbolAttr]
    ELF_TypeIndFunction: ClassVar[MCSymbolAttr]
    ELF_TypeNoType: ClassVar[MCSymbolAttr]
    ELF_TypeObject: ClassVar[MCSymbolAttr]
    ELF_TypeTLS: ClassVar[MCSymbolAttr]
    Extern: ClassVar[MCSymbolAttr]
    Global: ClassVar[MCSymbolAttr]
    Hidden: ClassVar[MCSymbolAttr]
    IndirectSymbol: ClassVar[MCSymbolAttr]
    Internal: ClassVar[MCSymbolAttr]
    Invalid: ClassVar[MCSymbolAttr]
    LGlobal: ClassVar[MCSymbolAttr]
    LazyReference: ClassVar[MCSymbolAttr]
    Local: ClassVar[MCSymbolAttr]
    NoDeadStrip: ClassVar[MCSymbolAttr]
    PrivateExtern: ClassVar[MCSymbolAttr]
    Protected: ClassVar[MCSymbolAttr]
    Reference: ClassVar[MCSymbolAttr]
    SymbolResolver: ClassVar[MCSymbolAttr]
    Weak: ClassVar[MCSymbolAttr]
    WeakDefAutoPrivate: ClassVar[MCSymbolAttr]
    WeakDefinition: ClassVar[MCSymbolAttr]
    WeakReference: ClassVar[MCSymbolAttr]

    @property
    def name(self) -> str:
        pass

    @property
    def value(arg0: MCSymbolAttr) -> int:
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
