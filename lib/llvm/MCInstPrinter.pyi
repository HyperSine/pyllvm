from typing import Tuple
from .MCInst import MCInst
from .MCInstrAnalysis import MCInstrAnalysis

class MCInstPrinter:

    @property
    def PrintImmHex(arg0: MCInstPrinter) -> bool:
        pass

    @PrintImmHex.setter
    def PrintImmHex(arg0: MCInstPrinter, arg1: bool) -> None:
        pass

    @property
    def UseMarkup(arg0: MCInstPrinter) -> bool:
        pass

    @UseMarkup.setter
    def UseMarkup(arg0: MCInstPrinter, arg1: bool) -> None:
        pass

    def applyTargetSpecificCLOption(self, Opt: str) -> bool:
        pass

    def getMnemonic(self, MI: MCInst) -> Tuple[str, int]:
        pass

    def getOpcodeName(self, arg0: int) -> str:
        pass

    def markup(self, s: str) -> str:
        pass

    def setMCInstrAnalysis(self, Value: MCInstrAnalysis) -> None:
        pass

    def setPrintBranchImmAsAddress(self, arg0: bool) -> None:
        pass

    def setSymbolizeOperands(self, arg0: bool) -> None:
        pass
