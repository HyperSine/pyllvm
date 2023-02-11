#include <llvm/MC/MCSection.h>
#include <llvm/MC/MCSymbol.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

// to avoid g++ bug
#ifdef __GNUG__     
namespace PYBIND11_NAMESPACE {
    namespace detail {
        template<>
        struct has_operator_delete<llvm::MCSymbol, void> : public std::false_type {};
    }
}
#endif

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCSymbol> : pybinder_t {
        using binding_t = py::class_<llvm::MCSymbol, std::unique_ptr<llvm::MCSymbol, py::nodelete>>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCSymbol"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCSymbol" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCSymbol").cast<binding_t>()
                .def("getName", &llvm::MCSymbol::getName)
                .def("isRegistered", &llvm::MCSymbol::isRegistered)
                .def("setIsRegistered", &llvm::MCSymbol::setIsRegistered)
                .def("isUsedInReloc", &llvm::MCSymbol::isUsedInReloc)
                .def("setUsedInReloc", &llvm::MCSymbol::setUsedInReloc)
                .def("isTemporary", &llvm::MCSymbol::isTemporary)
                .def("isUsed", &llvm::MCSymbol::isUsed)
                .def("isRedefinable", &llvm::MCSymbol::isRedefinable)
                .def("setRedefinable", &llvm::MCSymbol::setRedefinable)
                .def("redefineIfPossible", &llvm::MCSymbol::redefineIfPossible)
                .def("isDefined", &llvm::MCSymbol::isDefined)
                .def("isInSection", &llvm::MCSymbol::isInSection)
                .def("isUndefined", &llvm::MCSymbol::isUndefined)
                .def("isAbsolute", &llvm::MCSymbol::isAbsolute)
                .def("getSection", &llvm::MCSymbol::getSection, py::return_value_policy::reference_internal)
                //.def("setFragment", &llvm::MCSymbol::setFragment, py::arg("F"), py::keep_alive<1, 2>())
                .def("setUndefined", &llvm::MCSymbol::setUndefined)
                .def("isELF", &llvm::MCSymbol::isELF)
                .def("isCOFF", &llvm::MCSymbol::isCOFF)
                .def("isGOFF", &llvm::MCSymbol::isGOFF)
                .def("isMachO", &llvm::MCSymbol::isMachO)
                .def("isWasm", &llvm::MCSymbol::isWasm)
                .def("isXCOFF", &llvm::MCSymbol::isXCOFF)
                .def("isVariable", &llvm::MCSymbol::isVariable)
                // .def(
                //     "getVariableValue",
                //     &llvm::MCSymbol::getVariableValue,
                //     py::return_value_policy::reference_internal,
                //     py::arg("SetUsed") = true
                // )
                // .def(
                //     "setVariableValue",
                //     &llvm::MCSymbol::setVariableValue,
                //     py::arg("Value"),
                //     py::keep_alive<1, 2>()
                // )
                .def("getIndex", &llvm::MCSymbol::getIndex)
                .def("setIndex", &llvm::MCSymbol::setIndex)
                .def("isUnset", &llvm::MCSymbol::isUnset)
                .def("getOffset", &llvm::MCSymbol::getOffset)
                .def("setOffset", &llvm::MCSymbol::setOffset)
                .def("getCommonSize", &llvm::MCSymbol::getCommonSize)
                .def("setCommon", &llvm::MCSymbol::setCommon, py::arg("Size"), py::arg("Align"), py::arg("Target") = false)
                .def("getCommonAlignment", &llvm::MCSymbol::getCommonAlignment)
                .def("declareCommon", &llvm::MCSymbol::declareCommon, py::arg("Size"), py::arg("Align"), py::arg("Target") = false)
                .def("isCommon", &llvm::MCSymbol::isCommon)
                .def("isTargetCommon", &llvm::MCSymbol::isTargetCommon)
                //.def("getFragment", &llvm::MCSymbol::getFragment, py::return_value_policy::reference_internal, py::arg("SetUsed") = true)
                .def("isExternal", &llvm::MCSymbol::isExternal)
                .def("setExternal", &llvm::MCSymbol::setExternal)
                .def("isPrivateExtern", &llvm::MCSymbol::isPrivateExtern)
                .def("setPrivateExtern", &llvm::MCSymbol::setPrivateExtern)
                //.def("print", &llvm::MCSymbol::print)
                //.def("dump", &llvm::MCSymbol::dump)
                ;
        }
    };

    static class_pybinder_t<llvm::MCSymbol> PYLLVM_UNIQUE_NAME(_);
}
