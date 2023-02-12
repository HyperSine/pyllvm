#include <llvm/MC/MCAsmBackend.h>
#include <llvm/MC/MCInst.h>
#include <llvm/MC/MCObjectWriter.h>
#include <llvm/MC/MCSubtargetInfo.h>
#include "../ADT/Optional.hpp"
#include "../ADT/StringRef.hpp"
#include "../Support/raw_py_binaryio_ostream.hpp"
#include "../../CxxWrapper.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCAsmBackend> : pybinder_t {
        using binding_t = py::class_<llvm::MCAsmBackend>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmBackend"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCAsmBackend" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCAsmBackend").cast<binding_t>()
                .def("allowAutoPadding", &llvm::MCAsmBackend::allowAutoPadding)
                .def("allowEnhancedRelaxation", &llvm::MCAsmBackend::allowEnhancedRelaxation)
                //.def("emitInstructionBegin", &llvm::MCAsmBackend::emitInstructionBegin)
                //.def("emitInstructionEnd", &llvm::MCAsmBackend::emitInstructionEnd)
                .def("reset", &llvm::MCAsmBackend::reset)
                //.def("createObjectWriter", &llvm::MCAsmBackend::createObjectWriter)
                //.def("createDwoObjectWriter", &llvm::MCAsmBackend::createDwoObjectWriter)
                .def(
                    "createObjectTargetWriter",
                    [](llvm::MCAsmBackend& self) -> std::unique_ptr<CxxWrapper> {
                        using wrapper_t = CxxWrapperFor<std::unique_ptr<llvm::MCObjectTargetWriter>>;
                        return std::make_unique<wrapper_t>(self.createObjectTargetWriter());
                    }
                )
                .def("getNumFixupKinds", &llvm::MCAsmBackend::getNumFixupKinds)
                .def(
                    "getFixupKind",
                    &llvm::MCAsmBackend::getFixupKind,
                    py::arg("Name")
                )
                //.def("getFixupKindInfo", &llvm::MCAsmBackend::getFixupKindInfo)
                //.def("shouldForceRelocation", &llvm::MCAsmBackend::shouldForceRelocation)
                //.def("shouldInsertExtraNopBytesForCodeAlign", &llvm::MCAsmBackend::shouldInsertExtraNopBytesForCodeAlign)
                //.def("shouldInsertFixupForCodeAlign", &llvm::MCAsmBackend::shouldInsertFixupForCodeAlign)
                //.def("evaluateTargetFixup", &llvm::MCAsmBackend::evaluateTargetFixup)
                //.def("applyFixup", &llvm::MCAsmBackend::applyFixup)
                .def("mayNeedRelaxation", &llvm::MCAsmBackend::mayNeedRelaxation)
                //.def("fixupNeedsRelaxationAdvanced", &llvm::MCAsmBackend::fixupNeedsRelaxationAdvanced)
                .def("relaxInstruction", &llvm::MCAsmBackend::relaxInstruction)
                //.def("relaxDwarfLineAddr", &llvm::MCAsmBackend::relaxDwarfLineAddr)
                //.def("relaxDwarfCFA", &llvm::MCAsmBackend::relaxDwarfCFA)
                .def("getMinimumNopSize", &llvm::MCAsmBackend::getMinimumNopSize)
                .def(
                    "getMaximumNopSize",
                    &llvm::MCAsmBackend::getMaximumNopSize,
                    py::arg("STI")
                )
                .def(
                    "writeNopData",
                    [](llvm::MCAsmBackend& self, py::BinaryIO OS, uint64_t Count, py::nullable_ptr<llvm::MCSubtargetInfo> STI) -> bool {
                        llvm::raw_py_binaryio_ostream bio{ OS };
                        return self.writeNopData(bio, Count, STI.value);
                    },
                    py::arg("OS"),
                    py::arg("Count"),
                    py::arg("STI")
                )
                //.def("finishLayout", &llvm::MCAsmBackend::finishLayout)
                .def("handleAssemblerFlag", &llvm::MCAsmBackend::handleAssemblerFlag)
                //.def("generateCompactUnwindEncoding", &llvm::MCAsmBackend::generateCompactUnwindEncoding)
                //.def("isMicroMips", &llvm::MCAsmBackend::isMicroMips)
                ;
        }
    };

    static class_pybinder_t<llvm::MCAsmBackend> PYLLVM_UNIQUE_NAME(_);
}
