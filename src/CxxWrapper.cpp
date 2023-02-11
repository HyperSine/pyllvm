#include "CxxWrapper.hpp"
#include "init.hpp"
#include "macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<CxxWrapper> : pybinder_t {
        using binding_t = py::class_<CxxWrapper>;

        static constexpr std::string_view binder_identifier = "pyllvm.CxxWrapper"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m, "CxxWrapper" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("CxxWrapper").cast<binding_t>()
                .def("__repr__", &CxxWrapper::repr)
                .def("isEmpty", &CxxWrapper::isEmpty)
                .def("unwrap", &CxxWrapper::unwrap);
        }
    };

    static class_pybinder_t<CxxWrapper> PYLLVM_UNIQUE_NAME(_);
}
