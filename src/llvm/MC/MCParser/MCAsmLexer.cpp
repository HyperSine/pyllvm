#include <llvm/MC/MCParser/MCAsmLexer.h>
#include "../../../init.hpp"
#include "../../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCAsmLexer> : pybinder_t {
        using binding_t = py::class_<llvm::MCAsmLexer>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmLexer"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCAsmLexer" };
        }

        virtual void make_binding(py::module_& m) override {
            // todo
        }
    };

    static class_pybinder_t<llvm::MCAsmLexer> PYLLVM_UNIQUE_NAME(_);
}
