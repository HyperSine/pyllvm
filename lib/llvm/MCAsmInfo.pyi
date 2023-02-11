from typing import Any, ClassVar, Tuple
from .DebugCompressionType import DebugCompressionType
from .MCSection import MCSection

class MCAsmInfo:

    class AsmCharLiteralSyntax:

        SingleQuotePrefix: ClassVar[MCAsmInfo.AsmCharLiteralSyntax]
        Unknown: ClassVar[MCAsmInfo.AsmCharLiteralSyntax]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: MCAsmInfo.AsmCharLiteralSyntax) -> int:
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

    def avoidWeakIfComdat(self) -> bool:
        pass

    def binutilsIsAtLeast(self, Major: int, Minor: int) -> bool:
        pass

    def canRelaxRelocations(self) -> bool:
        pass

    def characterLiteralSyntax(self) -> MCAsmInfo.AsmCharLiteralSyntax:
        pass

    def compressDebugSections(self) -> DebugCompressionType:
        pass

    def doDwarfFDESymbolsUseAbsDiff(self) -> bool:
        pass

    def doesAllowAtAtStartOfIdentifier(self) -> bool:
        pass

    def doesAllowAtInName(self) -> bool:
        pass

    def doesAllowDollarAtStartOfIdentifier(self) -> bool:
        pass

    def doesAllowHashAtStartOfIdentifier(self) -> bool:
        pass

    def doesAllowQuestionAtStartOfIdentifier(self) -> bool:
        pass

    def doesDwarfUseRelocationsAcrossSections(self) -> bool:
        pass

    def doesSetDirectiveSuppressReloc(self) -> bool:
        pass

    def doesSupportDataRegionDirectives(self) -> bool:
        pass

    def doesSupportDebugInformation(self) -> bool:
        pass

    def doesUseCFIForDebug(self) -> bool:
        pass

    def doesZeroDirectiveSupportNonZeroValue(self) -> bool:
        pass

    def getAlignmentIsInBytes(self) -> bool:
        pass

    def getAsciiDirective(self) -> str:
        pass

    def getAscizDirective(self) -> str:
        pass

    def getAssemblerDialect(self) -> int:
        pass

    def getByteListDirective(self) -> str:
        pass

    def getCOMMDirectiveAlignmentIsInBytes(self) -> bool:
        pass

    def getCalleeSaveStackSlotSize(self) -> int:
        pass

    def getCode16Directive(self) -> str:
        pass

    def getCode32Directive(self) -> str:
        pass

    def getCode64Directive(self) -> str:
        pass

    def getCodePointerSize(self) -> int:
        pass

    def getCommentColumn(self) -> int:
        pass

    def getCommentString(self) -> str:
        pass

    def getDTPRel32Directive(self) -> str:
        pass

    def getDTPRel64Directive(self) -> str:
        pass

    def getData16bitsDirective(self) -> str:
        pass

    def getData32bitsDirective(self) -> str:
        pass

    def getData64bitsDirective(self) -> str:
        pass

    def getData8bitsDirective(self) -> str:
        pass

    def getDollarIsPC(self) -> bool:
        pass

    def getDotIsPC(self) -> bool:
        pass

    def getEmitGNUAsmStartIndentationMarker(self) -> bool:
        pass

    def getGPRel32Directive(self) -> str:
        pass

    def getGPRel64Directive(self) -> str:
        pass

    def getGlobalDirective(self) -> str:
        pass

    def getInlineAsmEnd(self) -> str:
        pass

    def getInlineAsmStart(self) -> str:
        pass

    def getLabelSuffix(self) -> str:
        pass

    def getLinkerPrivateGlobalPrefix(self) -> str:
        pass

    def getMinInstAlignment(self) -> int:
        pass

    def getPlainStringDirective(self) -> str:
        pass

    def getPrivateGlobalPrefix(self) -> str:
        pass

    def getPrivateLabelPrefix(self) -> str:
        pass

    def getRestrictCommentStringToStartOfStatement(self) -> bool:
        pass

    def getSeparatorString(self) -> str:
        pass

    def getStarIsPC(self) -> bool:
        pass

    def getTPRel32Directive(self) -> str:
        pass

    def getTPRel64Directive(self) -> str:
        pass

    def getTextAlignFillValue(self) -> int:
        pass

    def getWeakDirective(self) -> str:
        pass

    def getWeakRefDirective(self) -> str:
        pass

    def getZeroDirective(self) -> str:
        pass

    def hasAggressiveSymbolFolding(self) -> bool:
        pass

    def hasAltEntry(self) -> bool:
        pass

    def hasBasenameOnlyForFileDirective(self) -> bool:
        pass

    def hasCOFFAssociativeComdats(self) -> bool:
        pass

    def hasCOFFComdatConstants(self) -> bool:
        pass

    def hasDotTypeDotSizeDirective(self) -> bool:
        pass

    def hasFourStringsDotFile(self) -> bool:
        pass

    def hasFunctionAlignment(self) -> bool:
        pass

    def hasIdentDirective(self) -> bool:
        pass

    def hasLEB128Directives(self) -> bool:
        pass

    def hasLinkerPrivateGlobalPrefix(self) -> bool:
        pass

    def hasMachoTBSSDirective(self) -> bool:
        pass

    def hasMachoZeroFillDirective(self) -> bool:
        pass

    def hasMipsExpressions(self) -> bool:
        pass

    def hasNoDeadStrip(self) -> bool:
        pass

    def hasPairedDoubleQuoteStringConstants(self) -> bool:
        pass

    def hasSingleParameterDotFile(self) -> bool:
        pass

    def hasSubsectionsViaSymbols(self) -> bool:
        pass

    def hasVisibilityOnlyWithLinkage(self) -> bool:
        pass

    def hasWeakDefCanBeHiddenDirective(self) -> bool:
        pass

    def hasWeakDefDirective(self) -> bool:
        pass

    def isAcceptableChar(self, C: str) -> bool:
        pass

    def isLittleEndian(self) -> bool:
        pass

    def isSectionAtomizableBySymbols(self, arg0: MCSection) -> bool:
        pass

    def isStackGrowthDirectionUp(self) -> bool:
        pass

    def needsDwarfSectionOffsetDirective(self) -> bool:
        pass

    def needsDwarfSectionSizeInHeader(self) -> bool:
        pass

    def needsFunctionDescriptors(self) -> bool:
        pass

    def needsLocalForSize(self) -> bool:
        pass

    def parseInlineAsmUsingAsmParser(self) -> bool:
        pass

    def preserveAsmComments(self) -> bool:
        pass

    def setBinutilsVersion(self, arg0: Tuple[int, int]) -> None:
        pass

    def setCompressDebugSections(self, arg0: DebugCompressionType) -> None:
        pass

    def setRelaxELFRelocations(self, V: bool) -> None:
        pass

    def shouldAllowAdditionalComments(self) -> bool:
        pass

    def shouldEmitLabelsInUpperCase(self) -> bool:
        pass

    def shouldUseLogicalShr(self) -> bool:
        pass

    def shouldUseMotorolaIntegers(self) -> bool:
        pass

    def supportsExtendedDwarfLocDirective(self) -> bool:
        pass

    def supportsNameQuoting(self) -> bool:
        pass

    def supportsSignedData(self) -> bool:
        pass

    def useAssignmentForEHBegin(self) -> bool:
        pass

    def useDotAlignForAlignment(self) -> bool:
        pass

    def useDwarfRegNumForCFI(self) -> bool:
        pass

    def useIntegratedAssembler(self) -> bool:
        pass

    def useParensForSymbolVariant(self) -> bool:
        pass

    def usesCFIForEH(self) -> bool:
        pass

    def usesDwarfFileAndLocDirectives(self) -> bool:
        pass

    def usesELFSectionDirectiveForBSS(self) -> bool:
        pass

    def usesSunStyleELFSectionSwitchSyntax(self) -> bool:
        pass

    def usesWindowsCFI(self) -> bool:
        pass
