from typing import Any, ClassVar

class AsmRewriteKind:

    Align: ClassVar[AsmRewriteKind]
    CallInput: ClassVar[AsmRewriteKind]
    Emit: ClassVar[AsmRewriteKind]
    EndOfStatement: ClassVar[AsmRewriteKind]
    Even: ClassVar[AsmRewriteKind]
    Input: ClassVar[AsmRewriteKind]
    IntelExpr: ClassVar[AsmRewriteKind]
    Label: ClassVar[AsmRewriteKind]
    Output: ClassVar[AsmRewriteKind]
    SizeDirective: ClassVar[AsmRewriteKind]
    Skip: ClassVar[AsmRewriteKind]

    @property
    def name(self) -> str:
        pass

    @property
    def value(arg0: AsmRewriteKind) -> int:
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
