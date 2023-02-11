#include <llvm/MC/MCContext.h>
#include <llvm/MC/MCDisassembler/MCDisassembler.h>
#include <llvm/MC/MCSubtargetInfo.h>
#include <llvm/Support/raw_os_ostream.h>
#include "../../../init.hpp"
#include "../../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCDisassembler> : pybinder_t {
        using binding_t = py::class_<llvm::MCDisassembler>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCDisassembler";

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCDisassembler" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCDisassembler").cast<binding_t>()
                .def(
                    "getInstruction",
                    [](llvm::MCDisassembler& self, llvm::MCInst& Instr, py::buffer Bytes, uint64_t Address) -> std::tuple<llvm::MCDisassembler::DecodeStatus, uint64_t> {
                        uint64_t inst_size = 0;

                        auto bytes_bufinfo = Bytes.request(false);
                        auto bytes_arrayref = llvm::ArrayRef<uint8_t>{ reinterpret_cast<const uint8_t*>(bytes_bufinfo.ptr), static_cast<size_t>(bytes_bufinfo.size) };

                        auto status = self.getInstruction(Instr, inst_size, bytes_arrayref, Address, llvm::nulls());

                        return std::make_tuple(status, inst_size);
                    },
                    py::arg("Inst"),
                    py::arg("Bytes"),
                    py::arg("Address")
                ).def(
                    "getInstruction",
                    [](llvm::MCDisassembler& self, llvm::MCInst& Instr, py::buffer Bytes, uint64_t Address, py::BinaryIO CStream) -> std::tuple<llvm::MCDisassembler::DecodeStatus, uint64_t> {
                        uint64_t inst_size = 0;

                        auto bytes_bufinfo = Bytes.request(false);
                        auto bytes_arrayref = llvm::ArrayRef<uint8_t>{ reinterpret_cast<const uint8_t*>(bytes_bufinfo.ptr), static_cast<size_t>(bytes_bufinfo.size) };

                        std::ostringstream oss;
                        llvm::raw_os_ostream roo{ oss };
                        py::scoped_ostream_redirect oss_redirect_guard{ oss, CStream };   // redirect `oss` to `CStream`

                        auto status = self.getInstruction(Instr, inst_size, bytes_arrayref, Address, roo);

                        return std::make_tuple(status, inst_size);
                    },
                    py::arg("Inst"),
                    py::arg("Bytes"),
                    py::arg("Address"),
                    py::arg("CStream")
                )
                //.def(
                //    "onSymbolStart",
                //    [](llvm::MCDisassembler& self, llvm::SymbolInfoTy& symbol, const py::bytes& bytes, uint64_t address) -> std::optional<llvm::MCDisassembler::DecodeStatus> {
                //        uint64_t size = 0;
                //        std::string comments_and_annotations;
                //
                //        auto bytes_view = std::string_view(bytes);
                //        auto bytes_arrayref = llvm::ArrayRef<uint8_t>{ reinterpret_cast<const uint8_t*>(bytes_view.data()), bytes_view.size() };
                //
                //        auto ss = llvm::raw_string_ostream(comments_and_annotations);
                //        auto status = self.onSymbolStart(symbol, size, bytes_arrayref, address, ss);
                //
                //        return std::make_tuple(status.hasValue() ? std::optional(status.getValue()) : std::nullopt, size, comments_and_annotations);
                //    }
                //)
                .def(
                    "tryAddingSymbolicOperand",
                    &llvm::MCDisassembler::tryAddingSymbolicOperand,
                    py::arg("Inst"),
                    py::arg("Value"),
                    py::arg("Address"),
                    py::arg("IsBranch"),
                    py::arg("Offset"),
                    py::arg("OpSize"),
                    py::arg("InstSize")
                )
                .def(
                    "tryAddingPcLoadReferenceComment",
                    &llvm::MCDisassembler::tryAddingPcLoadReferenceComment,
                    py::arg("Value"),
                    py::arg("Address")
                )
                //.def("setSymbolizer", llvm::MCDisassembler::setSymbolizer)
                .def("getContext", &llvm::MCDisassembler::getContext, py::return_value_policy::reference)
                .def("getSubtargetInfo", &llvm::MCDisassembler::getSubtargetInfo, py::return_value_policy::reference);
        }
    };

    template<>
    struct enum_pybinder_t<llvm::MCDisassembler::DecodeStatus> : pybinder_t {
        using binding_t = py::enum_<llvm::MCDisassembler::DecodeStatus>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCDisassembler.DecodeStatus";
        static_assert(class_pybinder_t<llvm::MCDisassembler>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("MCDisassembler"), "DecodeStatus" }
                .value("Fail", llvm::MCDisassembler::DecodeStatus::Fail)
                .value("SoftFail", llvm::MCDisassembler::DecodeStatus::SoftFail)
                .value("Success", llvm::MCDisassembler::DecodeStatus::Success);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    static class_pybinder_t<llvm::MCDisassembler> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCDisassembler::DecodeStatus> PYLLVM_UNIQUE_NAME(_);
}
