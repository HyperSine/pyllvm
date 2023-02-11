#include <llvm/MC/MCInstrInfo.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCInstrInfo> : pybinder_t {
        using binding_t = py::class_<llvm::MCInstrInfo>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCInstrInfo"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCInstrInfo" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCInstrInfo").cast<binding_t>()
                .def("get", &llvm::MCInstrInfo::get, py::return_value_policy::reference_internal, py::arg("Opcode"))
                .def("getName", &llvm::MCInstrInfo::getName, py::arg("Opcode"))
                .def("getNumOpcodes", &llvm::MCInstrInfo::getNumOpcodes);
        }
    };

    static class_pybinder_t<llvm::MCInstrInfo> PYLLVM_UNIQUE_NAME(_);
}
