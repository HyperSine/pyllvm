#include <llvm/MC/MCRegister.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCRegister> : pybinder_t {
        using binding_t = py::class_<llvm::MCRegister>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCRegister"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCRegister" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCRegister").cast<binding_t>()
                .def(py::init<unsigned>(), py::arg("Val") = 0)
                .def(py::self == py::self)
                .def(py::self != py::self)
                .def("__int__", &llvm::MCRegister::id)
                .def(
                    "__hash__",
                    [](llvm::MCRegister& self) -> std::size_t {
                        return llvm::hash_value(self);
                    }
                )
                .def(
                    "__repr__",
                    [](llvm::MCRegister& self) -> py::str {
                        return py::str("MCRegister({:d})").format(self.id());
                    }
                )
                //.def("id", &llvm::MCRegister::id) // skip: already bound as `__int__`
                .def("isValid", &llvm::MCRegister::isValid)
                //.def_static("from", &llvm::MCRegister::from, py::arg("Val"))      // skip: `from` is a keyword reserved by Python
                .def_static("isStackSlot", &llvm::MCRegister::isStackSlot, py::arg("Reg"))
                .def_static("isPhysicalRegister", &llvm::MCRegister::isPhysicalRegister, py::arg("Reg"));
        }
    };

    static class_pybinder_t<llvm::MCRegister> PYLLVM_UNIQUE_NAME(_);
}
