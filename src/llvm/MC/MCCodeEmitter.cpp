#include <llvm/MC/MCCodeEmitter.h>
#include <llvm/MC/MCInst.h>
#include <llvm/MC/MCSubtargetInfo.h>
#include "../Support/raw_py_binaryio_ostream.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCCodeEmitter> : pybinder_t {
        using binding_t = py::class_<llvm::MCCodeEmitter>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCCodeEmitter"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCCodeEmitter" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCCodeEmitter").cast<binding_t>()
                .def("reset", &llvm::MCCodeEmitter::reset)
                .def(
                    "emitPrefix",
                    [](llvm::MCCodeEmitter& self, const llvm::MCInst& Inst, py::BinaryIO& OS, const llvm::MCSubtargetInfo& STI) {
                        llvm::raw_py_binaryio_ostream bio{ OS };
                        self.emitPrefix(Inst, bio, STI);
                    },
                    py::arg("Inst"),
                    py::arg("OS"),
                    py::arg("STI")
                )
                // .def(
                //     "encodeInstruction",
                //     [](llvm::MCCodeEmitter& self, const llvm::MCInst& Inst, py::BinaryIO& OS, llvm::SmallVector<llvm::MCFixup> Fixups, const llvm::MCSubtargetInfo& STI) {
                //         // todo
                //     },
                //     py::arg("Inst"),
                //     py::arg("OS"),
                //     py::arg("Fixups"),
                //     py::arg("STI")
                // )
                ;
        }
    };

    static class_pybinder_t<llvm::MCCodeEmitter> PYLLVM_UNIQUE_NAME(_);
}
