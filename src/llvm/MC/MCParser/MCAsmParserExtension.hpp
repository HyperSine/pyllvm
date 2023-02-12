#include <llvm/MC/MCParser/MCAsmParserExtension.h>
#include "../../../init.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCAsmParserExtension> : pybinder_t {
        using binding_t = py::class_<llvm::MCAsmParserExtension>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmParserExtension"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCAsmParserExtension" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCAsmParserExtension").cast<binding_t>()
                .def(
                    "Initialize",
                    &llvm::MCAsmParserExtension::Initialize,
                    py::arg("Parser"),
                    py::keep_alive<1, 2>()
                )
                // todo
                ;
        }
    };
}
