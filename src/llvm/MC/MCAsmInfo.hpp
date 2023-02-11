#include <llvm/MC/MCAsmInfo.h>
#include <llvm/MC/MCSection.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCAsmInfo> : pybinder_t {
        using binding_t = py::class_<llvm::MCAsmInfo>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmInfo"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCAsmInfo" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCAsmInfo").cast<binding_t>()
                .def("getCodePointerSize", &llvm::MCAsmInfo::getCodePointerSize)
                .def("getCalleeSaveStackSlotSize", &llvm::MCAsmInfo::getCalleeSaveStackSlotSize)
                .def("isLittleEndian", &llvm::MCAsmInfo::isLittleEndian)
                .def("isStackGrowthDirectionUp", &llvm::MCAsmInfo::isStackGrowthDirectionUp)
                .def("hasSubsectionsViaSymbols", &llvm::MCAsmInfo::hasSubsectionsViaSymbols)
                .def("getData8bitsDirective", &llvm::MCAsmInfo::getData8bitsDirective)
                .def("getData16bitsDirective", &llvm::MCAsmInfo::getData16bitsDirective)
                .def("getData32bitsDirective", &llvm::MCAsmInfo::getData32bitsDirective)
                .def("getData64bitsDirective", &llvm::MCAsmInfo::getData64bitsDirective)
                .def("supportsSignedData", &llvm::MCAsmInfo::supportsSignedData)
                .def("getGPRel32Directive", &llvm::MCAsmInfo::getGPRel32Directive)
                .def("getGPRel64Directive", &llvm::MCAsmInfo::getGPRel64Directive)
                .def("getDTPRel32Directive", &llvm::MCAsmInfo::getDTPRel32Directive)
                .def("getDTPRel64Directive", &llvm::MCAsmInfo::getDTPRel64Directive)
                .def("getTPRel32Directive", &llvm::MCAsmInfo::getTPRel32Directive)
                .def("getTPRel64Directive", &llvm::MCAsmInfo::getTPRel64Directive)
                //.def("getNonexecutableStackSection", &llvm::MCAsmInfo::getNonexecutableStackSection)
                .def("isSectionAtomizableBySymbols", &llvm::MCAsmInfo::isSectionAtomizableBySymbols)
                //.def("getExprForPersonalitySymbol", &llvm::MCAsmInfo::getExprForPersonalitySymbol)
                //.def("getExprForFDESymbol", &llvm::MCAsmInfo::getExprForFDESymbol)
                .def("isAcceptableChar", &llvm::MCAsmInfo::isAcceptableChar, py::arg("C"))
                //.def("isValidUnquotedName", &llvm::MCAsmInfo::isValidUnquotedName)
                //.def("shouldOmitSectionDirective", &llvm::MCAsmInfo::shouldOmitSectionDirective)
                .def("usesSunStyleELFSectionSwitchSyntax", &llvm::MCAsmInfo::usesSunStyleELFSectionSwitchSyntax)
                .def("usesELFSectionDirectiveForBSS", &llvm::MCAsmInfo::usesELFSectionDirectiveForBSS)
                .def("needsDwarfSectionOffsetDirective", &llvm::MCAsmInfo::needsDwarfSectionOffsetDirective)
                .def("hasMachoZeroFillDirective", &llvm::MCAsmInfo::hasMachoZeroFillDirective)
                .def("hasMachoTBSSDirective", &llvm::MCAsmInfo::hasMachoTBSSDirective)
                .def("hasCOFFAssociativeComdats", &llvm::MCAsmInfo::hasCOFFAssociativeComdats)
                .def("hasCOFFComdatConstants", &llvm::MCAsmInfo::hasCOFFComdatConstants)
                .def("hasVisibilityOnlyWithLinkage", &llvm::MCAsmInfo::hasVisibilityOnlyWithLinkage)
                //.def("getMaxInstLength", &llvm::MCAsmInfo::getMaxInstLength)
                .def("getMinInstAlignment", &llvm::MCAsmInfo::getMinInstAlignment)
                .def("getDollarIsPC", &llvm::MCAsmInfo::getDollarIsPC)
                .def("getDotIsPC", &llvm::MCAsmInfo::getDotIsPC)
                .def("getStarIsPC", &llvm::MCAsmInfo::getStarIsPC)
                .def("getSeparatorString", &llvm::MCAsmInfo::getSeparatorString)
                .def("getCommentColumn", &llvm::MCAsmInfo::getCommentColumn)
                .def("getCommentString", &llvm::MCAsmInfo::getCommentString)
                .def("getRestrictCommentStringToStartOfStatement", &llvm::MCAsmInfo::getRestrictCommentStringToStartOfStatement)
                .def("shouldAllowAdditionalComments", &llvm::MCAsmInfo::shouldAllowAdditionalComments)
                .def("getEmitGNUAsmStartIndentationMarker", &llvm::MCAsmInfo::getEmitGNUAsmStartIndentationMarker)
                .def("getLabelSuffix", &llvm::MCAsmInfo::getLabelSuffix)
                .def("shouldEmitLabelsInUpperCase", &llvm::MCAsmInfo::shouldEmitLabelsInUpperCase)
                .def("useAssignmentForEHBegin", &llvm::MCAsmInfo::useAssignmentForEHBegin)
                .def("needsLocalForSize", &llvm::MCAsmInfo::needsLocalForSize)
                .def("getPrivateGlobalPrefix", &llvm::MCAsmInfo::getPrivateGlobalPrefix)
                .def("getPrivateLabelPrefix", &llvm::MCAsmInfo::getPrivateLabelPrefix)
                .def("hasLinkerPrivateGlobalPrefix", &llvm::MCAsmInfo::hasLinkerPrivateGlobalPrefix)
                .def("getLinkerPrivateGlobalPrefix", &llvm::MCAsmInfo::getLinkerPrivateGlobalPrefix)
                .def("getInlineAsmStart", &llvm::MCAsmInfo::getInlineAsmStart)
                .def("getInlineAsmEnd", &llvm::MCAsmInfo::getInlineAsmEnd)
                .def("getCode16Directive", &llvm::MCAsmInfo::getCode16Directive)
                .def("getCode32Directive", &llvm::MCAsmInfo::getCode32Directive)
                .def("getCode64Directive", &llvm::MCAsmInfo::getCode64Directive)
                .def("getAssemblerDialect", &llvm::MCAsmInfo::getAssemblerDialect)
                .def("doesAllowAtInName", &llvm::MCAsmInfo::doesAllowAtInName)
                .def("doesAllowQuestionAtStartOfIdentifier", &llvm::MCAsmInfo::doesAllowQuestionAtStartOfIdentifier)
                .def("doesAllowAtAtStartOfIdentifier", &llvm::MCAsmInfo::doesAllowAtAtStartOfIdentifier)
                .def("doesAllowDollarAtStartOfIdentifier", &llvm::MCAsmInfo::doesAllowDollarAtStartOfIdentifier)
                .def("doesAllowHashAtStartOfIdentifier", &llvm::MCAsmInfo::doesAllowHashAtStartOfIdentifier)
                .def("supportsNameQuoting", &llvm::MCAsmInfo::supportsNameQuoting)
                .def("doesSupportDataRegionDirectives", &llvm::MCAsmInfo::doesSupportDataRegionDirectives)
                .def("useDotAlignForAlignment", &llvm::MCAsmInfo::useDotAlignForAlignment)
                .def("hasLEB128Directives", &llvm::MCAsmInfo::hasLEB128Directives)
                .def("getZeroDirective", &llvm::MCAsmInfo::getZeroDirective)
                .def("doesZeroDirectiveSupportNonZeroValue", &llvm::MCAsmInfo::doesZeroDirectiveSupportNonZeroValue)
                .def("getAsciiDirective", &llvm::MCAsmInfo::getAsciiDirective)
                .def("getAscizDirective", &llvm::MCAsmInfo::getAscizDirective)
                .def("getByteListDirective", &llvm::MCAsmInfo::getByteListDirective)
                .def("getPlainStringDirective", &llvm::MCAsmInfo::getPlainStringDirective)
                .def("characterLiteralSyntax", &llvm::MCAsmInfo::characterLiteralSyntax)
                .def("getAlignmentIsInBytes", &llvm::MCAsmInfo::getAlignmentIsInBytes)
                .def("getTextAlignFillValue", &llvm::MCAsmInfo::getTextAlignFillValue)
                .def("getGlobalDirective", &llvm::MCAsmInfo::getGlobalDirective)
                .def("doesSetDirectiveSuppressReloc", &llvm::MCAsmInfo::doesSetDirectiveSuppressReloc)
                .def("hasAggressiveSymbolFolding", &llvm::MCAsmInfo::hasAggressiveSymbolFolding)
                .def("getCOMMDirectiveAlignmentIsInBytes", &llvm::MCAsmInfo::getCOMMDirectiveAlignmentIsInBytes)
                //.def("getLCOMMDirectiveAlignmentType", &llvm::MCAsmInfo::getLCOMMDirectiveAlignmentType)
                .def("hasBasenameOnlyForFileDirective", &llvm::MCAsmInfo::hasBasenameOnlyForFileDirective)
                .def("hasPairedDoubleQuoteStringConstants", &llvm::MCAsmInfo::hasPairedDoubleQuoteStringConstants)
                .def("hasFunctionAlignment", &llvm::MCAsmInfo::hasFunctionAlignment)
                .def("hasDotTypeDotSizeDirective", &llvm::MCAsmInfo::hasDotTypeDotSizeDirective)
                .def("hasSingleParameterDotFile", &llvm::MCAsmInfo::hasSingleParameterDotFile)
                .def("hasFourStringsDotFile", &llvm::MCAsmInfo::hasFourStringsDotFile)
                .def("hasIdentDirective", &llvm::MCAsmInfo::hasIdentDirective)
                .def("hasNoDeadStrip", &llvm::MCAsmInfo::hasNoDeadStrip)
                .def("hasAltEntry", &llvm::MCAsmInfo::hasAltEntry)
                .def("getWeakDirective", &llvm::MCAsmInfo::getWeakDirective)
                .def("getWeakRefDirective", &llvm::MCAsmInfo::getWeakRefDirective)
                .def("hasWeakDefDirective", &llvm::MCAsmInfo::hasWeakDefDirective)
                .def("hasWeakDefCanBeHiddenDirective", &llvm::MCAsmInfo::hasWeakDefCanBeHiddenDirective)
                .def("avoidWeakIfComdat", &llvm::MCAsmInfo::avoidWeakIfComdat)
                //.def("getHiddenVisibilityAttr", &llvm::MCAsmInfo::getHiddenVisibilityAttr)
                //.def("getHiddenDeclarationVisibilityAttr", &llvm::MCAsmInfo::getHiddenDeclarationVisibilityAttr)
                //.def("getProtectedVisibilityAttr", &llvm::MCAsmInfo::getProtectedVisibilityAttr)
                .def("doesSupportDebugInformation", &llvm::MCAsmInfo::doesSupportDebugInformation)
                //.def("getExceptionHandlingType", &llvm::MCAsmInfo::getExceptionHandlingType)
                //.def("getWinEHEncodingType", &llvm::MCAsmInfo::getWinEHEncodingType)
                //.def("setExceptionsType", &llvm::MCAsmInfo::setExceptionsType)
                .def("doesUseCFIForDebug", &llvm::MCAsmInfo::doesUseCFIForDebug)
                .def("usesCFIForEH", &llvm::MCAsmInfo::usesCFIForEH)
                .def("usesWindowsCFI", &llvm::MCAsmInfo::usesWindowsCFI)
                .def("doesDwarfUseRelocationsAcrossSections", &llvm::MCAsmInfo::doesDwarfUseRelocationsAcrossSections)
                .def("doDwarfFDESymbolsUseAbsDiff", &llvm::MCAsmInfo::doDwarfFDESymbolsUseAbsDiff)
                .def("useDwarfRegNumForCFI", &llvm::MCAsmInfo::useDwarfRegNumForCFI)
                .def("useParensForSymbolVariant", &llvm::MCAsmInfo::useParensForSymbolVariant)
                .def("supportsExtendedDwarfLocDirective", &llvm::MCAsmInfo::supportsExtendedDwarfLocDirective)
                .def("usesDwarfFileAndLocDirectives", &llvm::MCAsmInfo::usesDwarfFileAndLocDirectives)
                .def("needsDwarfSectionSizeInHeader", &llvm::MCAsmInfo::needsDwarfSectionSizeInHeader)
                //.def("addInitialFrameState", &llvm::MCAsmInfo::addInitialFrameState)
                //.def("getInitialFrameState", &llvm::MCAsmInfo::getInitialFrameState)
                .def("setBinutilsVersion", &llvm::MCAsmInfo::setBinutilsVersion)
                .def("useIntegratedAssembler", &llvm::MCAsmInfo::useIntegratedAssembler)
                .def("parseInlineAsmUsingAsmParser", &llvm::MCAsmInfo::parseInlineAsmUsingAsmParser)
                .def("binutilsIsAtLeast", &llvm::MCAsmInfo::binutilsIsAtLeast, py::arg("Major"), py::arg("Minor"))
                //.def("setUseIntegratedAssembler", &llvm::MCAsmInfo::setUseIntegratedAssembler)
                //.def("setParseInlineAsmUsingAsmParser", &llvm::MCAsmInfo::setParseInlineAsmUsingAsmParser)
                .def("preserveAsmComments", &llvm::MCAsmInfo::preserveAsmComments)
                //.def("setPreserveAsmComments", &llvm::MCAsmInfo::setPreserveAsmComments)
                .def("compressDebugSections", &llvm::MCAsmInfo::compressDebugSections)
                .def("setCompressDebugSections", &llvm::MCAsmInfo::setCompressDebugSections)
                .def("shouldUseLogicalShr", &llvm::MCAsmInfo::shouldUseLogicalShr)
                .def("canRelaxRelocations", &llvm::MCAsmInfo::canRelaxRelocations)
                .def("setRelaxELFRelocations", &llvm::MCAsmInfo::setRelaxELFRelocations, py::arg("V"))
                .def("hasMipsExpressions", &llvm::MCAsmInfo::hasMipsExpressions)
                .def("needsFunctionDescriptors", &llvm::MCAsmInfo::needsFunctionDescriptors)
                .def("shouldUseMotorolaIntegers", &llvm::MCAsmInfo::shouldUseMotorolaIntegers);
        }
    };

    template<>
    struct enum_pybinder_t<llvm::MCAsmInfo::AsmCharLiteralSyntax> : pybinder_t {
        using binding_t = py::enum_<llvm::MCAsmInfo::AsmCharLiteralSyntax>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmInfo.AsmCharLiteralSyntax"sv;
        static_assert(class_pybinder_t<llvm::MCAsmInfo>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("MCAsmInfo"), "AsmCharLiteralSyntax" }
                .value("Unknown", llvm::MCAsmInfo::AsmCharLiteralSyntax::ACLS_Unknown)
                .value("SingleQuotePrefix", llvm::MCAsmInfo::AsmCharLiteralSyntax::ACLS_SingleQuotePrefix);
        }

        virtual void make_binding(py::module_& m) override {}
    };
}
