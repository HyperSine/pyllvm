#include <llvm/Support/SourceMgr.h>
#include "../ADT/ArrayRef.hpp"
#include "../ADT/StringRef.hpp"
#include "../Support/raw_py_binaryio_ostream.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"
#include "../../CxxWrapper.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::SourceMgr> : pybinder_t {
        using binding_t = py::class_<llvm::SourceMgr>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.SourceMgr"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "SourceMgr", py::dynamic_attr() };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("SourceMgr").cast<binding_t>()
                .def(py::init<>())
                .def("getIncludeDirs", &llvm::SourceMgr::getIncludeDirs)
                .def("setIncludeDirs", &llvm::SourceMgr::setIncludeDirs, py::arg("Dirs"))
                .def(
                    "setDiagHandler",
                    [](llvm::SourceMgr& self, py::Callable<void(const llvm::SMDiagnostic&, py::Any)> DH, py::Any Ctx) {
                        py::object self_py = py::cast(self);

                        self_py.attr("__diag_handler__") = std::move(DH);
                        self_py.attr("__diag_handler_ctx__") = std::move(Ctx);

                        self.setDiagHandler(
                            [](const llvm::SMDiagnostic& diag, void* context) {
                                py::handle self_py{ reinterpret_cast<PyObject*>(context) };
                                self_py.attr("__diag_handler__")(diag, self_py.attr("__diag_handler_ctx__"));
                            },
                            self_py.ptr()
                        );
                    },
                    py::arg("DH"),
                    py::arg("Ctx")
                )
                .def(
                    "getDiagHandler",
                    [](llvm::SourceMgr& self) -> py::Callable<void(const llvm::SMDiagnostic&, py::Any)> {
                        return py::cast(self).attr("__diag_handler__");
                    }
                )
                .def(
                    "getDiagContext",
                    [](llvm::SourceMgr& self) -> py::Any {
                        return py::cast(self).attr("__diag_handler_ctx__");
                    }
                )
                //.def("getBufferInfo", &llvm::SourceMgr::getBufferInfo)
                .def(
                    "getMemoryBuffer",
                    &llvm::SourceMgr::getMemoryBuffer,
                    py::arg("i"),
                    py::return_value_policy::reference_internal
                )
                .def("getNumBuffers", &llvm::SourceMgr::getNumBuffers)
                .def("getMainFileID", &llvm::SourceMgr::getMainFileID)
                .def("getParentIncludeLoc", &llvm::SourceMgr::getParentIncludeLoc, py::arg("i"))
                .def(
                    "AddNewSourceBuffer",
                    [](llvm::SourceMgr& self, CxxWrapper& F_wrapper, llvm::SMLoc IncludeLoc) {
                        using wrapper_t = CxxWrapperFor<std::unique_ptr<llvm::MemoryBuffer>>;
                        return self.AddNewSourceBuffer(std::move(dynamic_cast<wrapper_t&>(F_wrapper).ptr), IncludeLoc);
                    },
                    py::arg("F"),
                    py::arg("IncludeLoc")
                 )
                .def(
                    "takeSourceBuffersFrom",
                    [](llvm::SourceMgr& self, llvm::SourceMgr& SrcMgr, std::optional<llvm::SMLoc> MainBufferIncludeLoc) {
                        if (MainBufferIncludeLoc.has_value()) {
                            self.takeSourceBuffersFrom(SrcMgr, MainBufferIncludeLoc.value());
                        } else {
                            self.takeSourceBuffersFrom(SrcMgr);
                        }
                    },
                    py::arg("SrcMgr"),
                    py::arg("MainBufferIncludeLoc") = py::none{}
                )
                //.def("AddIncludeFile", &llvm::SourceMgr::AddIncludeFile)
                //.def("OpenIncludeFile", &llvm::SourceMgr::OpenIncludeFile)
                .def("FindBufferContainingLoc", &llvm::SourceMgr::FindBufferContainingLoc, py::arg("Loc"))
                .def("FindLineNumber", &llvm::SourceMgr::FindLineNumber, py::arg("Loc"), py::arg("BufferID") = 0)
                .def("getLineAndColumn", &llvm::SourceMgr::getLineAndColumn, py::arg("Loc"), py::arg("BufferID") = 0)
                .def("getFormattedLocationNoOffset", &llvm::SourceMgr::getFormattedLocationNoOffset, py::arg("Loc"), py::arg("IncludePath") = false)
                .def("FindLocForLineAndColumn", &llvm::SourceMgr::FindLocForLineAndColumn, py::arg("BufferID"), py::arg("LineNo"), py::arg("ColNo"))
                //.def("PrintMessage", &llvm::SourceMgr::PrintMessage)
                //.def("PrintMessage", &llvm::SourceMgr::PrintMessage)
                //.def("PrintMessage", &llvm::SourceMgr::PrintMessage)
                //.def("GetMessage", &llvm::SourceMgr::GetMessage)
                .def(
                    "PrintIncludeStack",
                    [](llvm::SourceMgr& self, llvm::SMLoc IncludeLoc, py::BinaryIO OS) {
                        llvm::raw_py_binaryio_ostream ostream{ OS };
                        self.PrintIncludeStack(IncludeLoc, ostream);
                    },
                    py::arg("IncludeLoc"),
                    py::arg("OS")
                );
        }
    };

    template<>
    struct enum_pybinder_t<llvm::SourceMgr::DiagKind> : pybinder_t {
        using binding_t = py::enum_<llvm::SourceMgr::DiagKind>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.SourceMgr.DiagKind"sv;
        static_assert(class_pybinder_t<llvm::SourceMgr>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("SourceMgr"), "DiagKind" }
                .value("Error", llvm::SourceMgr::DiagKind::DK_Error)
                .value("Warning", llvm::SourceMgr::DiagKind::DK_Warning)
                .value("Remark", llvm::SourceMgr::DiagKind::DK_Remark)
                .value("Note", llvm::SourceMgr::DiagKind::DK_Note);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::SMFixIt> : pybinder_t {
        using binding_t = py::class_<llvm::SMFixIt>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.SMFixIt"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "SMFixIt" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("SMFixIt").cast<binding_t>()
                .def(py::self < py::self)
                .def("getText", &llvm::SMFixIt::getText)
                .def("getRange", &llvm::SMFixIt::getRange);
        }
    };

    template<>
    struct class_pybinder_t<llvm::SMDiagnostic> : pybinder_t {
        using binding_t = py::class_<llvm::SMDiagnostic>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.SMDiagnostic"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "SMDiagnostic" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("SMDiagnostic").cast<binding_t>()
                .def("getSourceMgr", &llvm::SMDiagnostic::getSourceMgr, py::return_value_policy::reference)
                .def("getLoc", &llvm::SMDiagnostic::getLoc)
                .def("getFilename", &llvm::SMDiagnostic::getFilename)
                .def("getLineNo", &llvm::SMDiagnostic::getLineNo)
                .def("getKind", &llvm::SMDiagnostic::getKind)
                .def("getMessage", &llvm::SMDiagnostic::getMessage)
                .def("getLineContents", &llvm::SMDiagnostic::getLineContents)
                .def("getRanges", &llvm::SMDiagnostic::getRanges)
                .def(
                    "print",
                    [](llvm::SMDiagnostic& self, const char* ProgName, py::BinaryIO S, bool ShowColors, bool ShowKindLabel) {
                        llvm::raw_py_binaryio_ostream ostream{ S };
                        self.print(ProgName, ostream, ShowColors, ShowKindLabel);
                    },
                    py::arg("ProgName"),
                    py::arg("S"),
                    py::arg("ShowColors") = true,
                    py::arg("ShowKindLabel") = true
                );
        }
    };

    static class_pybinder_t<llvm::SourceMgr> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::SourceMgr::DiagKind> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::SMFixIt> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::SMDiagnostic> PYLLVM_UNIQUE_NAME(_);
}
