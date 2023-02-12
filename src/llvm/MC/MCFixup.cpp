#include <llvm/MC/MCFixup.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct enum_pybinder_t<llvm::MCFixupKind> : pybinder_t {
        using binding_t = py::enum_<llvm::MCFixupKind>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCFixupKind"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCFixupKind" }
                .value("NONE", llvm::MCFixupKind::FK_NONE)
                .value("Data_1", llvm::MCFixupKind::FK_Data_1)
                .value("Data_2", llvm::MCFixupKind::FK_Data_2)
                .value("Data_4", llvm::MCFixupKind::FK_Data_4)
                .value("Data_8", llvm::MCFixupKind::FK_Data_8)
                .value("Data_6b", llvm::MCFixupKind::FK_Data_6b)
                .value("PCRel_1", llvm::MCFixupKind::FK_PCRel_1)
                .value("PCRel_2", llvm::MCFixupKind::FK_PCRel_2)
                .value("PCRel_4", llvm::MCFixupKind::FK_PCRel_4)
                .value("PCRel_8", llvm::MCFixupKind::FK_PCRel_8)
                .value("GPRel_1", llvm::MCFixupKind::FK_GPRel_1)
                .value("GPRel_2", llvm::MCFixupKind::FK_GPRel_2)
                .value("GPRel_4", llvm::MCFixupKind::FK_GPRel_4)
                .value("GPRel_8", llvm::MCFixupKind::FK_GPRel_8)
                .value("DTPRel_4", llvm::MCFixupKind::FK_DTPRel_4)
                .value("DTPRel_8", llvm::MCFixupKind::FK_DTPRel_8)
                .value("TPRel_4", llvm::MCFixupKind::FK_TPRel_4)
                .value("TPRel_8", llvm::MCFixupKind::FK_TPRel_8)
                .value("SecRel_1", llvm::MCFixupKind::FK_SecRel_1)
                .value("SecRel_2", llvm::MCFixupKind::FK_SecRel_2)
                .value("SecRel_4", llvm::MCFixupKind::FK_SecRel_4)
                .value("SecRel_8", llvm::MCFixupKind::FK_SecRel_8)
                .value("FirstTargetFixupKind", llvm::MCFixupKind::FirstTargetFixupKind)
                .value("FirstLiteralRelocationKind", llvm::MCFixupKind::FirstLiteralRelocationKind)
                .value("MaxFixupKind", llvm::MCFixupKind::MaxFixupKind);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::MCFixup> : pybinder_t {
        using binding_t = py::class_<llvm::MCFixup>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCFixup"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCFixup" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCFixup").cast<binding_t>()
                .def("getKind", &llvm::MCFixup::getKind)
                .def("getTargetKind", &llvm::MCFixup::getTargetKind)
                .def("getOffset", &llvm::MCFixup::getOffset)
                .def("setOffset", &llvm::MCFixup::setOffset, py::arg("Value"))
                //.def("getValue", &llvm::MCFixup::getValue)
                .def("getLoc", &llvm::MCFixup::getLoc)
                //.def_static("create", &llvm::MCFixup::create)
                .def_static(
                    "getKindForSize",
                    &llvm::MCFixup::getKindForSize,
                    py::arg("Size"),
                    py::arg("IsPCRel")
                )
                .def_static(
                    "getKindForSizeInBits",
                    &llvm::MCFixup::getKindForSizeInBits,
                    py::arg("Size"),
                    py::arg("IsPCRel")
                );
        }
    };

    static enum_pybinder_t<llvm::MCFixupKind> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::MCFixup> PYLLVM_UNIQUE_NAME(_);
}
