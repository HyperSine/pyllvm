#include <llvm/MC/MCAsmInfo.h>
#include <llvm/MC/MCContext.h>
#include <llvm/MC/MCObjectFileInfo.h>
#include <llvm/MC/MCRegisterInfo.h>
#include <llvm/MC/MCSectionMachO.h>
#include <llvm/MC/MCSubtargetInfo.h>
#include <llvm/MC/MCSymbol.h>
#include <llvm/MC/MCTargetOptions.h>
#include <llvm/Support/SourceMgr.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCContext> : pybinder_t {
        using binding_t = py::class_<llvm::MCContext>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCContext"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCContext" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCContext").cast<binding_t>()
                .def(
                    py::init<const llvm::Triple&, const llvm::MCAsmInfo*, const llvm::MCRegisterInfo*, const llvm::MCSubtargetInfo*, const llvm::SourceMgr*, const llvm::MCTargetOptions*, bool, llvm::StringRef>(),
                    py::arg("TheTriple"),
                    py::arg("MAI"),
                    py::arg("MRI"),
                    py::arg("MSTI"),
                    py::arg("Mgr") = nullptr,
                    py::arg("TargetOpts") = nullptr,
                    py::arg("DoAutoReset") = true,
                    py::arg("Swift5ReflSegmentName") = llvm::StringRef{},
                    py::keep_alive<1, 3>(),
                    py::keep_alive<1, 4>(),
                    py::keep_alive<1, 5>(),
                    py::keep_alive<1, 6>(),
                    py::keep_alive<1, 7>(),
                    py::keep_alive<1, 9>()
                )
                .def("getObjectFileType", &llvm::MCContext::getObjectFileType)
                .def("getSwift5ReflectionSegmentName", &llvm::MCContext::getSwift5ReflectionSegmentName, py::return_value_policy::copy)
                .def("getTargetTriple", &llvm::MCContext::getTargetTriple, py::return_value_policy::reference_internal)
                .def("getSourceManager", &llvm::MCContext::getSourceManager, py::return_value_policy::reference_internal)
                .def("initInlineSourceManager", &llvm::MCContext::initInlineSourceManager)
                .def("getInlineSourceManager", &llvm::MCContext::getInlineSourceManager, py::return_value_policy::reference_internal)
                //.def("getLocInfos", &llvm::MCContext::getLocInfos)
                //.def("setDiagnosticHandler", &llvm::MCContext::setDiagnosticHandler)
                //.def("setObjectFileInfo", &llvm::MCContext::setObjectFileInfo, py::keep_alive<1, 2>())      // todo: need pybind11 feature https://github.com/pybind/pybind11/pull/3291
                .def("getAsmInfo", &llvm::MCContext::getAsmInfo, py::return_value_policy::reference_internal)
                .def("getRegisterInfo", &llvm::MCContext::getRegisterInfo, py::return_value_policy::reference_internal)
                .def("getObjectFileInfo", &llvm::MCContext::getObjectFileInfo, py::return_value_policy::reference_internal)
                .def("getSubtargetInfo", &llvm::MCContext::getSubtargetInfo, py::return_value_policy::reference_internal)
                //.def("getCVContext", &llvm::MCContext::getCVContext)
                .def("setAllowTemporaryLabels", &llvm::MCContext::setAllowTemporaryLabels)
                .def("setUseNamesOnTempLabels", &llvm::MCContext::setUseNamesOnTempLabels)
                .def("reset", &llvm::MCContext::reset)
                .def("createMCInst", &llvm::MCContext::createMCInst, py::return_value_policy::reference_internal)
                .def("createLinkerPrivateTempSymbol", &llvm::MCContext::createLinkerPrivateTempSymbol, py::return_value_policy::reference_internal)
                .def("createTempSymbol", py::overload_cast<>(&llvm::MCContext::createTempSymbol), py::return_value_policy::reference_internal)
                .def(
                    "createTempSymbol",
                    [](llvm::MCContext& ctx, std::string_view name, bool always_add_suffix) {
                        return ctx.createTempSymbol(name, always_add_suffix);
                    },
                    py::return_value_policy::reference_internal,
                    py::arg("Name"),
                    py::arg("AlwaysAddSuffix") = true
                )
                .def("createNamedTempSymbol", py::overload_cast<>(&llvm::MCContext::createNamedTempSymbol), py::return_value_policy::reference_internal)
                .def(
                    "createNamedTempSymbol",
                    [](llvm::MCContext& ctx, std::string_view name) {
                        return ctx.createNamedTempSymbol(name);
                    },
                    py::return_value_policy::reference_internal,
                    py::arg("Name")
                )
                .def("createDirectionalLocalSymbol", &llvm::MCContext::createDirectionalLocalSymbol, py::return_value_policy::reference_internal)
                .def("getDirectionalLocalSymbol", &llvm::MCContext::getDirectionalLocalSymbol, py::return_value_policy::reference_internal)
                //.def("getOrCreateSymbol", &llvm::MCContext::getOrCreateSymbol)
                //.def("getOrCreateFrameAllocSymbol", &llvm::MCContext::getOrCreateFrameAllocSymbol)
                //.def("getOrCreateParentFrameOffsetSymbol", &llvm::MCContext::getOrCreateParentFrameOffsetSymbol)
                //.def("getOrCreateLSDASymbol", &llvm::MCContext::getOrCreateLSDASymbol)
                //.def("lookupSymbol", &llvm::MCContext::lookupSymbol)
                //.def("setSymbolValue", &llvm::MCContext::setSymbolValue)
                //.def("getSymbols", &llvm::MCContext::getSymbols)
                //.def("getInlineAsmLabel", &llvm::MCContext::getInlineAsmLabel)
                //.def("registerInlineAsmLabel", &llvm::MCContext::registerInlineAsmLabel)
                .def(
                    "getMachOSection",
                    py::overload_cast<llvm::StringRef, llvm::StringRef, unsigned, unsigned, llvm::SectionKind, const char*>(&llvm::MCContext::getMachOSection),
                    py::return_value_policy::reference_internal,
                    py::arg("Segment"),
                    py::arg("Section"),
                    py::arg("TypeAndAttributes"),
                    py::arg("Reserved2"),
                    py::arg("K"),
                    py::arg("BeginSymName") = nullptr
                )
                .def(
                    "getMachOSection",
                    py::overload_cast<llvm::StringRef, llvm::StringRef, unsigned, llvm::SectionKind, const char*>(&llvm::MCContext::getMachOSection),
                    py::return_value_policy::reference_internal,
                    py::arg("Segment"),
                    py::arg("Section"),
                    py::arg("TypeAndAttributes"),
                    py::arg("K"),
                    py::arg("BeginSymName") = nullptr
                )
                //.def("getELFSection", &llvm::MCContext::getELFSection)
                //.def("getELFSection", &llvm::MCContext::getELFSection)
                //.def("getELFSection", &llvm::MCContext::getELFSection)
                //.def("getELFSection", &llvm::MCContext::getELFSection)
                //.def("getELFSection", &llvm::MCContext::getELFSection)
                //.def("getELFNamedSection", &llvm::MCContext::getELFNamedSection)
                //.def("createELFRelSection", &llvm::MCContext::createELFRelSection)
                //.def("renameELFSection", &llvm::MCContext::renameELFSection)
                //.def("createELFGroupSection", &llvm::MCContext::createELFGroupSection)
                //.def("recordELFMergeableSectionInfo", &llvm::MCContext::recordELFMergeableSectionInfo)
                //.def("isELFImplicitMergeableSectionNamePrefix", &llvm::MCContext::isELFImplicitMergeableSectionNamePrefix)
                //.def("isELFGenericMergeableSection", &llvm::MCContext::isELFGenericMergeableSection)
                //.def("getELFUniqueIDForEntsize", &llvm::MCContext::getELFUniqueIDForEntsize)
                //.def("getGOFFSection", &llvm::MCContext::getGOFFSection)
                //.def("getCOFFSection", &llvm::MCContext::getCOFFSection)
                //.def("getCOFFSection", &llvm::MCContext::getCOFFSection)
                //.def("getAssociativeCOFFSection", &llvm::MCContext::getAssociativeCOFFSection)
                //.def("getWasmSection", &llvm::MCContext::getWasmSection)
                //.def("getWasmSection", &llvm::MCContext::getWasmSection)
                //.def("getWasmSection", &llvm::MCContext::getWasmSection)
                //.def("getWasmSection", &llvm::MCContext::getWasmSection)
                //.def("getWasmSection", &llvm::MCContext::getWasmSection)
                //.def("getXCOFFSection", &llvm::MCContext::getXCOFFSection)
                //.def("getSubtargetCopy", &llvm::MCContext::getSubtargetCopy)
                //.def("getCompilationDir", &llvm::MCContext::getCompilationDir)
                //.def("setCompilationDir", &llvm::MCContext::setCompilationDir)
                //.def("addDebugPrefixMapEntry", &llvm::MCContext::addDebugPrefixMapEntry)
                //.def("RemapDebugPaths", &llvm::MCContext::RemapDebugPaths)
                //.def("getMainFileName", &llvm::MCContext::getMainFileName)
                //.def("setMainFileName", &llvm::MCContext::setMainFileName)
                //.def("getDwarfFile", &llvm::MCContext::getDwarfFile)
                //.def("isValidDwarfFileNumber", &llvm::MCContext::isValidDwarfFileNumber)
                //.def("getMCDwarfLineTables", &llvm::MCContext::getMCDwarfLineTables)
                //.def("getMCDwarfLineTable", &llvm::MCContext::getMCDwarfLineTable)
                //.def("getMCDwarfFiles", &llvm::MCContext::getMCDwarfFiles)
                //.def("getMCDwarfDirs", &llvm::MCContext::getMCDwarfDirs)
                .def("getDwarfCompileUnitID", &llvm::MCContext::getDwarfCompileUnitID)
                .def("setDwarfCompileUnitID", &llvm::MCContext::setDwarfCompileUnitID)
                //.def("setMCLineTableRootFile", &llvm::MCContext::setMCLineTableRootFile)
                .def("isDwarfMD5UsageConsistent", &llvm::MCContext::isDwarfMD5UsageConsistent)
                .def("setCurrentDwarfLoc", &llvm::MCContext::setCurrentDwarfLoc)
                .def("clearDwarfLocSeen", &llvm::MCContext::clearDwarfLocSeen)
                .def("getDwarfLocSeen", &llvm::MCContext::getDwarfLocSeen)
                //.def("getCurrentDwarfLoc", &llvm::MCContext::getCurrentDwarfLoc)
                .def("getGenDwarfForAssembly", &llvm::MCContext::getGenDwarfForAssembly)
                .def("setGenDwarfForAssembly", &llvm::MCContext::setGenDwarfForAssembly)
                .def("getGenDwarfFileNumber", &llvm::MCContext::getGenDwarfFileNumber)
                .def("setGenDwarfFileNumber", &llvm::MCContext::setGenDwarfFileNumber)
                //.def("setGenDwarfRootFile", &llvm::MCContext::setGenDwarfRootFile)`
                //.def("getGenDwarfSectionSyms", &llvm::MCContext::getGenDwarfSectionSyms)
                //.def("addGenDwarfSection", &llvm::MCContext::addGenDwarfSection)
                //.def("finalizeDwarfSections", &llvm::MCContext::finalizeDwarfSections)
                //.def("getMCGenDwarfLabelEntries", &llvm::MCContext::getMCGenDwarfLabelEntries)
                //.def("addMCGenDwarfLabelEntry", &llvm::MCContext::addMCGenDwarfLabelEntry)
                .def("setDwarfDebugFlags", &llvm::MCContext::setDwarfDebugFlags)
                .def("setDwarfDebugProducer", &llvm::MCContext::setDwarfDebugProducer)
                //.def("setDwarfFormat", &llvm::MCContext::setDwarfFormat)
                .def("setDwarfVersion", &llvm::MCContext::setDwarfVersion, py::arg("v"))
                .def("getSecureLogFile", &llvm::MCContext::getSecureLogFile)
                //.def("setSecureLog", &llvm::MCContext::setSecureLog)
                .def("getSecureLogUsed", &llvm::MCContext::getSecureLogUsed)
                .def("setSecureLogUsed", &llvm::MCContext::setSecureLogUsed)
                //.def("allocate", &llvm::MCContext::allocate)
                //.def("deallocate", &llvm::MCContext::deallocate)
                .def("hadError", &llvm::MCContext::hadError)
                //.def("diagnose", &llvm::MCContext::diagnose)
                //.def("reportError", &llvm::MCContext::reportError)
                //.def("reportWarning", &llvm::MCContext::reportWarning)
                .def("lookupMacro", &llvm::MCContext::lookupMacro)
                .def("defineMacro", &llvm::MCContext::defineMacro)
                .def("undefineMacro", &llvm::MCContext::undefineMacro)
                //.def("getMCPseudoProbeTable", &llvm::MCContext::getMCPseudoProbeTable)
                ;
        }
    };

    template<>
    struct enum_pybinder_t<llvm::MCContext::Environment> : pybinder_t {
        using binding_t = py::enum_<llvm::MCContext::Environment>;
        
        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCContext.Environment"sv;
        static_assert(class_pybinder_t<llvm::MCContext>::binder_identifier < binder_identifier);
        
        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("MCContext"), "Environment" }
                .value("IsMachO", llvm::MCContext::Environment::IsMachO)
                .value("IsELF", llvm::MCContext::Environment::IsELF)
                .value("IsGOFF", llvm::MCContext::Environment::IsGOFF)
                .value("IsCOFF", llvm::MCContext::Environment::IsCOFF)
                .value("IsWasm", llvm::MCContext::Environment::IsWasm)
                .value("IsXCOFF", llvm::MCContext::Environment::IsXCOFF);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    static class_pybinder_t<llvm::MCContext> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCContext::Environment> PYLLVM_UNIQUE_NAME(_);
}
