from typing import Any, ClassVar

class AliasPatternCond:

    class CondKind:

        Custom: ClassVar[AliasPatternCond.CondKind]
        EndOrFeatures: ClassVar[AliasPatternCond.CondKind]
        Feature: ClassVar[AliasPatternCond.CondKind]
        Ignore: ClassVar[AliasPatternCond.CondKind]
        Imm: ClassVar[AliasPatternCond.CondKind]
        NegFeature: ClassVar[AliasPatternCond.CondKind]
        OrFeature: ClassVar[AliasPatternCond.CondKind]
        OrNegFeature: ClassVar[AliasPatternCond.CondKind]
        Reg: ClassVar[AliasPatternCond.CondKind]
        RegClass: ClassVar[AliasPatternCond.CondKind]
        TiedReg: ClassVar[AliasPatternCond.CondKind]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: AliasPatternCond.CondKind) -> int:
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
    def Kind(self) -> AliasPatternCond.CondKind:
        pass

    @Kind.setter
    def Kind(self, arg0: AliasPatternCond.CondKind) -> None:
        pass

    @property
    def Value(self) -> int:
        pass

    @Value.setter
    def Value(self, arg0: int) -> None:
        pass

    def __init__(self) -> None:
        pass
