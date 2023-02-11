#include <llvm/MC/MCSection.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCSection> : pybinder_t {
        using binding_t = py::class_<llvm::MCSection, std::unique_ptr<llvm::MCSection, py::nodelete>>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCSection"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCSection" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCSection").cast<binding_t>()
                .def_readonly_static("NonUniqueID", &llvm::MCSection::NonUniqueID)
                .def(
                    "__iter__",
                    [](llvm::MCSection& self) {
                        return py::make_iterator(self.begin(), self.end());
                    }
                )
                .def("getName", &llvm::MCSection::getName)
                .def("getKind", &llvm::MCSection::getKind)
                .def("getVariant", &llvm::MCSection::getVariant)
                //.def("getBeginSymbol", &llvm::MCSection::getBeginSymbol)
                //.def("getBeginSymbol", &llvm::MCSection::getBeginSymbol)
                //.def("setBeginSymbol", &llvm::MCSection::setBeginSymbol)
                //.def("getEndSymbol", &llvm::MCSection::getEndSymbol)
                .def("hasEnded", &llvm::MCSection::hasEnded)
                .def("getAlignment", &llvm::MCSection::getAlignment)
                //.def("setAlignment", &llvm::MCSection::setAlignment)
                .def_property("Ordinal", &llvm::MCSection::getOrdinal, &llvm::MCSection::setOrdinal)
                .def_property("LayoutOrder", &llvm::MCSection::getLayoutOrder, &llvm::MCSection::setLayoutOrder)
                .def_property("BundleLockState", &llvm::MCSection::getBundleLockState, &llvm::MCSection::setBundleLockState)
                .def("isBundleLocked", &llvm::MCSection::isBundleLocked)
                .def_property("BundleGroupBeforeFirstInst", &llvm::MCSection::isBundleGroupBeforeFirstInst, &llvm::MCSection::setBundleGroupBeforeFirstInst)
                .def_property("HasInstructions", &llvm::MCSection::hasInstructions, &llvm::MCSection::setHasInstructions)
                .def_property("IsRegistered", &llvm::MCSection::isRegistered, &llvm::MCSection::setIsRegistered)
                //.def("getFragmentList", &llvm::MCSection::getFragmentList)
                //.def("getFragmentList", &llvm::MCSection::getFragmentList)
                //.def_static("getSublistAccess", &llvm::MCSection::getSublistAccess)
                //.def("getDummyFragment", &llvm::MCSection::getDummyFragment)
                //.def("getDummyFragment", &llvm::MCSection::getDummyFragment)
                //.def("dump", &llvm::MCSection::dump)
                //.def("PrintSwitchToSection", &llvm::MCSection::PrintSwitchToSection)
                .def("useCodeAlign", &llvm::MCSection::useCodeAlign)
                .def("isVirtualSection", &llvm::MCSection::isVirtualSection)
                .def("getVirtualSectionKind", &llvm::MCSection::getVirtualSectionKind)
                //.def("addPendingLabel", &llvm::MCSection::addPendingLabel)
                //.def("flushPendingLabels", &llvm::MCSection::flushPendingLabels)
                .def("flushPendingLabels", py::overload_cast<>(&llvm::MCSection::flushPendingLabels));
        }
    };

    template<>
    struct enum_pybinder_t<llvm::MCSection::SectionVariant> : pybinder_t {
        using binding_t = py::enum_<llvm::MCSection::SectionVariant>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCSection.SectionVariant"sv;
        static_assert(class_pybinder_t<llvm::MCSection>::binder_identifier < binder_identifier);
        
        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("MCSection"), "SectionVariant" }
                .value("COFF", llvm::MCSection::SectionVariant::SV_COFF)
                .value("ELF", llvm::MCSection::SectionVariant::SV_ELF)
                .value("GOFF", llvm::MCSection::SectionVariant::SV_GOFF)
                .value("MachO", llvm::MCSection::SectionVariant::SV_MachO)
                .value("Wasm", llvm::MCSection::SectionVariant::SV_Wasm)
                .value("XCOFF", llvm::MCSection::SectionVariant::SV_XCOFF);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::MCSection::BundleLockStateType> : pybinder_t {
        using binding_t = py::enum_<llvm::MCSection::BundleLockStateType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCSection.BundleLockStateType"sv;
        static_assert(class_pybinder_t<llvm::MCSection>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("MCSection"), "BundleLockStateType" }
                .value("NotBundleLocked", llvm::MCSection::BundleLockStateType::NotBundleLocked)
                .value("BundleLocked", llvm::MCSection::BundleLockStateType::BundleLocked)
                .value("BundleLockedAlignToEnd", llvm::MCSection::BundleLockStateType::BundleLockedAlignToEnd);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    static class_pybinder_t<llvm::MCSection> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCSection::SectionVariant> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCSection::BundleLockStateType> PYLLVM_UNIQUE_NAME(_);
}
