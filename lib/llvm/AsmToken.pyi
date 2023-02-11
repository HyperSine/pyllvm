from typing import Any, ClassVar, overload
from .SMLoc import SMLoc

class AsmToken:

    class TokenKind:

        Amp: ClassVar[AsmToken.TokenKind]
        AmpAmp: ClassVar[AsmToken.TokenKind]
        At: ClassVar[AsmToken.TokenKind]
        BackSlash: ClassVar[AsmToken.TokenKind]
        BigNum: ClassVar[AsmToken.TokenKind]
        Caret: ClassVar[AsmToken.TokenKind]
        Colon: ClassVar[AsmToken.TokenKind]
        Comma: ClassVar[AsmToken.TokenKind]
        Comment: ClassVar[AsmToken.TokenKind]
        Dollar: ClassVar[AsmToken.TokenKind]
        Dot: ClassVar[AsmToken.TokenKind]
        EndOfStatement: ClassVar[AsmToken.TokenKind]
        Eof: ClassVar[AsmToken.TokenKind]
        Equal: ClassVar[AsmToken.TokenKind]
        EqualEqual: ClassVar[AsmToken.TokenKind]
        Error: ClassVar[AsmToken.TokenKind]
        Exclaim: ClassVar[AsmToken.TokenKind]
        ExclaimEqual: ClassVar[AsmToken.TokenKind]
        Greater: ClassVar[AsmToken.TokenKind]
        GreaterEqual: ClassVar[AsmToken.TokenKind]
        GreaterGreater: ClassVar[AsmToken.TokenKind]
        Hash: ClassVar[AsmToken.TokenKind]
        HashDirective: ClassVar[AsmToken.TokenKind]
        Identifier: ClassVar[AsmToken.TokenKind]
        Integer: ClassVar[AsmToken.TokenKind]
        LBrac: ClassVar[AsmToken.TokenKind]
        LCurly: ClassVar[AsmToken.TokenKind]
        LParen: ClassVar[AsmToken.TokenKind]
        Less: ClassVar[AsmToken.TokenKind]
        LessEqual: ClassVar[AsmToken.TokenKind]
        LessGreater: ClassVar[AsmToken.TokenKind]
        LessLess: ClassVar[AsmToken.TokenKind]
        Minus: ClassVar[AsmToken.TokenKind]
        MinusGreater: ClassVar[AsmToken.TokenKind]
        Percent: ClassVar[AsmToken.TokenKind]
        PercentCall16: ClassVar[AsmToken.TokenKind]
        PercentCall_Hi: ClassVar[AsmToken.TokenKind]
        PercentCall_Lo: ClassVar[AsmToken.TokenKind]
        PercentDtprel_Hi: ClassVar[AsmToken.TokenKind]
        PercentDtprel_Lo: ClassVar[AsmToken.TokenKind]
        PercentGot: ClassVar[AsmToken.TokenKind]
        PercentGot_Disp: ClassVar[AsmToken.TokenKind]
        PercentGot_Hi: ClassVar[AsmToken.TokenKind]
        PercentGot_Lo: ClassVar[AsmToken.TokenKind]
        PercentGot_Ofst: ClassVar[AsmToken.TokenKind]
        PercentGot_Page: ClassVar[AsmToken.TokenKind]
        PercentGottprel: ClassVar[AsmToken.TokenKind]
        PercentGp_Rel: ClassVar[AsmToken.TokenKind]
        PercentHi: ClassVar[AsmToken.TokenKind]
        PercentHigher: ClassVar[AsmToken.TokenKind]
        PercentHighest: ClassVar[AsmToken.TokenKind]
        PercentLo: ClassVar[AsmToken.TokenKind]
        PercentNeg: ClassVar[AsmToken.TokenKind]
        PercentPcrel_Hi: ClassVar[AsmToken.TokenKind]
        PercentPcrel_Lo: ClassVar[AsmToken.TokenKind]
        PercentTlsgd: ClassVar[AsmToken.TokenKind]
        PercentTlsldm: ClassVar[AsmToken.TokenKind]
        PercentTprel_Hi: ClassVar[AsmToken.TokenKind]
        PercentTprel_Lo: ClassVar[AsmToken.TokenKind]
        Pipe: ClassVar[AsmToken.TokenKind]
        PipePipe: ClassVar[AsmToken.TokenKind]
        Plus: ClassVar[AsmToken.TokenKind]
        RBrac: ClassVar[AsmToken.TokenKind]
        RCurly: ClassVar[AsmToken.TokenKind]
        RParen: ClassVar[AsmToken.TokenKind]
        Real: ClassVar[AsmToken.TokenKind]
        Slash: ClassVar[AsmToken.TokenKind]
        Space: ClassVar[AsmToken.TokenKind]
        Star: ClassVar[AsmToken.TokenKind]
        String: ClassVar[AsmToken.TokenKind]
        Tilde: ClassVar[AsmToken.TokenKind]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: AsmToken.TokenKind) -> int:
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

    @overload
    def __init__(self) -> None:
        pass

    @overload
    def __init__(self, Kind: AsmToken.TokenKind, Str: str, IntVal: int) -> None:
        pass

    def getEndLoc(self) -> SMLoc:
        pass

    def getIdentifier(self) -> str:
        pass

    def getIntVal(self) -> int:
        pass

    def getKind(self) -> AsmToken.TokenKind:
        pass

    def getLoc(self) -> SMLoc:
        pass

    def getString(self) -> str:
        pass

    def getStringContents(self) -> str:
        pass

    def isNot(self, K: AsmToken.TokenKind) -> bool:
        pass
