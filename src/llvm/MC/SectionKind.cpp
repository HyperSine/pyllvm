#include <llvm/MC/SectionKind.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::SectionKind> : pybinder_t {
        using binding_t = py::class_<llvm::SectionKind>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.SectionKind"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "SectionKind" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("SectionKind").cast<binding_t>()
                .def("isMetadata", &llvm::SectionKind::isMetadata)
                .def("isText", &llvm::SectionKind::isText)
                .def("isExecuteOnly", &llvm::SectionKind::isExecuteOnly)
                .def("isReadOnly", &llvm::SectionKind::isReadOnly)
                .def("isMergeableCString", &llvm::SectionKind::isMergeableCString)
                .def("isMergeable1ByteCString", &llvm::SectionKind::isMergeable1ByteCString)
                .def("isMergeable2ByteCString", &llvm::SectionKind::isMergeable2ByteCString)
                .def("isMergeable4ByteCString", &llvm::SectionKind::isMergeable4ByteCString)
                .def("isMergeableConst", &llvm::SectionKind::isMergeableConst)
                .def("isMergeableConst4", &llvm::SectionKind::isMergeableConst4)
                .def("isMergeableConst8", &llvm::SectionKind::isMergeableConst8)
                .def("isMergeableConst16", &llvm::SectionKind::isMergeableConst16)
                .def("isMergeableConst32", &llvm::SectionKind::isMergeableConst32)
                .def("isWriteable", &llvm::SectionKind::isWriteable)
                .def("isThreadLocal", &llvm::SectionKind::isThreadLocal)
                .def("isThreadBSS", &llvm::SectionKind::isThreadBSS)
                .def("isThreadData", &llvm::SectionKind::isThreadData)
                .def("isThreadBSSLocal", &llvm::SectionKind::isThreadBSSLocal)
                .def("isGlobalWriteableData", &llvm::SectionKind::isGlobalWriteableData)
                .def("isBSS", &llvm::SectionKind::isBSS)
                .def("isBSSLocal", &llvm::SectionKind::isBSSLocal)
                .def("isBSSExtern", &llvm::SectionKind::isBSSExtern)
                .def("isCommon", &llvm::SectionKind::isCommon)
                .def("isData", &llvm::SectionKind::isData)
                .def("isReadOnlyWithRel", &llvm::SectionKind::isReadOnlyWithRel)
                .def_static("getMetadata", &llvm::SectionKind::getMetadata)
                .def_static("getText", &llvm::SectionKind::getText)
                .def_static("getExecuteOnly", &llvm::SectionKind::getExecuteOnly)
                .def_static("getReadOnly", &llvm::SectionKind::getReadOnly)
                .def_static("getMergeable1ByteCString", &llvm::SectionKind::getMergeable1ByteCString)
                .def_static("getMergeable2ByteCString", &llvm::SectionKind::getMergeable2ByteCString)
                .def_static("getMergeable4ByteCString", &llvm::SectionKind::getMergeable4ByteCString)
                .def_static("getMergeableConst4", &llvm::SectionKind::getMergeableConst4)
                .def_static("getMergeableConst8", &llvm::SectionKind::getMergeableConst8)
                .def_static("getMergeableConst16", &llvm::SectionKind::getMergeableConst16)
                .def_static("getMergeableConst32", &llvm::SectionKind::getMergeableConst32)
                .def_static("getThreadBSS", &llvm::SectionKind::getThreadBSS)
                .def_static("getThreadData", &llvm::SectionKind::getThreadData)
                .def_static("getThreadBSSLocal", &llvm::SectionKind::getThreadBSSLocal)
                .def_static("getBSS", &llvm::SectionKind::getBSS)
                .def_static("getBSSLocal", &llvm::SectionKind::getBSSLocal)
                .def_static("getBSSExtern", &llvm::SectionKind::getBSSExtern)
                .def_static("getCommon", &llvm::SectionKind::getCommon)
                .def_static("getData", &llvm::SectionKind::getData)
                .def_static("getReadOnlyWithRel", &llvm::SectionKind::getReadOnlyWithRel);
        }
    };

    static class_pybinder_t<llvm::SectionKind> PYLLVM_UNIQUE_NAME(_);
}
