#include <llvm/MC/MCInst.h>
#include <llvm/MC/MCInstrAnalysis.h>
#include <llvm/MC/MCInstPrinter.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCInstPrinter> : pybinder_t {
        using binding_t = py::class_<llvm::MCInstPrinter>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCInstPrinter"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCInstPrinter" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCInstPrinter").cast<binding_t>()
                .def("applyTargetSpecificCLOption", &llvm::MCInstPrinter::applyTargetSpecificCLOption, py::arg("Opt"))
                //.def("setCommentStream", &llvm::MCInstPrinter::setCommentStream)
                .def("getMnemonic", &llvm::MCInstPrinter::getMnemonic, py::arg("MI"))
                //.def("printInst", &llvm::MCInstPrinter::printInst)
                .def("getOpcodeName", &llvm::MCInstPrinter::getOpcodeName)
                //.def("printRegName", &llvm::MCInstPrinter::printRegName)
                .def_property(
                    "UseMarkup",
                    &llvm::MCInstPrinter::getUseMarkup,
                    &llvm::MCInstPrinter::setUseMarkup
                )
                .def("markup", &llvm::MCInstPrinter::markup, py::arg("s"))
                .def_property(
                    "PrintImmHex",
                    &llvm::MCInstPrinter::getPrintImmHex,
                    &llvm::MCInstPrinter::setPrintImmHex
                )
                //.def("setPrintHexStyle", &llvm::MCInstPrinter::setPrintHexStyle)
                .def("setPrintBranchImmAsAddress", &llvm::MCInstPrinter::setPrintBranchImmAsAddress)
                .def("setSymbolizeOperands", &llvm::MCInstPrinter::setSymbolizeOperands)
                .def("setMCInstrAnalysis", &llvm::MCInstPrinter::setMCInstrAnalysis, py::arg("Value"), py::keep_alive<1, 2>())
                //.def("formatImm", &llvm::MCInstPrinter::formatImm)
                //.def("formatDec", &llvm::MCInstPrinter::formatDec)
                //.def("formatHex", &llvm::MCInstPrinter::formatHex)
                //.def("formatHex", &llvm::MCInstPrinter::formatHex)
                ;
        }
    };

    template<>
    struct class_pybinder_t<llvm::PatternsForOpcode> : pybinder_t {
        using binding_t = py::class_<llvm::PatternsForOpcode>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.PatternsForOpcode"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "PatternsForOpcode" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("PatternsForOpcode").cast<binding_t>()
                .def(py::init<>())
                .def_readwrite("Opcode", &llvm::PatternsForOpcode::Opcode)
                .def_readwrite("PatternStart", &llvm::PatternsForOpcode::PatternStart)
                .def_readwrite("NumPatterns", &llvm::PatternsForOpcode::NumPatterns);
        }
    };

    template<>
    struct class_pybinder_t<llvm::AliasPattern> : pybinder_t {
        using binding_t = py::class_<llvm::AliasPattern>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.AliasPattern"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "AliasPattern" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("AliasPattern").cast<binding_t>()
                .def(py::init<>())
                .def_readwrite("AsmStrOffset", &llvm::AliasPattern::AsmStrOffset)
                .def_readwrite("AliasCondStart", &llvm::AliasPattern::AliasCondStart)
                .def_readwrite("NumOperands", &llvm::AliasPattern::NumOperands)
                .def_readwrite("NumConds", &llvm::AliasPattern::NumConds);
        }
    };

    template<>
    struct class_pybinder_t<llvm::AliasPatternCond> : pybinder_t {
        using binding_t = py::class_<llvm::AliasPatternCond>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.AliasPatternCond"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "AliasPatternCond" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("AliasPatternCond").cast<binding_t>()
                .def(py::init<>())
                .def_readwrite("Kind", &llvm::AliasPatternCond::Kind)
                .def_readwrite("Value", &llvm::AliasPatternCond::Value);
        }
    };

    template<>
    struct enum_pybinder_t<llvm::AliasPatternCond::CondKind> : pybinder_t {
        using binding_t = py::enum_<llvm::AliasPatternCond::CondKind>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.AliasPatternCond.CondKind"sv;
        static_assert(class_pybinder_t<llvm::AliasPatternCond>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("AliasPatternCond"), "CondKind" }
                .value("Feature", llvm::AliasPatternCond::CondKind::K_Feature)
                .value("NegFeature", llvm::AliasPatternCond::CondKind::K_NegFeature)
                .value("OrFeature", llvm::AliasPatternCond::CondKind::K_OrFeature)
                .value("OrNegFeature", llvm::AliasPatternCond::CondKind::K_OrNegFeature)
                .value("EndOrFeatures", llvm::AliasPatternCond::CondKind::K_EndOrFeatures)
                .value("Ignore", llvm::AliasPatternCond::CondKind::K_Ignore)
                .value("Reg", llvm::AliasPatternCond::CondKind::K_Reg)
                .value("TiedReg", llvm::AliasPatternCond::CondKind::K_TiedReg)
                .value("Imm", llvm::AliasPatternCond::CondKind::K_Imm)
                .value("RegClass", llvm::AliasPatternCond::CondKind::K_RegClass)
                .value("Custom", llvm::AliasPatternCond::CondKind::K_Custom);
        }

        virtual void make_binding(py::module_& m) override {}
    };

//    template<>
//    struct class_pybinder_t<llvm::AliasMatchingData>;

    static class_pybinder_t<llvm::MCInstPrinter> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::PatternsForOpcode> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::AliasPattern> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::AliasPatternCond> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::AliasPatternCond::CondKind> PYLLVM_UNIQUE_NAME(_);
    // static class_pybinder_t<llvm::AliasMatchingData> PYLLVM_UNIQUE_NAME(_);
}
