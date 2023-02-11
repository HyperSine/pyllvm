#include <llvm/Support/TargetSelect.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    struct Support_TargetSelect_tag {};

    template<>
    struct function_pybinder_t<Support_TargetSelect_tag> : pybinder_t {
        static constexpr std::string_view binder_identifier = "pyllvm.llvm.funtions@Support/TargetSelect"sv;

        function_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {}

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").cast<py::module_>()
                .def("InitializeAllTargetInfos", &llvm::InitializeAllTargetInfos)
                .def("InitializeAllTargets", &llvm::InitializeAllTargets)
                .def("InitializeAllTargetMCs", &llvm::InitializeAllTargetMCs)
                .def("InitializeAllAsmPrinters", &llvm::InitializeAllAsmPrinters)
                .def("InitializeAllAsmParsers", &llvm::InitializeAllAsmParsers)
                .def("InitializeAllDisassemblers", &llvm::InitializeAllDisassemblers)
                .def("InitializeNativeTarget", &llvm::InitializeNativeTarget)
                .def("InitializeNativeTargetAsmPrinter", &llvm::InitializeNativeTargetAsmPrinter)
                .def("InitializeNativeTargetAsmParser", &llvm::InitializeNativeTargetAsmParser)
                .def("InitializeNativeTargetDisassembler", &llvm::InitializeNativeTargetDisassembler)
                .def("InitializeAllTargetMCAs", &llvm::InitializeAllTargetMCAs);
        }
    };

    static function_pybinder_t<Support_TargetSelect_tag> PYLLVM_UNIQUE_NAME(_);
}
