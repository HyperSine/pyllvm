#include <llvm/ADT/StringRef.h>
#include <llvm/MC/MCTargetOptions.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct enum_pybinder_t<llvm::ExceptionHandling> : pybinder_t {
        using binding_t = py::enum_<llvm::ExceptionHandling>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.ExceptionHandling"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "ExceptionHandling" }
                .value("Null", llvm::ExceptionHandling::None)           // None is a keyword reserved by Python, use `Null` instead
                .value("DwarfCFI", llvm::ExceptionHandling::DwarfCFI)
                .value("SjLj", llvm::ExceptionHandling::SjLj)
                .value("ARM", llvm::ExceptionHandling::ARM)
                .value("WinEH", llvm::ExceptionHandling::WinEH)
                .value("Wasm", llvm::ExceptionHandling::Wasm)
                .value("AIX", llvm::ExceptionHandling::AIX);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::DebugCompressionType> : pybinder_t {
        using binding_t = py::enum_<llvm::DebugCompressionType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.DebugCompressionType"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "DebugCompressionType" }
                .value("Null", llvm::DebugCompressionType::None)    // None is a keyword reserved by Python, use `Null` instead
                .value("Z", llvm::DebugCompressionType::Z);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::EmitDwarfUnwindType> : pybinder_t {
        using binding_t = py::enum_<llvm::EmitDwarfUnwindType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.EmitDwarfUnwindType"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "EmitDwarfUnwindType" }
                .value("Always", llvm::EmitDwarfUnwindType::Always)
                .value("NoCompactUnwind", llvm::EmitDwarfUnwindType::NoCompactUnwind)
                .value("Default", llvm::EmitDwarfUnwindType::Default);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::MCTargetOptions> : pybinder_t {
        using binding_t = py::class_<llvm::MCTargetOptions>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCTargetOptions"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCTargetOptions" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCTargetOptions").cast<binding_t>()
                .def(py::init())
                .def_property(
                    "MCRelaxAll",
                    [](llvm::MCTargetOptions& self) -> bool { return self.MCRelaxAll; },
                    [](llvm::MCTargetOptions& self, bool v) { self.MCRelaxAll = v; }
                )
                .def_property(
                    "MCNoExecStack",
                    [](llvm::MCTargetOptions& self) -> bool { return self.MCNoExecStack; },
                    [](llvm::MCTargetOptions& self, bool v) { self.MCNoExecStack = v; }
                )
                .def_property(
                    "MCFatalWarnings",
                    [](llvm::MCTargetOptions& self) -> bool { return self.MCFatalWarnings; },
                    [](llvm::MCTargetOptions& self, bool v) { self.MCFatalWarnings = v; }
                )
                .def_property(
                    "MCNoWarn",
                    [](llvm::MCTargetOptions& self) -> bool { return self.MCNoWarn; },
                    [](llvm::MCTargetOptions& self, bool v) { self.MCNoWarn = v; }
                )
                .def_property(
                    "MCNoDeprecatedWarn",
                    [](llvm::MCTargetOptions& self) -> bool { return self.MCNoDeprecatedWarn; },
                    [](llvm::MCTargetOptions& self, bool v) { self.MCNoDeprecatedWarn = v; }
                )
                .def_property(
                    "MCNoTypeCheck",
                    [](llvm::MCTargetOptions& self) -> bool { return self.MCNoTypeCheck; },
                    [](llvm::MCTargetOptions& self, bool v) { self.MCNoTypeCheck = v; }
                )
                .def_property(
                    "MCSaveTempLabels",
                    [](llvm::MCTargetOptions& self) -> bool { return self.MCSaveTempLabels; },
                    [](llvm::MCTargetOptions& self, bool v) { self.MCSaveTempLabels = v; }
                )
                .def_property(
                    "MCUseDwarfDirectory",
                    [](llvm::MCTargetOptions& self) -> llvm::MCTargetOptions::DwarfDirectory { return self.MCUseDwarfDirectory; },
                    [](llvm::MCTargetOptions& self, llvm::MCTargetOptions::DwarfDirectory v) { self.MCUseDwarfDirectory = v; }
                )
                .def_property(
                    "MCIncrementalLinkerCompatible",
                    [](llvm::MCTargetOptions& self) -> bool { return self.MCIncrementalLinkerCompatible; },
                    [](llvm::MCTargetOptions& self, bool v) { self.MCIncrementalLinkerCompatible = v; }
                )
                .def_property(
                    "ShowMCEncoding",
                    [](llvm::MCTargetOptions& self) -> bool { return self.ShowMCEncoding; },
                    [](llvm::MCTargetOptions& self, bool v) { self.ShowMCEncoding = v; }
                )
                .def_property(
                    "ShowMCInst",
                    [](llvm::MCTargetOptions& self) -> bool { return self.ShowMCInst; },
                    [](llvm::MCTargetOptions& self, bool v) { self.ShowMCInst = v; }
                )
                .def_property(
                    "AsmVerbose",
                    [](llvm::MCTargetOptions& self) -> bool { return self.AsmVerbose; },
                    [](llvm::MCTargetOptions& self, bool v) { self.AsmVerbose = v; }
                )
                .def_property(
                    "PreserveAsmComments",
                    [](llvm::MCTargetOptions& self) -> bool { return self.PreserveAsmComments; },
                    [](llvm::MCTargetOptions& self, bool v) { self.PreserveAsmComments = v; }
                )
                .def_property(
                    "Dwarf64",
                    [](llvm::MCTargetOptions& self) -> bool { return self.Dwarf64; },
                    [](llvm::MCTargetOptions& self, bool v) { self.Dwarf64 = v; }
                )
                .def_property(
                    "EmitDwarfUnwind",
                    [](llvm::MCTargetOptions& self) -> llvm::EmitDwarfUnwindType { return self.EmitDwarfUnwind; },
                    [](llvm::MCTargetOptions& self, llvm::EmitDwarfUnwindType v) { self.EmitDwarfUnwind = v; }
                )
                .def_property(
                    "DwarfVersion",
                    [](llvm::MCTargetOptions& self) -> int { return self.DwarfVersion; },
                    [](llvm::MCTargetOptions& self, int v) { self.DwarfVersion = v; }
                )
                .def_property(
                    "ABIName",
                    [](llvm::MCTargetOptions& self) -> std::string_view { return self.ABIName; },
                    [](llvm::MCTargetOptions& self, std::string_view v) { self.ABIName = v; }
                )
                .def_property(
                    "AssemblyLanguage",
                    [](llvm::MCTargetOptions& self) -> std::string_view { return self.AssemblyLanguage; },
                    [](llvm::MCTargetOptions& self, std::string_view v) { self.AssemblyLanguage = v; }
                )
                .def_property(
                    "SplitDwarfFile",
                    [](llvm::MCTargetOptions& self) -> std::string_view { return self.SplitDwarfFile; },
                    [](llvm::MCTargetOptions& self, std::string_view v) { self.SplitDwarfFile = v; }
                )
                .def("getABIName", &llvm::MCTargetOptions::getABIName)
                .def("getAssemblyLanguage", &llvm::MCTargetOptions::getAssemblyLanguage);
        }
    };

    template<>
    struct enum_pybinder_t<llvm::MCTargetOptions::AsmInstrumentation> : pybinder_t {
        using binding_t = py::enum_<llvm::MCTargetOptions::AsmInstrumentation>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCTargetOptions.AsmInstrumentation"sv;
        static_assert(class_pybinder_t<llvm::MCTargetOptions>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("MCTargetOptions"), "AsmInstrumentation" }
                .value("Null", llvm::MCTargetOptions::AsmInstrumentation::AsmInstrumentationNone)   // None is a keyword reserved by Python, use `Null` instead
                .value("Address", llvm::MCTargetOptions::AsmInstrumentation::AsmInstrumentationAddress);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::MCTargetOptions::DwarfDirectory> : pybinder_t {
        using binding_t = py::enum_<llvm::MCTargetOptions::DwarfDirectory>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCTargetOptions.DwarfDirectory"sv;
        static_assert(class_pybinder_t<llvm::MCTargetOptions>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("MCTargetOptions"), "DwarfDirectory" }
                .value("Disable", llvm::MCTargetOptions::DwarfDirectory::DisableDwarfDirectory)
                .value("Enable", llvm::MCTargetOptions::DwarfDirectory::EnableDwarfDirectory)
                .value("Default", llvm::MCTargetOptions::DwarfDirectory::DefaultDwarfDirectory);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    static enum_pybinder_t<llvm::ExceptionHandling> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::DebugCompressionType> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::EmitDwarfUnwindType> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::MCTargetOptions> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCTargetOptions::AsmInstrumentation> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCTargetOptions::DwarfDirectory> PYLLVM_UNIQUE_NAME(_);
}
