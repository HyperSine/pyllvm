#include <llvm/MC/MCSection.h>
#include <llvm/MC/MCSectionMachO.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCSectionMachO> : pybinder_t {
        using binding_t = py::class_<llvm::MCSectionMachO, llvm::MCSection, std::unique_ptr<llvm::MCSectionMachO, py::nodelete>>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCSectionMachO"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCSectionMachO" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCSectionMachO").cast<binding_t>()
                .def("getSegmentName", &llvm::MCSectionMachO::getSegmentName)
                .def("getTypeAndAttributes", &llvm::MCSectionMachO::getTypeAndAttributes)
                .def("getStubSize", &llvm::MCSectionMachO::getStubSize)
                //.def("getType", &llvm::MCSectionMachO::getType)
                .def("hasAttribute", &llvm::MCSectionMachO::hasAttribute, py::arg("Value"))
                //.def("ParseSectionSpecifier", &llvm::MCSectionMachO::ParseSectionSpecifier)
                //.def("printSwitchToSection", &llvm::MCSectionMachO::printSwitchToSection)
                .def("useCodeAlign", &llvm::MCSectionMachO::useCodeAlign)
                .def("isVirtualSection", &llvm::MCSectionMachO::isVirtualSection)
                .def_static("classof", &llvm::MCSectionMachO::classof, py::arg("S"));
        }
    };

    static class_pybinder_t<llvm::MCSectionMachO> PYLLVM_UNIQUE_NAME(_);
}
