#include <llvm/MC/MCContext.h>
#include <llvm/MC/MCObjectFileInfo.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCObjectFileInfo> : pybinder_t {
        using binding_t = py::class_<llvm::MCObjectFileInfo>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCObjectFileInfo"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCObjectFileInfo" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCObjectFileInfo").cast<binding_t>()
                .def("getContext", &llvm::MCObjectFileInfo::getContext, py::return_value_policy::reference_internal)
                .def("getSupportsWeakOmittedEHFrame", &llvm::MCObjectFileInfo::getSupportsWeakOmittedEHFrame)
                .def("getSupportsCompactUnwindWithoutEHFrame", &llvm::MCObjectFileInfo::getSupportsCompactUnwindWithoutEHFrame)
                .def("getOmitDwarfIfHaveCompactUnwind", &llvm::MCObjectFileInfo::getOmitDwarfIfHaveCompactUnwind)
                .def("getCommDirectiveSupportsAlignment", &llvm::MCObjectFileInfo::getCommDirectiveSupportsAlignment)
                .def("getFDEEncoding", &llvm::MCObjectFileInfo::getFDEEncoding)
                .def("getCompactUnwindDwarfEHFrameOnly", &llvm::MCObjectFileInfo::getCompactUnwindDwarfEHFrameOnly)
                .def("getTextSectionAlignment", &llvm::MCObjectFileInfo::getTextSectionAlignment)
                .def("getTextSection", &llvm::MCObjectFileInfo::getTextSection, py::return_value_policy::reference_internal)
                .def("getDataSection", &llvm::MCObjectFileInfo::getDataSection, py::return_value_policy::reference_internal)
                .def("getBSSSection", &llvm::MCObjectFileInfo::getBSSSection, py::return_value_policy::reference_internal)
                .def("getReadOnlySection", &llvm::MCObjectFileInfo::getReadOnlySection, py::return_value_policy::reference_internal)
                .def("getLSDASection", &llvm::MCObjectFileInfo::getLSDASection, py::return_value_policy::reference_internal)
                .def("getCompactUnwindSection", &llvm::MCObjectFileInfo::getCompactUnwindSection, py::return_value_policy::reference_internal)
                .def("getDwarfAbbrevSection", &llvm::MCObjectFileInfo::getDwarfAbbrevSection, py::return_value_policy::reference_internal)
                .def("getDwarfInfoSection", py::overload_cast<>(&llvm::MCObjectFileInfo::getDwarfInfoSection, py::const_), py::return_value_policy::reference_internal)
                .def("getDwarfInfoSection", py::overload_cast<uint64_t>(&llvm::MCObjectFileInfo::getDwarfInfoSection, py::const_), py::return_value_policy::reference_internal, py::arg("Hash"))
                .def("getDwarfLineSection", &llvm::MCObjectFileInfo::getDwarfLineSection, py::return_value_policy::reference_internal)
                .def("getDwarfLineStrSection", &llvm::MCObjectFileInfo::getDwarfLineStrSection, py::return_value_policy::reference_internal)
                .def("getDwarfFrameSection", &llvm::MCObjectFileInfo::getDwarfFrameSection, py::return_value_policy::reference_internal)
                .def("getDwarfPubNamesSection", &llvm::MCObjectFileInfo::getDwarfPubNamesSection, py::return_value_policy::reference_internal)
                .def("getDwarfPubTypesSection", &llvm::MCObjectFileInfo::getDwarfPubTypesSection, py::return_value_policy::reference_internal)
                .def("getDwarfGnuPubNamesSection", &llvm::MCObjectFileInfo::getDwarfGnuPubNamesSection, py::return_value_policy::reference_internal)
                .def("getDwarfGnuPubTypesSection", &llvm::MCObjectFileInfo::getDwarfGnuPubTypesSection, py::return_value_policy::reference_internal)
                .def("getDwarfDebugInlineSection", &llvm::MCObjectFileInfo::getDwarfDebugInlineSection, py::return_value_policy::reference_internal)
                .def("getDwarfStrSection", &llvm::MCObjectFileInfo::getDwarfStrSection, py::return_value_policy::reference_internal)
                .def("getDwarfLocSection", &llvm::MCObjectFileInfo::getDwarfLocSection, py::return_value_policy::reference_internal)
                .def("getDwarfARangesSection", &llvm::MCObjectFileInfo::getDwarfARangesSection, py::return_value_policy::reference_internal)
                .def("getDwarfRangesSection", &llvm::MCObjectFileInfo::getDwarfRangesSection, py::return_value_policy::reference_internal)
                .def("getDwarfRnglistsSection", &llvm::MCObjectFileInfo::getDwarfRnglistsSection, py::return_value_policy::reference_internal)
                .def("getDwarfLoclistsSection", &llvm::MCObjectFileInfo::getDwarfLoclistsSection, py::return_value_policy::reference_internal)
                .def("getDwarfMacinfoSection", &llvm::MCObjectFileInfo::getDwarfMacinfoSection, py::return_value_policy::reference_internal)
                .def("getDwarfMacroSection", &llvm::MCObjectFileInfo::getDwarfMacroSection, py::return_value_policy::reference_internal)
                .def("getDwarfDebugNamesSection", &llvm::MCObjectFileInfo::getDwarfDebugNamesSection, py::return_value_policy::reference_internal)
                .def("getDwarfAccelNamesSection", &llvm::MCObjectFileInfo::getDwarfAccelNamesSection, py::return_value_policy::reference_internal)
                .def("getDwarfAccelObjCSection", &llvm::MCObjectFileInfo::getDwarfAccelObjCSection, py::return_value_policy::reference_internal)
                .def("getDwarfAccelNamespaceSection", &llvm::MCObjectFileInfo::getDwarfAccelNamespaceSection, py::return_value_policy::reference_internal)
                .def("getDwarfAccelTypesSection", &llvm::MCObjectFileInfo::getDwarfAccelTypesSection, py::return_value_policy::reference_internal)
                .def("getDwarfInfoDWOSection", &llvm::MCObjectFileInfo::getDwarfInfoDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfTypesSection", &llvm::MCObjectFileInfo::getDwarfTypesSection, py::return_value_policy::reference_internal, py::arg("Hash"))
                .def("getDwarfTypesDWOSection", &llvm::MCObjectFileInfo::getDwarfTypesDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfAbbrevDWOSection", &llvm::MCObjectFileInfo::getDwarfAbbrevDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfStrDWOSection", &llvm::MCObjectFileInfo::getDwarfStrDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfLineDWOSection", &llvm::MCObjectFileInfo::getDwarfLineDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfLocDWOSection", &llvm::MCObjectFileInfo::getDwarfLocDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfStrOffDWOSection", &llvm::MCObjectFileInfo::getDwarfStrOffDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfStrOffSection", &llvm::MCObjectFileInfo::getDwarfStrOffSection, py::return_value_policy::reference_internal)
                .def("getDwarfLoclistsDWOSection", &llvm::MCObjectFileInfo::getDwarfLoclistsDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfMacroDWOSection", &llvm::MCObjectFileInfo::getDwarfMacroDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfMacinfoDWOSection", &llvm::MCObjectFileInfo::getDwarfMacinfoDWOSection, py::return_value_policy::reference_internal)
                .def("getDwarfCUIndexSection", &llvm::MCObjectFileInfo::getDwarfCUIndexSection, py::return_value_policy::reference_internal)
                .def("getDwarfTUIndexSection", &llvm::MCObjectFileInfo::getDwarfTUIndexSection, py::return_value_policy::reference_internal)
                .def("getDwarfSwiftASTSection", &llvm::MCObjectFileInfo::getDwarfSwiftASTSection, py::return_value_policy::reference_internal)
                .def("getCOFFDebugSymbolsSection", &llvm::MCObjectFileInfo::getCOFFDebugSymbolsSection, py::return_value_policy::reference_internal)
                .def("getCOFFDebugTypesSection", &llvm::MCObjectFileInfo::getCOFFDebugTypesSection, py::return_value_policy::reference_internal)
                .def("getCOFFGlobalTypeHashesSection", &llvm::MCObjectFileInfo::getCOFFGlobalTypeHashesSection, py::return_value_policy::reference_internal)
                .def("getTLSExtraDataSection", &llvm::MCObjectFileInfo::getTLSExtraDataSection, py::return_value_policy::reference_internal)
                .def("getTLSDataSection", &llvm::MCObjectFileInfo::getTLSDataSection, py::return_value_policy::reference_internal)
                .def("getTLSBSSSection", &llvm::MCObjectFileInfo::getTLSBSSSection, py::return_value_policy::reference_internal)
                .def("getStackMapSection", &llvm::MCObjectFileInfo::getStackMapSection, py::return_value_policy::reference_internal)
                .def("getFaultMapSection", &llvm::MCObjectFileInfo::getFaultMapSection, py::return_value_policy::reference_internal)
                .def("getRemarksSection", &llvm::MCObjectFileInfo::getRemarksSection, py::return_value_policy::reference_internal)
                .def("getStackSizesSection", &llvm::MCObjectFileInfo::getStackSizesSection, py::return_value_policy::reference_internal)
                .def("getBBAddrMapSection", &llvm::MCObjectFileInfo::getBBAddrMapSection, py::return_value_policy::reference_internal)
                .def("getPseudoProbeSection", &llvm::MCObjectFileInfo::getPseudoProbeSection, py::return_value_policy::reference_internal)
                .def("getPseudoProbeDescSection", &llvm::MCObjectFileInfo::getPseudoProbeDescSection, py::return_value_policy::reference_internal)
                .def("getDataRelROSection", &llvm::MCObjectFileInfo::getDataRelROSection, py::return_value_policy::reference_internal)
                .def("getMergeableConst4Section", &llvm::MCObjectFileInfo::getMergeableConst4Section, py::return_value_policy::reference_internal)
                .def("getMergeableConst8Section", &llvm::MCObjectFileInfo::getMergeableConst8Section, py::return_value_policy::reference_internal)
                .def("getMergeableConst16Section", &llvm::MCObjectFileInfo::getMergeableConst16Section, py::return_value_policy::reference_internal)
                .def("getMergeableConst32Section", &llvm::MCObjectFileInfo::getMergeableConst32Section, py::return_value_policy::reference_internal)
                .def("getTLSTLVSection", &llvm::MCObjectFileInfo::getTLSTLVSection, py::return_value_policy::reference_internal)
                .def("getTLSThreadInitSection", &llvm::MCObjectFileInfo::getTLSThreadInitSection, py::return_value_policy::reference_internal)
                .def("getCStringSection", &llvm::MCObjectFileInfo::getCStringSection, py::return_value_policy::reference_internal)
                .def("getUStringSection", &llvm::MCObjectFileInfo::getUStringSection, py::return_value_policy::reference_internal)
                .def("getTextCoalSection", &llvm::MCObjectFileInfo::getTextCoalSection, py::return_value_policy::reference_internal)
                .def("getConstTextCoalSection", &llvm::MCObjectFileInfo::getConstTextCoalSection, py::return_value_policy::reference_internal)
                .def("getConstDataSection", &llvm::MCObjectFileInfo::getConstDataSection, py::return_value_policy::reference_internal)
                .def("getDataCoalSection", &llvm::MCObjectFileInfo::getDataCoalSection, py::return_value_policy::reference_internal)
                .def("getConstDataCoalSection", &llvm::MCObjectFileInfo::getConstDataCoalSection, py::return_value_policy::reference_internal)
                .def("getDataCommonSection", &llvm::MCObjectFileInfo::getDataCommonSection, py::return_value_policy::reference_internal)
                .def("getDataBSSSection", &llvm::MCObjectFileInfo::getDataBSSSection, py::return_value_policy::reference_internal)
                .def("getFourByteConstantSection", &llvm::MCObjectFileInfo::getFourByteConstantSection, py::return_value_policy::reference_internal)
                .def("getEightByteConstantSection", &llvm::MCObjectFileInfo::getEightByteConstantSection, py::return_value_policy::reference_internal)
                .def("getSixteenByteConstantSection", &llvm::MCObjectFileInfo::getSixteenByteConstantSection, py::return_value_policy::reference_internal)
                .def("getLazySymbolPointerSection", &llvm::MCObjectFileInfo::getLazySymbolPointerSection, py::return_value_policy::reference_internal)
                .def("getNonLazySymbolPointerSection", &llvm::MCObjectFileInfo::getNonLazySymbolPointerSection, py::return_value_policy::reference_internal)
                .def("getThreadLocalPointerSection", &llvm::MCObjectFileInfo::getThreadLocalPointerSection, py::return_value_policy::reference_internal)
                .def("getAddrSigSection", &llvm::MCObjectFileInfo::getAddrSigSection, py::return_value_policy::reference_internal)
                .def("getDrectveSection", &llvm::MCObjectFileInfo::getDrectveSection, py::return_value_policy::reference_internal)
                .def("getPDataSection", &llvm::MCObjectFileInfo::getPDataSection, py::return_value_policy::reference_internal)
                .def("getXDataSection", &llvm::MCObjectFileInfo::getXDataSection, py::return_value_policy::reference_internal)
                .def("getSXDataSection", &llvm::MCObjectFileInfo::getSXDataSection, py::return_value_policy::reference_internal)
                .def("getGEHContSection", &llvm::MCObjectFileInfo::getGEHContSection, py::return_value_policy::reference_internal)
                .def("getGFIDsSection", &llvm::MCObjectFileInfo::getGFIDsSection, py::return_value_policy::reference_internal)
                .def("getGIATsSection", &llvm::MCObjectFileInfo::getGIATsSection, py::return_value_policy::reference_internal)
                .def("getGLJMPSection", &llvm::MCObjectFileInfo::getGLJMPSection, py::return_value_policy::reference_internal)
                .def("getPPA1Section", &llvm::MCObjectFileInfo::getPPA1Section, py::return_value_policy::reference_internal)
                .def("getTOCBaseSection", &llvm::MCObjectFileInfo::getTOCBaseSection, py::return_value_policy::reference_internal)
                .def("getEHFrameSection", &llvm::MCObjectFileInfo::getEHFrameSection, py::return_value_policy::reference_internal)
                .def("isPositionIndependent", &llvm::MCObjectFileInfo::isPositionIndependent)
                //.def("getSwift5ReflectionSection", &llvm::MCObjectFileInfo::getSwift5ReflectionSection, py::return_value_policy::reference_internal)
                //.def("setSDKVersion", &llvm::MCObjectFileInfo::setSDKVersion)
                //.def("getSDKVersion", &llvm::MCObjectFileInfo::getSDKVersion)
                //.def("setDarwinTargetVariantTriple", &llvm::MCObjectFileInfo::setDarwinTargetVariantTriple)
                //.def("getDarwinTargetVariantTriple", &llvm::MCObjectFileInfo::getDarwinTargetVariantTriple)
                //.def("setDarwinTargetVariantSDKVersion", &llvm::MCObjectFileInfo::setDarwinTargetVariantSDKVersion)
                //.def("getDarwinTargetVariantSDKVersion", &llvm::MCObjectFileInfo::getDarwinTargetVariantSDKVersion)
                ;
        }
    };

    static class_pybinder_t<llvm::MCObjectFileInfo> PYLLVM_UNIQUE_NAME(_);
}
