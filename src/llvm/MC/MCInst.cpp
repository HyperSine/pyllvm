#include <llvm/MC/MCInst.h>
#include <llvm/MC/MCRegisterInfo.h>
#include "../Support/raw_py_binaryio_ostream.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCOperand> : pybinder_t {
        using binding_t = py::class_<llvm::MCOperand>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCOperand"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCOperand" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCOperand").cast<binding_t>()
                .def(py::init<>())
                .def("isValid", &llvm::MCOperand::isValid)
                .def("isReg", &llvm::MCOperand::isReg)
                .def("isImm", &llvm::MCOperand::isImm)
                .def("isSFPImm", &llvm::MCOperand::isSFPImm)
                .def("isDFPImm", &llvm::MCOperand::isDFPImm)
                .def("isExpr", &llvm::MCOperand::isExpr)
                .def("isInst", &llvm::MCOperand::isInst)
                .def_property("Reg", &llvm::MCOperand::getReg, &llvm::MCOperand::setReg)
                .def_property("Imm", &llvm::MCOperand::getImm, &llvm::MCOperand::setImm)
                .def_property("SFPImm", &llvm::MCOperand::getSFPImm, &llvm::MCOperand::setSFPImm)
                .def_property("DFPImm", &llvm::MCOperand::getDFPImm, &llvm::MCOperand::setDFPImm)
                //.def_property("Expr", &llvm::MCOperand::getExpr, &llvm::MCOperand::setExpr)
                //.def_property("Inst", &llvm::MCOperand::getInst, &llvm::MCOperand::setInst)
                .def_static("createReg", &llvm::MCOperand::createReg, py::arg("Reg"))
                .def_static("createImm", &llvm::MCOperand::createImm, py::arg("Val"))
                .def_static("createSFPImm", &llvm::MCOperand::createSFPImm, py::arg("Val"))
                .def_static("createDFPImm", &llvm::MCOperand::createDFPImm, py::arg("Val"))
                //.def_static("createExpr", &llvm::MCOperand::createExpr)
                //.def_static("createInst", &llvm::MCOperand::createInst)
                .def(
                    "print",
                    [](llvm::MCOperand& self, py::BinaryIO& OS, py::nullable_ptr<llvm::MCRegisterInfo> RegInfo) {
                        llvm::raw_py_binaryio_ostream bio{ OS };
                        self.print(bio, RegInfo.value);
                    },
                    py::arg("OS"),
                    py::arg("RegInfo") = nullptr
                )
                .def("isBareSymbolRef", &llvm::MCOperand::isBareSymbolRef)
                .def(
                    "evaluateAsConstantImm",
                    [](llvm::MCOperand& self) -> std::optional<int64_t> {
                        int64_t imm = 0;
                        return self.evaluateAsConstantImm(imm) ? std::optional(imm) : std::nullopt;
                    }
                );
        }
    };

    template<>
    struct class_pybinder_t<llvm::MCInst> : pybinder_t {
        using binding_t = py::class_<llvm::MCInst>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCInst"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCInst" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCInst").cast<binding_t>()
                .def(py::init<>())
                .def_property("Opcode", &llvm::MCInst::getOpcode, &llvm::MCInst::setOpcode)
                .def_property("Flags", &llvm::MCInst::getFlags, &llvm::MCInst::setFlags)
                .def_property("Loc", &llvm::MCInst::getLoc, &llvm::MCInst::setLoc)
                .def_property_readonly(
                    "Operands",
                    [](llvm::MCInst& self) {
                        return std::vector<std::reference_wrapper<llvm::MCOperand>>(self.begin(), self.end());
                    },
                    py::return_value_policy::reference_internal
                )
                .def(
                    "getOperand",
                    [](llvm::MCInst& self, unsigned i) -> llvm::MCOperand& {
                        return i < self.size() ? self.getOperand(i) : throw py::index_error();
                    },
                    py::return_value_policy::reference_internal
                )
                .def("getNumOperands", &llvm::MCInst::getNumOperands)
                    //.def("addOperand", &llvm::MCInst::addOperand, py::arg("Op"))
                .def("clear", &llvm::MCInst::clear)
                .def(
                    "print",
                    [](llvm::MCInst& self, py::BinaryIO& OS, llvm::MCRegisterInfo* register_info) {
                        llvm::raw_py_binaryio_ostream bio{ OS };
                        self.print(bio, register_info);
                    },
                    py::arg("OS"),
                    py::arg("RegInfo") = nullptr
                );
        }
    };

    static class_pybinder_t<llvm::MCOperand> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::MCInst> PYLLVM_UNIQUE_NAME(_);
}
