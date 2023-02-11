#include <llvm/IR/Module.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::Module> : pybinder_t {
        using binding_t = py::class_<llvm::Module>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Module"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "Module" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("Module").cast<binding_t>()
                .def(py::init<llvm::StringRef, llvm::LLVMContext&>(), py::arg("ModuleID"), py::arg("C"), py::keep_alive<1, 2>())
                // todo
                ;
        }
    };

    static class_pybinder_t<llvm::Module> PYLLVM_UNIQUE_NAME(_);
}