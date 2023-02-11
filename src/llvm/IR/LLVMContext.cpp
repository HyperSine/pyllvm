#include <llvm/IR/LLVMContext.h>
#include "../ADT/Optional.hpp"
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::LLVMContext> : pybinder_t {
        using binding_t = py::class_<llvm::LLVMContext>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.LLVMContext"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "LLVMContext" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("LLVMContext").cast<binding_t>()
                .def(py::init<>())
                .def("getMDKindID", &llvm::LLVMContext::getMDKindID, py::arg("Name"))
                //.def("getMDKindNames", &llvm::LLVMContext::getMDKindNames)
                //.def("getOperandBundleTags", &llvm::LLVMContext::getOperandBundleTags)
                //.def("getOrInsertBundleTag", &llvm::LLVMContext::getOrInsertBundleTag)
                .def("getOperandBundleTagID", &llvm::LLVMContext::getOperandBundleTagID, py::arg("Tag"))
                //.def("getOrInsertSyncScopeID", &llvm::LLVMContext::getOrInsertSyncScopeID)
                //.def("getSyncScopeNames", &llvm::LLVMContext::getSyncScopeNames)
                //.def("setGC", &llvm::LLVMContext::setGC)
                //.def("getGC", &llvm::LLVMContext::getGC)
                //.def("deleteGC", &llvm::LLVMContext::deleteGC)
                .def("shouldDiscardValueNames", &llvm::LLVMContext::shouldDiscardValueNames)
                .def("setDiscardValueNames", &llvm::LLVMContext::setDiscardValueNames, py::arg("Discard"))
                .def("isODRUniquingDebugTypes", &llvm::LLVMContext::isODRUniquingDebugTypes)
                .def("enableDebugTypeODRUniquing", &llvm::LLVMContext::enableDebugTypeODRUniquing)
                .def("disableDebugTypeODRUniquing", &llvm::LLVMContext::disableDebugTypeODRUniquing)
                //.def("setDiagnosticHandlerCallBack", &llvm::LLVMContext::getSyncScopeNames)
                //.def("setDiagnosticHandler", &llvm::LLVMContext::getSyncScopeNames)
                //.def("getDiagnosticHandlerCallBack", &llvm::LLVMContext::getDiagnosticHandlerCallBack)
                //.def("getDiagnosticContext", &llvm::LLVMContext::getDiagnosticContext)
                //.def("getDiagHandlerPtr", &llvm::LLVMContext::getDiagHandlerPtr)
                //.def("getDiagnosticHandler", &llvm::LLVMContext::getDiagnosticHandler)
                .def("getDiagnosticsHotnessRequested", &llvm::LLVMContext::getDiagnosticsHotnessRequested)
                .def("setDiagnosticsHotnessRequested", &llvm::LLVMContext::setDiagnosticsHotnessRequested, py::arg("Requested"))
                .def("getMisExpectWarningRequested", &llvm::LLVMContext::getMisExpectWarningRequested)
                .def("setMisExpectWarningRequested", &llvm::LLVMContext::setMisExpectWarningRequested, py::arg("Requested"))
                .def("setDiagnosticsMisExpectTolerance", &llvm::LLVMContext::setDiagnosticsMisExpectTolerance, py::arg("Tolerance"))
                .def("getDiagnosticsMisExpectTolerance", &llvm::LLVMContext::getDiagnosticsMisExpectTolerance)
                .def("getDiagnosticsHotnessThreshold", &llvm::LLVMContext::getDiagnosticsHotnessThreshold)
                .def("setDiagnosticsHotnessThreshold", &llvm::LLVMContext::setDiagnosticsHotnessThreshold, py::arg("Threshold"))
                .def("isDiagnosticsHotnessThresholdSetFromPSI", &llvm::LLVMContext::isDiagnosticsHotnessThresholdSetFromPSI)
                //.def("getMainRemarkStreamer", &llvm::LLVMContext::getMainRemarkStreamer)
                //.def("setMainRemarkStreamer", &llvm::LLVMContext::setMainRemarkStreamer)
                //.def("getLLVMRemarkStreamer", &llvm::LLVMContext::getLLVMRemarkStreamer)
                //.def("setLLVMRemarkStreamer", &llvm::LLVMContext::setLLVMRemarkStreamer)
                //.def("getDiagnosticMessagePrefix", &llvm::LLVMContext::getDiagnosticMessagePrefix)
                //.def("diagnose", &llvm::LLVMContext::diagnose)
                //.def("setYieldCallback", &llvm::LLVMContext::setYieldCallback)
                .def("yield", &llvm::LLVMContext::yield)
                //.def("emitError", &llvm::LLVMContext::emitError)
                //.def("emitError", &llvm::LLVMContext::emitError)
                //.def("emitError", &llvm::LLVMContext::emitError)
                //.def("getOptPassGate", &llvm::LLVMContext::getOptPassGate)
                //.def("setOptPassGate", &llvm::LLVMContext::setOptPassGate)
                .def("hasSetOpaquePointersValue", &llvm::LLVMContext::hasSetOpaquePointersValue)
                .def("setOpaquePointers", &llvm::LLVMContext::setOpaquePointers, py::arg("Enable"))
                .def("supportsTypedPointers", &llvm::LLVMContext::supportsTypedPointers)
                //.def("getTargetData", &llvm::LLVMContext::getTargetData)
                ;
        }
    };

    static class_pybinder_t<llvm::LLVMContext> PYLLVM_UNIQUE_NAME(_);
}
