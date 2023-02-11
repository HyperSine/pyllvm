#include <llvm/MC/MCSubtargetInfo.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCSubtargetInfo> : pybinder_t {
        using binding_t = py::class_<llvm::MCSubtargetInfo>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCSubtargetInfo"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCSubtargetInfo" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCSubtargetInfo").cast<binding_t>()
                .def("getTargetTriple", &llvm::MCSubtargetInfo::getTargetTriple, py::return_value_policy::reference_internal)
                .def("getCPU", &llvm::MCSubtargetInfo::getCPU)
                .def("getTuneCPU", &llvm::MCSubtargetInfo::getTuneCPU)
                // .def_property(
                //     "FeatureBits",
                //     &llvm::MCSubtargetInfo::getFeatureBits,
                //     &llvm::MCSubtargetInfo::setFeatureBits
                // )
                .def("getFeatureString", &llvm::MCSubtargetInfo::getFeatureString)
                .def("hasFeature", &llvm::MCSubtargetInfo::hasFeature, py::arg("Feature"))
                .def(
                    "setDefaultFeatures",
                    &llvm::MCSubtargetInfo::setDefaultFeatures,
                    py::arg("CPU"),
                    py::arg("TuneCPU"),
                    py::arg("FS")
                )
                //.def("ToggleFeature", &llvm::MCSubtargetInfo::ToggleFeature)
                //.def("ToggleFeature", &llvm::MCSubtargetInfo::ToggleFeature)
                //.def("ToggleFeature", &llvm::MCSubtargetInfo::ToggleFeature)
                //.def("ApplyFeatureFlag", &llvm::MCSubtargetInfo::ApplyFeatureFlag)
                //.def("SetFeatureBitsTransitively", &llvm::MCSubtargetInfo::SetFeatureBitsTransitively)
                //.def("ClearFeatureBitsTransitively", &llvm::MCSubtargetInfo::ClearFeatureBitsTransitively)
                .def("checkFeatures", &llvm::MCSubtargetInfo::checkFeatures, py::arg("FS"))
                //.def("getSchedModelForCPU", &llvm::MCSubtargetInfo::getSchedModelForCPU)
                //.def("getSchedModel", &llvm::MCSubtargetInfo::getSchedModel)
                //.def("getWriteProcResBegin", &llvm::MCSubtargetInfo::getWriteProcResBegin)
                //.def("getWriteProcResEnd", &llvm::MCSubtargetInfo::getWriteProcResEnd)
                //.def("getWriteLatencyEntry", &llvm::MCSubtargetInfo::getWriteLatencyEntry)
                //.def("getReadAdvanceCycles", &llvm::MCSubtargetInfo::getReadAdvanceCycles)
                //.def("getReadAdvanceEntries", &llvm::MCSubtargetInfo::getReadAdvanceEntries)
                //.def("getInstrItineraryForCPU", &llvm::MCSubtargetInfo::getInstrItineraryForCPU)
                //.def("initInstrItins", &llvm::MCSubtargetInfo::initInstrItins)
                .def("isCPUStringValid", &llvm::MCSubtargetInfo::isCPUStringValid, py::arg("CPU"))
                .def("getHwMode", &llvm::MCSubtargetInfo::getHwMode)
                .def(
                    "getCacheSize",
                    [](llvm::MCSubtargetInfo& self, unsigned level) -> std::optional<unsigned> {
                        auto r = self.getCacheSize(level);
                        return r.hasValue() ? std::optional(r.getValue()) : std::nullopt;
                    },
                    py::arg("Level")
                )
                .def(
                    "getCacheAssociativity",
                    [](llvm::MCSubtargetInfo& self, unsigned level) -> std::optional<unsigned> {
                        auto r = self.getCacheAssociativity(level);
                        return r.hasValue() ? std::optional(r.getValue()) : std::nullopt;
                    },
                    py::arg("Level")
                )
                .def(
                    "getCacheLineSize",
                    [](llvm::MCSubtargetInfo& self) {
                        return self.getCacheLineSize();
                    }
                )
                .def(
                    "getCacheLineSize",
                    [](llvm::MCSubtargetInfo& self, unsigned level) -> std::optional<unsigned> {
                        auto r = self.getCacheLineSize(level);
                        return r.hasValue() ? std::optional(r.getValue()) : std::nullopt;
                    },
                    py::arg("Level")
                )
                .def("getPrefetchDistance", &llvm::MCSubtargetInfo::getPrefetchDistance)
                .def("getMaxPrefetchIterationsAhead", &llvm::MCSubtargetInfo::getMaxPrefetchIterationsAhead)
                .def("enableWritePrefetching", &llvm::MCSubtargetInfo::enableWritePrefetching)
                .def(
                    "getMinPrefetchStride", &llvm::MCSubtargetInfo::getMinPrefetchStride,
                    py::arg("NumMemAccesses"), py::arg("NumStridedMemAccesses"), py::arg("NumPrefetches"), py::arg("HasCall")
                );
        }
    };

    static class_pybinder_t<llvm::MCSubtargetInfo> PYLLVM_UNIQUE_NAME(_);
}
