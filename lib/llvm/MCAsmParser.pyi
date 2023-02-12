from .AsmToken import AsmToken
from .MCAsmLexer import MCAsmLexer
from .MCContext import MCContext
from .MCStreamer import MCStreamer
from .SMLoc import SMLoc
from .SourceMgr import SourceMgr

class MCAsmParser:

    def Run(self, NoInitialTextSection: bool, NoFinalize: bool = False) -> bool:
        pass

    def addAliasForDirective(self, Directive: str, Alias: str) -> None:
        pass

    def checkForValidSection(self) -> bool:
        pass

    def clearPendingErrors(self) -> None:
        pass

    def eatToEndOfStatement(self) -> None:
        pass

    def getAssemblerDialect(self) -> int:
        pass

    def getContext(self) -> MCContext:
        pass

    def getLexer(self) -> MCAsmLexer:
        pass

    def getShowParsedOperands(self) -> bool:
        pass

    def getSourceManager(self) -> SourceMgr:
        pass

    def getStreamer(self) -> MCStreamer:
        pass

    def hasPendingError(self) -> bool:
        pass

    def isParsingMSInlineAsm(self) -> bool:
        pass

    def isParsingMasm(self) -> bool:
        pass

    def parseComma(self) -> bool:
        pass

    def parseOptionalToken(self, T: AsmToken.TokenKind) -> bool:
        pass

    def parseRParen(self) -> bool:
        pass

    def parseStringToEndOfStatement(self) -> str:
        pass

    def parseTokenLoc(self, arg0: SMLoc) -> bool:
        pass

    def printPendingErrors(self) -> bool:
        pass

    def setAssemblerDialect(self, i: int) -> None:
        pass

    def setParsingMSInlineAsm(self, V: bool) -> None:
        pass

    def setShowParsedOperands(self, Value: bool) -> None:
        pass
