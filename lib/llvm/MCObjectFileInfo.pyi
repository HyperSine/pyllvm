from typing import overload
from .MCContext import MCContext
from .MCSection import MCSection

class MCObjectFileInfo:

    def getAddrSigSection(self) -> MCSection:
        pass

    def getBBAddrMapSection(self, arg0: MCSection) -> MCSection:
        pass

    def getBSSSection(self) -> MCSection:
        pass

    def getCOFFDebugSymbolsSection(self) -> MCSection:
        pass

    def getCOFFDebugTypesSection(self) -> MCSection:
        pass

    def getCOFFGlobalTypeHashesSection(self) -> MCSection:
        pass

    def getCStringSection(self) -> MCSection:
        pass

    def getCommDirectiveSupportsAlignment(self) -> bool:
        pass

    def getCompactUnwindDwarfEHFrameOnly(self) -> int:
        pass

    def getCompactUnwindSection(self) -> MCSection:
        pass

    def getConstDataCoalSection(self) -> MCSection:
        pass

    def getConstDataSection(self) -> MCSection:
        pass

    def getConstTextCoalSection(self) -> MCSection:
        pass

    def getContext(self) -> MCContext:
        pass

    def getDataBSSSection(self) -> MCSection:
        pass

    def getDataCoalSection(self) -> MCSection:
        pass

    def getDataCommonSection(self) -> MCSection:
        pass

    def getDataRelROSection(self) -> MCSection:
        pass

    def getDataSection(self) -> MCSection:
        pass

    def getDrectveSection(self) -> MCSection:
        pass

    def getDwarfARangesSection(self) -> MCSection:
        pass

    def getDwarfAbbrevDWOSection(self) -> MCSection:
        pass

    def getDwarfAbbrevSection(self) -> MCSection:
        pass

    def getDwarfAccelNamesSection(self) -> MCSection:
        pass

    def getDwarfAccelNamespaceSection(self) -> MCSection:
        pass

    def getDwarfAccelObjCSection(self) -> MCSection:
        pass

    def getDwarfAccelTypesSection(self) -> MCSection:
        pass

    def getDwarfCUIndexSection(self) -> MCSection:
        pass

    def getDwarfDebugInlineSection(self) -> MCSection:
        pass

    def getDwarfDebugNamesSection(self) -> MCSection:
        pass

    def getDwarfFrameSection(self) -> MCSection:
        pass

    def getDwarfGnuPubNamesSection(self) -> MCSection:
        pass

    def getDwarfGnuPubTypesSection(self) -> MCSection:
        pass

    def getDwarfInfoDWOSection(self) -> MCSection:
        pass

    @overload
    def getDwarfInfoSection(self) -> MCSection:
        pass

    @overload
    def getDwarfInfoSection(self, Hash: int) -> MCSection:
        pass

    def getDwarfLineDWOSection(self) -> MCSection:
        pass

    def getDwarfLineSection(self) -> MCSection:
        pass

    def getDwarfLineStrSection(self) -> MCSection:
        pass

    def getDwarfLocDWOSection(self) -> MCSection:
        pass

    def getDwarfLocSection(self) -> MCSection:
        pass

    def getDwarfLoclistsDWOSection(self) -> MCSection:
        pass

    def getDwarfLoclistsSection(self) -> MCSection:
        pass

    def getDwarfMacinfoDWOSection(self) -> MCSection:
        pass

    def getDwarfMacinfoSection(self) -> MCSection:
        pass

    def getDwarfMacroDWOSection(self) -> MCSection:
        pass

    def getDwarfMacroSection(self) -> MCSection:
        pass

    def getDwarfPubNamesSection(self) -> MCSection:
        pass

    def getDwarfPubTypesSection(self) -> MCSection:
        pass

    def getDwarfRangesSection(self) -> MCSection:
        pass

    def getDwarfRnglistsSection(self) -> MCSection:
        pass

    def getDwarfStrDWOSection(self) -> MCSection:
        pass

    def getDwarfStrOffDWOSection(self) -> MCSection:
        pass

    def getDwarfStrOffSection(self) -> MCSection:
        pass

    def getDwarfStrSection(self) -> MCSection:
        pass

    def getDwarfSwiftASTSection(self) -> MCSection:
        pass

    def getDwarfTUIndexSection(self) -> MCSection:
        pass

    def getDwarfTypesDWOSection(self) -> MCSection:
        pass

    def getDwarfTypesSection(self, Hash: int) -> MCSection:
        pass

    def getEHFrameSection(self) -> MCSection:
        pass

    def getEightByteConstantSection(self) -> MCSection:
        pass

    def getFDEEncoding(self) -> int:
        pass

    def getFaultMapSection(self) -> MCSection:
        pass

    def getFourByteConstantSection(self) -> MCSection:
        pass

    def getGEHContSection(self) -> MCSection:
        pass

    def getGFIDsSection(self) -> MCSection:
        pass

    def getGIATsSection(self) -> MCSection:
        pass

    def getGLJMPSection(self) -> MCSection:
        pass

    def getLSDASection(self) -> MCSection:
        pass

    def getLazySymbolPointerSection(self) -> MCSection:
        pass

    def getMergeableConst16Section(self) -> MCSection:
        pass

    def getMergeableConst32Section(self) -> MCSection:
        pass

    def getMergeableConst4Section(self) -> MCSection:
        pass

    def getMergeableConst8Section(self) -> MCSection:
        pass

    def getNonLazySymbolPointerSection(self) -> MCSection:
        pass

    def getOmitDwarfIfHaveCompactUnwind(self) -> bool:
        pass

    def getPDataSection(self) -> MCSection:
        pass

    def getPPA1Section(self) -> MCSection:
        pass

    def getPseudoProbeDescSection(self, arg0: str) -> MCSection:
        pass

    def getPseudoProbeSection(self, arg0: MCSection) -> MCSection:
        pass

    def getReadOnlySection(self) -> MCSection:
        pass

    def getRemarksSection(self) -> MCSection:
        pass

    def getSXDataSection(self) -> MCSection:
        pass

    def getSixteenByteConstantSection(self) -> MCSection:
        pass

    def getStackMapSection(self) -> MCSection:
        pass

    def getStackSizesSection(self, arg0: MCSection) -> MCSection:
        pass

    def getSupportsCompactUnwindWithoutEHFrame(self) -> bool:
        pass

    def getSupportsWeakOmittedEHFrame(self) -> bool:
        pass

    def getTLSBSSSection(self) -> MCSection:
        pass

    def getTLSDataSection(self) -> MCSection:
        pass

    def getTLSExtraDataSection(self) -> MCSection:
        pass

    def getTLSTLVSection(self) -> MCSection:
        pass

    def getTLSThreadInitSection(self) -> MCSection:
        pass

    def getTOCBaseSection(self) -> MCSection:
        pass

    def getTextCoalSection(self) -> MCSection:
        pass

    def getTextSection(self) -> MCSection:
        pass

    def getTextSectionAlignment(self) -> int:
        pass

    def getThreadLocalPointerSection(self) -> MCSection:
        pass

    def getUStringSection(self) -> MCSection:
        pass

    def getXDataSection(self) -> MCSection:
        pass

    def isPositionIndependent(self) -> bool:
        pass
