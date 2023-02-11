#include <llvm/MC/MCRegister.h>
#include <llvm/MC/MCRegisterInfo.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCRegisterClass> : pybinder_t {
        using binding_t = py::class_<llvm::MCRegisterClass>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCRegisterClass"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCRegisterClass" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCRegisterClass").cast<binding_t>()
                .def("__contains__", py::overload_cast<llvm::MCRegister>(&llvm::MCRegisterClass::contains, py::const_))
                .def(
                    "__getitem__",
                    [](llvm::MCRegisterClass& self, unsigned i) -> llvm::MCRegister {
                        if (i < self.getNumRegs()) {
                            return llvm::MCRegister(self.getRegister(i));
                        } else {
                            throw py::index_error();
                        }
                    },
                    py::arg("i")
                )
                .def(
                    "__iter__",
                    [](llvm::MCRegisterClass& self) {
                        return py::make_iterator(self.begin(), self.end());
                    }
                )
                .def("__len__", &llvm::MCRegisterClass::getNumRegs)
                .def("getID", &llvm::MCRegisterClass::getID)
                .def("getNumRegs", &llvm::MCRegisterClass::getNumRegs)
                .def("getRegister", &llvm::MCRegisterClass::getRegister)
                .def("getSizeInBits", &llvm::MCRegisterClass::getSizeInBits)
                .def("getCopyCost", &llvm::MCRegisterClass::getCopyCost)
                .def("isAllocatable", &llvm::MCRegisterClass::isAllocatable);
        }
    };

    template<>
    struct class_pybinder_t<llvm::MCRegisterDesc> : pybinder_t {
        using binding_t = py::class_<llvm::MCRegisterDesc>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCRegisterDesc"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCRegisterDesc" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCRegisterDesc").cast<binding_t>()
                .def_readwrite("Name", &llvm::MCRegisterDesc::Name)
                .def_readwrite("SubRegs", &llvm::MCRegisterDesc::SubRegs)
                .def_readwrite("SuperRegs", &llvm::MCRegisterDesc::SuperRegs)
                .def_readwrite("SubRegIndices", &llvm::MCRegisterDesc::SubRegIndices)
                .def_readwrite("RegUnits", &llvm::MCRegisterDesc::RegUnits)
                .def_readwrite("RegUnitLaneMasks", &llvm::MCRegisterDesc::RegUnitLaneMasks);
        }
    };

    template<>
    struct class_pybinder_t<llvm::MCRegisterInfo> : pybinder_t {
        using binding_t = py::class_<llvm::MCRegisterInfo>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCRegisterInfo"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCRegisterInfo" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCRegisterInfo").cast<binding_t>()
                .def(
                    "__getitem__",
                    [](llvm::MCRegisterInfo& self, llvm::MCRegister reg_no) {
                        if (reg_no < self.getNumRegs()) {
                            return self[reg_no];
                        } else {
                            throw py::index_error();
                        }
                    },
                    py::return_value_policy::reference_internal
                )
                    //.def("InitMCRegisterInfo", &llvm::MCRegisterInfo::InitMCRegisterInfo)             // explicit marked as *DO NOT USE* by LLVM.
                    //.def("mapLLVMRegsToDwarfRegs", &llvm::MCRegisterInfo::mapLLVMRegsToDwarfRegs)     // explicit marked as *DO NOT USE* by LLVM.
                .def("mapLLVMRegToSEHReg", &llvm::MCRegisterInfo::mapLLVMRegToSEHReg, py::arg("LLVMReg"), py::arg("SEHReg"))
                .def("mapLLVMRegToCVReg", &llvm::MCRegisterInfo::mapLLVMRegToSEHReg, py::arg("LLVMReg"), py::arg("CVReg"))
                .def("getRARegister", &llvm::MCRegisterInfo::getRARegister)
                .def("getProgramCounter", &llvm::MCRegisterInfo::getProgramCounter)
                .def("getSubReg", &llvm::MCRegisterInfo::getSubReg, py::arg("Reg"), py::arg("Idx"))
                .def("getMatchingSuperReg", &llvm::MCRegisterInfo::getMatchingSuperReg, py::arg("Reg"), py::arg("SubIdx"), py::arg("RC"))
                .def("getSubRegIndex", &llvm::MCRegisterInfo::getSubRegIndex, py::arg("RegNo"), py::arg("SubRegNo"))
                .def("getSubRegIdxSize", &llvm::MCRegisterInfo::getSubRegIdxSize)
                .def("getSubRegIdxOffset", &llvm::MCRegisterInfo::getSubRegIdxOffset)
                .def("getName", &llvm::MCRegisterInfo::getName)
                .def("getNumRegs", &llvm::MCRegisterInfo::getNumRegs)
                .def("getNumSubRegIndices", &llvm::MCRegisterInfo::getNumSubRegIndices)
                .def("getNumRegUnits", &llvm::MCRegisterInfo::getNumRegUnits)
                .def("getDwarfRegNum", &llvm::MCRegisterInfo::getDwarfRegNum)
                .def(
                    "getLLVMRegNum",
                    [](llvm::MCRegisterInfo& self, unsigned RegNum, bool isEH) -> std::optional<unsigned> {
                        auto r = self.getLLVMRegNum(RegNum, isEH);
                        return r.hasValue() ? std::optional(r.getValue()) : std::nullopt;
                    }
                )
                .def("getDwarfRegNumFromDwarfEHRegNum", &llvm::MCRegisterInfo::getDwarfRegNumFromDwarfEHRegNum)
                .def("getSEHRegNum", &llvm::MCRegisterInfo::getSEHRegNum)
                .def("getCodeViewRegNum", &llvm::MCRegisterInfo::getCodeViewRegNum)
                    //.def(
                    //    "regclasses",
                    //    [](llvm::MCRegisterInfo& self) {
                    //        return py::make_iterator(self.regclass_begin(), self.regclass_end());
                    //    }
                    //)
                .def("getNumRegClasses", &llvm::MCRegisterInfo::getNumRegClasses)
                .def("getRegClass", &llvm::MCRegisterInfo::getRegClass, py::return_value_policy::reference_internal)
                .def("getRegClassName", &llvm::MCRegisterInfo::getRegClassName)
                .def("getEncodingValue", &llvm::MCRegisterInfo::getEncodingValue)
                .def("isSubRegister", &llvm::MCRegisterInfo::isSubRegister, py::arg("RegA"), py::arg("RegB"))
                .def("isSuperRegister", &llvm::MCRegisterInfo::isSuperRegister, py::arg("RegA"), py::arg("RegB"))
                .def("isSubRegisterEq", &llvm::MCRegisterInfo::isSubRegisterEq, py::arg("RegA"), py::arg("RegB"))
                .def("isSuperRegisterEq", &llvm::MCRegisterInfo::isSuperRegisterEq, py::arg("RegA"), py::arg("RegB"))
                .def("isSuperOrSubRegisterEq", &llvm::MCRegisterInfo::isSuperOrSubRegisterEq, py::arg("RegA"), py::arg("RegB"));
        }
    };

    static class_pybinder_t<llvm::MCRegisterClass> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::MCRegisterDesc> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::MCRegisterInfo> PYLLVM_UNIQUE_NAME(_);
}
