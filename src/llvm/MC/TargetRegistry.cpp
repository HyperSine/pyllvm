#include <llvm/MC/MCAsmBackend.h>
#include <llvm/MC/MCAsmInfo.h>
#include <llvm/MC/MCCodeEmitter.h>
#include <llvm/MC/MCContext.h>
#include <llvm/MC/MCDisassembler/MCDisassembler.h>
#include <llvm/MC/MCInstrAnalysis.h>
#include <llvm/MC/MCInstrInfo.h>
#include <llvm/MC/MCInstPrinter.h>
#include <llvm/MC/MCObjectFileInfo.h>
#include <llvm/MC/MCParser/MCTargetAsmParser.h>
#include <llvm/MC/MCRegisterInfo.h>
#include <llvm/MC/MCSubtargetInfo.h>
#include <llvm/MC/TargetRegistry.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::Target> : pybinder_t {
        using binding_t = py::class_<llvm::Target>;
        
        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Target"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "Target" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("Target").cast<binding_t>()
                .def("getNext", &llvm::Target::getNext, py::return_value_policy::reference)
                .def("getName", &llvm::Target::getName)
                .def("getShortDescription", &llvm::Target::getShortDescription)
                .def("getBackendName", &llvm::Target::getBackendName)
                .def("hasJIT", &llvm::Target::hasJIT)
                .def("hasTargetMachine", &llvm::Target::hasTargetMachine)
                .def("hasMCAsmBackend", &llvm::Target::hasMCAsmBackend)
                .def("hasMCAsmParser", &llvm::Target::hasMCAsmParser)
                .def(
                    "createMCAsmInfo",
                    &llvm::Target::createMCAsmInfo,
                    py::arg("MRI"),
                    py::arg("TheTriple"),
                    py::arg("Options")
                )
                .def(
                    "createMCObjectFileInfo",
                    &llvm::Target::createMCObjectFileInfo,
                    py::arg("Ctx"),
                    py::arg("PIC"),
                    py::arg("LargeCodeModel") = false,
                    py::keep_alive<0, 2>()
                )
                .def("createMCInstrInfo", &llvm::Target::createMCInstrInfo)
                .def(
                    "createMCInstrAnalysis",
                    &llvm::Target::createMCInstrAnalysis,
                    py::arg("Info"),
                    py::keep_alive<0, 2>()
                )
                .def("createMCRegInfo", &llvm::Target::createMCRegInfo, py::arg("TT"))
                .def(
                    "createMCSubtargetInfo",
                    &llvm::Target::createMCSubtargetInfo,
                    py::arg("TheTriple"),
                    py::arg("CPU"),
                    py::arg("Features")
                )
                //.def("createTargetMachine", &llvm::Target::createTargetMachine)
                .def(
                    "createMCAsmBackend",
                    &llvm::Target::createMCAsmBackend,
                    py::arg("STI"),
                    py::arg("MRI"),
                    py::arg("Options"),
                    py::keep_alive<0, 2>(),
                    py::keep_alive<0, 3>(),
                    py::keep_alive<0, 4>()
                )
                .def(
                    "createMCAsmParser",
                    &llvm::Target::createMCAsmParser,
                    py::arg("STI"),
                    py::arg("Parser"),
                    py::arg("MII"),
                    py::arg("Options"),
                    py::keep_alive<0, 2>(),
                    py::keep_alive<0, 3>(),
                    py::keep_alive<0, 4>()
                )
                //.def("createAsmPrinter", &llvm::Target::createAsmPrinter)
                .def(
                    "createMCDisassembler",
                    &llvm::Target::createMCDisassembler,
                    py::arg("STI"),
                    py::arg("Ctx"),
                    py::keep_alive<0, 2>(),
                    py::keep_alive<0, 3>()
                )
                .def(
                    "createMCInstPrinter",
                    &llvm::Target::createMCInstPrinter,
                    py::arg("T"),
                    py::arg("SyntaxVariant"),
                    py::arg("MAI"),
                    py::arg("MII"),
                    py::arg("MRI"),
                    py::keep_alive<0, 4>(),
                    py::keep_alive<0, 5>(),
                    py::keep_alive<0, 6>()
                )
               .def(
                   "createMCCodeEmitter",
                   &llvm::Target::createMCCodeEmitter,
                   py::arg("II"),
                   py::arg("Ctx"),
                   py::keep_alive<0, 2>(),
                   py::keep_alive<0, 3>()
               )
                //.def("createMCObjectStreamer", &llvm::Target::createMCObjectStreamer)
                //.def("createAsmStreamer", &llvm::Target::createAsmStreamer)
                //.def("createAsmTargetStreamer", &llvm::Target::createAsmTargetStreamer)
                //.def("createNullStreamer", &llvm::Target::createNullStreamer)
                //.def("createNullTargetStreamer", &llvm::Target::createNullTargetStreamer)
                //.def("createMCRelocationInfo", &llvm::Target::createMCRelocationInfo)
                //.def("createMCSymbolizer", &llvm::Target::createMCSymbolizer)
                //.def("createCustomBehaviour", &llvm::Target::createCustomBehaviour)
                //.def("createInstrPostProcess", &llvm::Target::createInstrPostProcess)
                ;
        }
    };

    template<>
    struct class_pybinder_t<llvm::TargetRegistry> : pybinder_t {
        using binding_t = py::class_<llvm::TargetRegistry>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.TargetRegistry"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "TargetRegistry" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("TargetRegistry").cast<binding_t>()
                .def_static(
                    "targets",
                    []() {
                        auto targets = llvm::TargetRegistry::targets();
                        return py::make_iterator<py::return_value_policy::reference>(targets.begin(), targets.end());
                    }
                )
                .def_static(
                    "lookupTarget",
                    [](std::string& triple) {
                        std::string err;
                        const auto* retval = llvm::TargetRegistry::lookupTarget(triple, err);
                        if (retval) {
                            return retval;
                        } else {
                            throw std::runtime_error(err);
                        }
                    },
                    py::return_value_policy::reference,
                    py::arg("Triple")
                )
                .def_static(
                    "lookupTarget",
                    [](std::string& arch_name, llvm::Triple& the_triple) {
                        std::string err;
                        const auto* retval = llvm::TargetRegistry::lookupTarget(arch_name, the_triple, err);
                        if (retval) {
                            return retval;
                        } else {
                            throw std::runtime_error(err);
                        }
                    },
                    py::return_value_policy::reference,
                    py::arg("ArchName"), py::arg("TheTriple")
                );
        }
    };

    static class_pybinder_t<llvm::Target> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::TargetRegistry> PYLLVM_UNIQUE_NAME(_);
}
