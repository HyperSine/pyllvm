#include <llvm/Support/SMLoc.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::SMLoc> : pybinder_t {
        using binding_t = py::class_<llvm::SMLoc>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.SMLoc"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "SMLoc" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("SMLoc").cast<binding_t>()
                .def(py::init<>())
                .def(py::self == py::self)
                .def(py::self != py::self)
                .def(
                    "__hash__",
                    [](llvm::SMLoc& self) -> std::size_t {
                        return std::hash<const char*>{}(self.getPointer());
                    }
                )
                .def("isValid", &llvm::SMLoc::isValid)
                .def(
                    "getPointer",
                    [](llvm::SMLoc& self) -> std::optional<py::capsule> {
                        if (const char* p = self.getPointer()) {
                            return py::capsule{ self.getPointer() };
                        } else {
                            return std::nullopt;
                        }
                    }
                )
                .def_static(
                    "getFromPointer",
                    [](std::optional<py::capsule> capsule) -> llvm::SMLoc {
                        const char* p = capsule.has_value() ? reinterpret_cast<const char*>(capsule->get_pointer()) : nullptr;
                        return llvm::SMLoc::getFromPointer(p);
                    },
                    py::arg("Ptr")
                );
        }
    };

    template<>
    struct class_pybinder_t<llvm::SMRange> : pybinder_t {
        using binding_t = py::class_<llvm::SMRange>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.SMRange"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "SMRange" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("SMRange").cast<binding_t>()
                .def(py::init<>())
                .def(py::init<llvm::SMLoc, llvm::SMLoc>(), py::arg("St"), py::arg("En"))
                .def("isValid", &llvm::SMRange::isValid);
        }
    };

    static class_pybinder_t<llvm::SMLoc> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::SMRange> PYLLVM_UNIQUE_NAME(_);
}
