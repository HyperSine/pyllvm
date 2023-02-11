#include <llvm/MC/MCInstrAnalysis.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCInstrAnalysis> : pybinder_t {
        using binding_t = py::class_<llvm::MCInstrAnalysis>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCInstrAnalysis"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCInstrAnalysis" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCInstrAnalysis").cast<binding_t>()
                .def("isBranch", &llvm::MCInstrAnalysis::isBranch, py::arg("Inst"))
                .def("isConditionalBranch", &llvm::MCInstrAnalysis::isConditionalBranch, py::arg("Inst"))
                .def("isUnconditionalBranch", &llvm::MCInstrAnalysis::isUnconditionalBranch, py::arg("Inst"))
                .def("isIndirectBranch", &llvm::MCInstrAnalysis::isIndirectBranch, py::arg("Inst"))
                .def("isCall", &llvm::MCInstrAnalysis::isCall, py::arg("Inst"))
                .def("isReturn", &llvm::MCInstrAnalysis::isReturn, py::arg("Inst"))
                .def("isTerminator", &llvm::MCInstrAnalysis::isTerminator, py::arg("Inst"))
                //.def("clearsSuperRegisters", &llvm::MCInstrAnalysis::clearsSuperRegisters)
                //.def("isZeroIdiom", &llvm::MCInstrAnalysis::isZeroIdiom)
                //.def("isDependencyBreaking", &llvm::MCInstrAnalysis::isDependencyBreaking)
                //.def("isOptimizableRegisterMove", &llvm::MCInstrAnalysis::isOptimizableRegisterMove)
                //.def("evaluateBranch", &llvm::MCInstrAnalysis::evaluateBranch)
                //.def("evaluateMemoryOperandAddress", &llvm::MCInstrAnalysis::evaluateMemoryOperandAddress)
                //.def("getMemoryOperandRelocationOffset", &llvm::MCInstrAnalysis::getMemoryOperandRelocationOffset)
                //.def("findPltEntries", &llvm::MCInstrAnalysis::findPltEntries)
                ;
        }
    };

    static class_pybinder_t<llvm::MCInstrAnalysis> PYLLVM_UNIQUE_NAME(_);
}
