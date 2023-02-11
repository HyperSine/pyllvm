#include <llvm/MC/MCInst.h>
#include <llvm/MC/MCInstrDesc.h>
#include <llvm/MC/MCRegisterInfo.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCOperandInfo> : pybinder_t {
        using binding_t = py::class_<llvm::MCOperandInfo>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCOperandInfo"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCOperandInfo" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCOperandInfo").cast<binding_t>()
                .def_readwrite("RegClass", &llvm::MCOperandInfo::RegClass)
                .def_readwrite("Flags", &llvm::MCOperandInfo::Flags)
                .def_readwrite("OperandType", &llvm::MCOperandInfo::OperandType)
                .def_readwrite("Constraints", &llvm::MCOperandInfo::Constraints)
                .def("isLookupPtrRegClass", &llvm::MCOperandInfo::isLookupPtrRegClass)
                .def("isPredicate", &llvm::MCOperandInfo::isPredicate)
                .def("isOptionalDef", &llvm::MCOperandInfo::isOptionalDef)
                .def("isBranchTarget", &llvm::MCOperandInfo::isBranchTarget)
                .def("isGenericType", &llvm::MCOperandInfo::isGenericType)
                .def("getGenericTypeIndex", &llvm::MCOperandInfo::getGenericTypeIndex)
                .def("isGenericImm", &llvm::MCOperandInfo::isGenericImm)
                .def("getGenericImmIndex", &llvm::MCOperandInfo::getGenericImmIndex);
        }
    };

    template<>
    struct class_pybinder_t<llvm::MCInstrDesc> : pybinder_t {
        using binding_t = py::class_<llvm::MCInstrDesc>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCInstrDesc"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCInstrDesc" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCInstrDesc").cast<binding_t>()
                .def_property_readonly("Opcode", &llvm::MCInstrDesc::getOpcode)
                .def_property_readonly("NumOperands", &llvm::MCInstrDesc::getNumOperands)
                .def_property_readonly("NumDefs", &llvm::MCInstrDesc::getNumDefs)
                .def_property_readonly("Size", &llvm::MCInstrDesc::getSize)
                .def_property_readonly("SchedClass", &llvm::MCInstrDesc::getSchedClass)
                .def_property_readonly("Flags", &llvm::MCInstrDesc::getFlags)
                //.def_readonly("TSFlags", &llvm::MCInstrDesc::TSFlags)
                .def_property_readonly(
                    "ImplicitUses",
                    [](llvm::MCInstrDesc& self) {
                        static_assert(std::is_same_v<std::decay_t<decltype(self.ImplicitUses[0])>, uint16_t>);
                        return std::vector<uint16_t>(self.ImplicitUses, self.ImplicitUses + self.getNumImplicitUses());
                    }
                )
                .def_property_readonly(
                    "ImplicitDefs",
                    [](llvm::MCInstrDesc& self) {
                        static_assert(std::is_same_v<std::decay_t<decltype(self.ImplicitDefs[0])>, uint16_t>);
                        return std::vector<uint16_t>(self.ImplicitDefs, self.ImplicitDefs + self.getNumImplicitDefs());
                    }
                )
                //.def_property_readonly("OpInfo", &llvm::MCInstrDesc::OpInfo)
                //.def("getOperandConstraint", &llvm::MCInstrDesc::getOperandConstraint)
                //.def("getOpcode", &llvm::MCInstrDesc::getOpcode)              // exposed by readonly property `Opcode`
                //.def("getNumOperands", &llvm::MCInstrDesc::getNumOperands)    // exposed by readonly property `NumOperands`
                .def_property_readonly(
                    "OperandInfos",
                    py::cpp_function(
                        [](llvm::MCInstrDesc& self) {
                            auto op_infos = std::vector<const llvm::MCOperandInfo*>(self.getNumOperands());
                            std::transform(self.opInfo_begin(), self.opInfo_end(), std::back_inserter(op_infos), [](const auto& x) { return std::addressof(x); });
                            return op_infos;
                        },
                        py::return_value_policy::reference_internal
                    )
                )
                //.def("getNumDefs", &llvm::MCInstrDesc::getNumDefs)        // exposed by readonly property `NumDefs`
                //.def("getFlags", &llvm::MCInstrDesc::getFlags)            // exposed by readonly property `Flags`
                .def("isPreISelOpcode", &llvm::MCInstrDesc::isPreISelOpcode)
                .def("isVariadic", &llvm::MCInstrDesc::isVariadic)
                .def("hasOptionalDef", &llvm::MCInstrDesc::hasOptionalDef)
                .def("isPseudo", &llvm::MCInstrDesc::isPseudo)
                .def("isReturn", &llvm::MCInstrDesc::isReturn)
                .def("isAdd", &llvm::MCInstrDesc::isAdd)
                .def("isTrap", &llvm::MCInstrDesc::isTrap)
                .def("isMoveReg", &llvm::MCInstrDesc::isMoveReg)
                .def("isCall", &llvm::MCInstrDesc::isCall)
                .def("isBarrier", &llvm::MCInstrDesc::isBarrier)
                .def("isTerminator", &llvm::MCInstrDesc::isTerminator)
                .def("isBranch", &llvm::MCInstrDesc::isBranch)
                .def("isIndirectBranch", &llvm::MCInstrDesc::isIndirectBranch)
                .def("isConditionalBranch", &llvm::MCInstrDesc::isConditionalBranch)
                .def("isUnconditionalBranch", &llvm::MCInstrDesc::isUnconditionalBranch)
                .def("mayAffectControlFlow", &llvm::MCInstrDesc::mayAffectControlFlow, py::arg("MI"), py::arg("RI"))
                .def("isPredicable", &llvm::MCInstrDesc::isPredicable)
                .def("isCompare", &llvm::MCInstrDesc::isCompare)
                .def("isMoveImmediate", &llvm::MCInstrDesc::isMoveImmediate)
                .def("isBitcast", &llvm::MCInstrDesc::isBitcast)
                .def("isSelect", &llvm::MCInstrDesc::isSelect)
                .def("isNotDuplicable", &llvm::MCInstrDesc::isNotDuplicable)
                .def("hasDelaySlot", &llvm::MCInstrDesc::hasDelaySlot)
                .def("canFoldAsLoad", &llvm::MCInstrDesc::canFoldAsLoad)
                .def("isRegSequenceLike", &llvm::MCInstrDesc::isRegSequenceLike)
                .def("isExtractSubregLike", &llvm::MCInstrDesc::isExtractSubregLike)
                .def("isInsertSubregLike", &llvm::MCInstrDesc::isInsertSubregLike)
                .def("isConvergent", &llvm::MCInstrDesc::isConvergent)
                .def("variadicOpsAreDefs", &llvm::MCInstrDesc::variadicOpsAreDefs)
                .def("isAuthenticated", &llvm::MCInstrDesc::isAuthenticated)
                .def("mayLoad", &llvm::MCInstrDesc::mayLoad)
                .def("mayStore", &llvm::MCInstrDesc::mayStore)
                .def("mayRaiseFPException", &llvm::MCInstrDesc::mayRaiseFPException)
                .def("hasUnmodeledSideEffects", &llvm::MCInstrDesc::hasUnmodeledSideEffects)
                .def("isCommutable", &llvm::MCInstrDesc::isCommutable)
                .def("isConvertibleTo3Addr", &llvm::MCInstrDesc::isConvertibleTo3Addr)
                .def("usesCustomInsertionHook", &llvm::MCInstrDesc::usesCustomInsertionHook)
                .def("hasPostISelHook", &llvm::MCInstrDesc::hasPostISelHook)
                .def("isRematerializable", &llvm::MCInstrDesc::isRematerializable)
                .def("isAsCheapAsAMove", &llvm::MCInstrDesc::isAsCheapAsAMove)
                .def("hasExtraSrcRegAllocReq", &llvm::MCInstrDesc::hasExtraSrcRegAllocReq)
                .def("hasExtraDefRegAllocReq", &llvm::MCInstrDesc::hasExtraDefRegAllocReq)
                //.def("getImplicitUses", &llvm::MCInstrDesc::getImplicitUses)      // exposed by readonly property `ImplicitUses`
                .def("getNumImplicitUses", &llvm::MCInstrDesc::getNumImplicitUses)
                //.def("getImplicitDefs", &llvm::MCInstrDesc::getImplicitDefs)
                .def("getNumImplicitDefs", &llvm::MCInstrDesc::getNumImplicitDefs)  // exposed by readonly property `ImplicitDefs`
                .def("hasImplicitUseOfPhysReg", &llvm::MCInstrDesc::hasImplicitUseOfPhysReg, py::arg("Reg"))
                .def("hasImplicitDefOfPhysReg", &llvm::MCInstrDesc::hasImplicitDefOfPhysReg, py::arg("Reg"), py::arg("MRI"))
                //.def("getSchedClass", &llvm::MCInstrDesc::getSchedClass)  // exposed by readonly property `SchedClass`
                //.def("getSize", &llvm::MCInstrDesc::getSize)              // exposed by readonly property `Size`
                .def("findFirstPredOperandIdx", &llvm::MCInstrDesc::findFirstPredOperandIdx)
                .def("hasDefOfPhysReg", &llvm::MCInstrDesc::hasDefOfPhysReg, py::arg("MI"), py::arg("Reg"), py::arg("RI"));
        }
    };

    static class_pybinder_t<llvm::MCOperandInfo> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::MCInstrDesc> PYLLVM_UNIQUE_NAME(_);
}
