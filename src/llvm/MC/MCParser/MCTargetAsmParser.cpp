#include <llvm/MC/MCParser/MCTargetAsmParser.h>
#include "MCAsmParserExtension.hpp"
#include "../../../init.hpp"
#include "../../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct enum_pybinder_t<llvm::AsmRewriteKind> : pybinder_t {
        using binding_t = py::enum_<llvm::AsmRewriteKind>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.AsmRewriteKind"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "AsmRewriteKind" }
                .value("Align", llvm::AsmRewriteKind::AOK_Align)
                .value("Even", llvm::AsmRewriteKind::AOK_EVEN)
                .value("Emit", llvm::AsmRewriteKind::AOK_Emit)
                .value("CallInput", llvm::AsmRewriteKind::AOK_CallInput)
                .value("Input", llvm::AsmRewriteKind::AOK_Input)
                .value("Output", llvm::AsmRewriteKind::AOK_Output)
                .value("SizeDirective", llvm::AsmRewriteKind::AOK_SizeDirective)
                .value("Label", llvm::AsmRewriteKind::AOK_Label)
                .value("EndOfStatement", llvm::AsmRewriteKind::AOK_EndOfStatement)
                .value("Skip", llvm::AsmRewriteKind::AOK_Skip)
                .value("IntelExpr", llvm::AsmRewriteKind::AOK_IntelExpr);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::IntelExpr> : pybinder_t {
        using binding_t = py::class_<llvm::IntelExpr>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.IntelExpr"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "IntelExpr" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("IntelExpr").cast<binding_t>()
                // todo: bind struct fields as readonly property
                //.def(py::init<>())
                //.def(py::init<...>())
                .def("hasBaseReg", &llvm::IntelExpr::hasBaseReg)
                .def("hasIndexReg", &llvm::IntelExpr::hasIndexReg)
                .def("hasRegs", &llvm::IntelExpr::hasRegs)
                .def("hasOffset", &llvm::IntelExpr::hasOffset)
                .def("emitImm", &llvm::IntelExpr::emitImm)
                .def("isValid", &llvm::IntelExpr::isValid);
        }
    };

    template<>
    struct class_pybinder_t<llvm::AsmRewrite> : pybinder_t {
        using binding_t = py::class_<llvm::AsmRewrite>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.AsmRewrite"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "AsmRewrite" };
        }

        virtual void make_binding(py::module_& m) override {
            // todo
        }
    };

    template<>
    struct class_pybinder_t<llvm::ParseInstructionInfo> : pybinder_t {
        using binding_t = py::class_<llvm::ParseInstructionInfo>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.ParseInstructionInfo"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "ParseInstructionInfo" };
        }

        virtual void make_binding(py::module_& m) override {
            // todo
        }
    };

    template<>
    struct enum_pybinder_t<llvm::OperandMatchResultTy> : pybinder_t {
        using binding_t = py::enum_<llvm::OperandMatchResultTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.OperandMatchResultTy"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "OperandMatchResultTy" }
                .value("Success", llvm::OperandMatchResultTy::MatchOperand_Success)
                .value("NoMatch", llvm::OperandMatchResultTy::MatchOperand_NoMatch)
                .value("ParseFail", llvm::OperandMatchResultTy::MatchOperand_ParseFail);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::DiagnosticPredicateTy> : pybinder_t {
        using binding_t = py::enum_<llvm::DiagnosticPredicateTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.DiagnosticPredicateTy"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "DiagnosticPredicateTy" }
                .value("Match", llvm::DiagnosticPredicateTy::Match)
                .value("NearMatch", llvm::DiagnosticPredicateTy::NearMatch)
                .value("NoMatch", llvm::DiagnosticPredicateTy::NoMatch);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::DiagnosticPredicate>;

    template<>
    struct class_pybinder_t<llvm::NearMissInfo>;

    template<>
    struct enum_pybinder_t<llvm::NearMissInfo::NearMissKind>;

    template<>
    struct class_pybinder_t<llvm::MCTargetAsmParser> : pybinder_t {
        using binding_t = py::class_<llvm::MCTargetAsmParser, llvm::MCAsmParserExtension>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmParserExtension@MCTargetAsmParser"sv;
        static_assert(class_pybinder_t<llvm::MCAsmParserExtension>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCTargetAsmParser" };
        }

        virtual void make_binding(py::module_& m) override {
            // todo
        }
    };

    static enum_pybinder_t<llvm::AsmRewriteKind> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::IntelExpr> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::AsmRewrite> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::ParseInstructionInfo> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::OperandMatchResultTy> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::DiagnosticPredicateTy> PYLLVM_UNIQUE_NAME(_);
    //static class_pybinder_t<llvm::DiagnosticPredicate> PYLLVM_UNIQUE_NAME(_);
    //static class_pybinder_t<llvm::NearMissInfo> PYLLVM_UNIQUE_NAME(_);
    //static enum_pybinder_t<llvm::NearMissInfo::NearMissKind> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::MCTargetAsmParser> PYLLVM_UNIQUE_NAME(_);
}
