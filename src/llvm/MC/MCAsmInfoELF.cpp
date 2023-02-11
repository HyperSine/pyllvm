#include <llvm/MC/MCAsmInfo.h>
#include <llvm/MC/MCAsmInfoELF.h>
#include "MCAsmInfo.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCAsmInfoELF> : pybinder_t {
        using binding_t = py::class_<llvm::MCAsmInfoELF, llvm::MCAsmInfo>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmInfoELF"sv;
        static_assert(class_pybinder_t<llvm::MCAsmInfo>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCAsmInfoELF" };
        }

        virtual void make_binding(py::module_& m) override {}
    };

    static class_pybinder_t<llvm::MCAsmInfoELF> PYLLVM_UNIQUE_NAME(_);
}
