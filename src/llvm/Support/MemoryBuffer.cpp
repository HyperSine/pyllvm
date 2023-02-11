#include <llvm/Support/MemoryBuffer.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"
#include "../../CxxWrapper.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MemoryBuffer> : pybinder_t {
        using binding_t = py::class_<llvm::MemoryBuffer>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MemoryBuffer"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MemoryBuffer" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MemoryBuffer").cast<binding_t>()
                .def("getBufferKind", &llvm::MemoryBuffer::getBufferKind)
                //.def("getMemBufferRef", &llvm::MemoryBuffer::getMemBufferRef)
                .def(
                    "getBufferStart",
                    [](llvm::MemoryBuffer& self) -> std::optional<py::capsule> {
                        if (const auto* ptr = self.getBufferStart()) {
                            return py::capsule{ ptr };
                        } else {
                            return std::nullopt;
                        }
                    }
                )
                .def(
                    "getBufferEnd",
                    [](llvm::MemoryBuffer& self) -> std::optional<py::capsule> {
                        if (const auto* ptr = self.getBufferEnd()) {
                            return py::capsule{ ptr };
                        } else {
                            return std::nullopt;
                        }
                    }
                )
                .def("getBufferSize", &llvm::MemoryBuffer::getBufferSize)
                .def(
                    "getBuffer",
                    [](llvm::MemoryBuffer& self) -> py::memoryview {
                        auto buf = self.getBuffer();
                        return py::memoryview::from_memory(static_cast<std::string_view>(buf));
                    }
                )
                .def("getBufferIdentifier", &llvm::MemoryBuffer::getBufferIdentifier)
                .def("dontNeedIfMmap", &llvm::MemoryBuffer::dontNeedIfMmap)
                .def_static(
                    "getFile",
                    [](std::string_view Filename, bool IsText, bool RequiresNullTerminator, bool IsVolatile) -> std::unique_ptr<CxxWrapper> {
                        auto maybe_membuf = llvm::MemoryBuffer::getFile(Filename, IsText, RequiresNullTerminator, IsVolatile);
                        if (maybe_membuf) {
                            using wrapper_t = CxxWrapperFor<std::unique_ptr<llvm::MemoryBuffer>>;
                            return std::make_unique<wrapper_t>(std::move(maybe_membuf.get()));
                        } else {
                            throw std::system_error(maybe_membuf.getError());
                        }
                    },
                    py::arg("Filename"),
                    py::arg("IsText") = false,
                    py::arg("RequiresNullTerminator") = true,
                    py::arg("IsVolatile") = false
                )
                .def_static(
                    "getFileSlice",
                    [](std::string_view Filename, uint64_t MapSize, uint64_t Offset, bool IsVolatile) -> std::unique_ptr<CxxWrapper> {
                        auto maybe_membuf = llvm::MemoryBuffer::getFileSlice(Filename, MapSize, Offset, IsVolatile);
                        if (maybe_membuf) {
                            using wrapper_t = CxxWrapperFor<std::unique_ptr<llvm::MemoryBuffer>>;
                            return std::make_unique<wrapper_t>(std::move(maybe_membuf.get()));
                        } else {
                            throw std::system_error(maybe_membuf.getError());
                        }
                    },
                    py::arg("Filename"),
                    py::arg("MapSize"),
                    py::arg("Offset"),
                    py::arg("IsVolatile") = false
                )
                .def_static(
                    "getFileAsStream",
                    [](std::string_view Filename) -> std::unique_ptr<CxxWrapper> {
                        auto maybe_membuf = llvm::MemoryBuffer::getFileAsStream(Filename);
                        if (maybe_membuf) {
                            using wrapper_t = CxxWrapperFor<std::unique_ptr<llvm::MemoryBuffer>>;
                            return std::make_unique<wrapper_t>(std::move(maybe_membuf.get()));
                        } else {
                            throw std::system_error(maybe_membuf.getError());
                        }
                    },
                    py::arg("Filename")
                )
                //.def_static("getOpenFileSlice", /*todo*/)
                //.def_static("getOpenFile", /*todo*/)
                //.def_static("getMemBuffer", /*todo*/)
                //.def_static("getMemBuffer", /*todo*/)
                .def_static(
                    "getMemBufferCopy",
                    [](py::buffer InputData, std::string_view BufferName) -> std::unique_ptr<CxxWrapper> {
                        auto buf_info = InputData.request(false);
                        auto membuf = llvm::MemoryBuffer::getMemBufferCopy(llvm::StringRef{ reinterpret_cast<const char*>(buf_info.ptr), static_cast<size_t>(buf_info.size) }, BufferName);

                        using wrapper_t = CxxWrapperFor<std::unique_ptr<llvm::MemoryBuffer>>;
                        return std::make_unique<wrapper_t>(std::move(membuf));
                    },
                    py::arg("InputData"),
                    py::arg("BufferName") = ""
                )
                .def_static(
                    "getSTDIN",
                    []() -> std::unique_ptr<CxxWrapper> {
                        auto maybe_stdin = llvm::MemoryBuffer::getSTDIN();
                        if (maybe_stdin) {
                            using wrapper_t = CxxWrapperFor<std::unique_ptr<llvm::MemoryBuffer>>;
                            return std::make_unique<wrapper_t>(std::move(maybe_stdin.get()));
                        } else {
                            throw std::system_error(maybe_stdin.getError());
                        }
                    }
                )
                .def_static(
                    "getFileOrSTDIN",
                    [](std::string_view Filename, bool IsText, bool RequiresNullTerminator) -> std::unique_ptr<CxxWrapper> {
                        auto maybe_stdin = llvm::MemoryBuffer::getFileOrSTDIN(Filename, IsText, RequiresNullTerminator);
                        if (maybe_stdin) {
                            using wrapper_t = CxxWrapperFor<std::unique_ptr<llvm::MemoryBuffer>>;
                            return std::make_unique<wrapper_t>(std::move(maybe_stdin.get()));
                        } else {
                            throw std::system_error(maybe_stdin.getError());
                        }
                    },
                    py::arg("Filename"),
                    py::arg("IsText") = false,
                    py::arg("RequiresNullTerminator") = true
                );
        }
    };

    template<>
    struct enum_pybinder_t<llvm::MemoryBuffer::BufferKind> : pybinder_t {
        using binding_t = py::enum_<llvm::MemoryBuffer::BufferKind>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MemoryBuffer.BufferKind"sv;
        static_assert(class_pybinder_t<llvm::MemoryBuffer>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("MemoryBuffer"), "BufferKind" }
                .value("Malloc", llvm::MemoryBuffer::BufferKind::MemoryBuffer_Malloc)
                .value("MMap", llvm::MemoryBuffer::BufferKind::MemoryBuffer_MMap);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    static class_pybinder_t<llvm::MemoryBuffer> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MemoryBuffer::BufferKind> PYLLVM_UNIQUE_NAME(_);
}