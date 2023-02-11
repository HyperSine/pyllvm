#include <llvm/ADT/Triple.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::Triple> : pybinder_t {
        using binding_t = py::class_<llvm::Triple>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Triple"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "Triple" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("Triple").cast<binding_t>()
                .def(py::init<>())
                .def(py::init<std::string_view>(), py::arg("Str"))
                .def(
                    py::init<std::string_view, std::string_view, std::string_view>(),
                    py::arg("ArchStr"),
                    py::arg("VendorStr"),
                    py::arg("OSStr"))
                .def(
                    py::init<std::string_view, std::string_view, std::string_view, std::string_view>(),
                    py::arg("ArchStr"),
                    py::arg("VendorStr"),
                    py::arg("OSStr"),
                    py::arg("EnvironmentStr")
                )
                .def(py::self == py::self)
                .def(py::self != py::self)
                .def(
                    "__hash__",
                    [](llvm::Triple& self) -> std::size_t {
                        return llvm::hash_combine(
                            self.getArch(), self.getSubArch(), self.getVendor(), self.getOS(), self.getEnvironment(), self.getObjectFormat()
                        );
                    }
                )
                .def("__str__", &llvm::Triple::str)
                .def("getArch", &llvm::Triple::getArch)
                .def(
                    "setArch",
                    [](llvm::Triple& self, llvm::Triple::ArchType Kind) {
                        self.setArch(Kind);
                    },
                    py::arg("Kind")
                )
                .def(
                    "setArch",
                    [](llvm::Triple& self, llvm::Triple::ArchType Kind, llvm::Triple::SubArchType SubArch) {
                        self.setArch(Kind, SubArch);
                    },
                    py::arg("Kind"),
                    py::arg("SubArch")
                )
                .def("getSubArch", &llvm::Triple::getSubArch)
                .def("getVendor", &llvm::Triple::getVendor)
                .def("setVendor", &llvm::Triple::setVendor)
                .def("getOS", &llvm::Triple::getOS)
                .def("setOS", &llvm::Triple::setOS)
                .def("hasEnvironment", &llvm::Triple::hasEnvironment)
                .def("getEnvironment", &llvm::Triple::getEnvironment)
                .def("setEnvironment", &llvm::Triple::setEnvironment)
                //.def("getEnvironmentVersion", &llvm::Triple::getEnvironmentVersion)
                .def("getObjectFormat", &llvm::Triple::getObjectFormat)
                .def("setObjectFormat", &llvm::Triple::setObjectFormat)
                //.def("getOSVersion", &llvm::Triple::getOSVersion)
                .def("getOSMajorVersion", &llvm::Triple::getOSMajorVersion)
                //.def("getMacOSXVersion", &llvm::Triple::getMacOSXVersion)
                //.def("getiOSVersion", &llvm::Triple::hasEnvironment)
                //.def("getWatchOSVersion", &llvm::Triple::hasEnvironment)
                .def("getTriple", &llvm::Triple::getTriple)
                //.def("getArchName", &llvm::Triple::getArchName)   // StringRef getArchName() const;
                //.def("getArchName", &llvm::Triple::getArchName)   // StringRef getArchName(ArchType Kind, SubArchType SubArch = NoSubArch) const;
                //.def("getVendorName", &llvm::Triple::getVendorName)
                //.def("getOSName", &llvm::Triple::getOSName)
                //.def("getEnvironmentName", &llvm::Triple::getEnvironmentName)
                //.def("getOSAndEnvironmentName", &llvm::Triple::getOSAndEnvironmentName)
                .def("isArch16Bit", &llvm::Triple::isArch16Bit)
                .def("isArch32Bit", &llvm::Triple::isArch32Bit)
                .def("isArch64Bit", &llvm::Triple::isArch64Bit)
                .def("isOSVersionLT", py::overload_cast<unsigned, unsigned, unsigned>(&llvm::Triple::isOSVersionLT, py::const_))
                .def("isOSVersionLT", py::overload_cast<const llvm::Triple&>(&llvm::Triple::isOSVersionLT, py::const_))
                .def("isMacOSXVersionLT", &llvm::Triple::isMacOSXVersionLT)
                .def("isMacOSX", &llvm::Triple::isMacOSX)
                .def("isiOS", &llvm::Triple::isiOS)
                .def("isTvOS", &llvm::Triple::isTvOS)
                .def("isWatchOS", &llvm::Triple::isWatchOS)
                .def("isWatchABI", &llvm::Triple::isWatchABI)
                .def("isOSzOS", &llvm::Triple::isOSzOS)
                .def("isOSDarwin", &llvm::Triple::isOSDarwin)
                .def("isSimulatorEnvironment", &llvm::Triple::isSimulatorEnvironment)
                .def("isMacCatalystEnvironment", &llvm::Triple::isMacCatalystEnvironment)
                .def("isTargetMachineMac", &llvm::Triple::isTargetMachineMac)
                .def("isOSNetBSD", &llvm::Triple::isOSNetBSD)
                .def("isOSOpenBSD", &llvm::Triple::isOSOpenBSD)
                .def("isOSFreeBSD", &llvm::Triple::isOSFreeBSD)
                .def("isOSFuchsia", &llvm::Triple::isOSFuchsia)
                .def("isOSDragonFly", &llvm::Triple::isOSDragonFly)
                .def("isOSSolaris", &llvm::Triple::isOSSolaris)
                .def("isOSIAMCU", &llvm::Triple::isOSIAMCU)
                .def("isOSUnknown", &llvm::Triple::isOSUnknown)
                .def("isGNUEnvironment", &llvm::Triple::isGNUEnvironment)
                .def("isOSContiki", &llvm::Triple::isOSContiki)
                .def("isOSHaiku", &llvm::Triple::isOSHaiku)
                .def("isOSWindows", &llvm::Triple::isOSWindows)
                .def("isKnownWindowsMSVCEnvironment", &llvm::Triple::isKnownWindowsMSVCEnvironment)
                .def("isWindowsMSVCEnvironment", &llvm::Triple::isWindowsMSVCEnvironment)
                .def("isWindowsCoreCLREnvironment", &llvm::Triple::isWindowsCoreCLREnvironment)
                .def("isWindowsItaniumEnvironment", &llvm::Triple::isWindowsItaniumEnvironment)
                .def("isWindowsCygwinEnvironment", &llvm::Triple::isWindowsCygwinEnvironment)
                .def("isWindowsGNUEnvironment", &llvm::Triple::isWindowsGNUEnvironment)
                .def("isOSCygMing", &llvm::Triple::isOSCygMing)
                .def("isOSMSVCRT", &llvm::Triple::isOSMSVCRT)
                .def("isOSNaCl", &llvm::Triple::isOSNaCl)
                .def("isOSLinux", &llvm::Triple::isOSLinux)
                .def("isOSKFreeBSD", &llvm::Triple::isOSKFreeBSD)
                .def("isOSHurd", &llvm::Triple::isOSHurd)
                .def("isOSWASI", &llvm::Triple::isOSWASI)
                .def("isOSEmscripten", &llvm::Triple::isOSEmscripten)
                .def("isOSGlibc", &llvm::Triple::isOSGlibc)
                .def("isOSAIX", &llvm::Triple::isOSAIX)
                .def("isOSBinFormatELF", &llvm::Triple::isOSBinFormatELF)
                .def("isOSBinFormatCOFF", &llvm::Triple::isOSBinFormatCOFF)
                .def("isOSBinFormatGOFF", &llvm::Triple::isOSBinFormatGOFF)
                .def("isOSBinFormatMachO", &llvm::Triple::isOSBinFormatMachO)
                .def("isOSBinFormatWasm", &llvm::Triple::isOSBinFormatWasm)
                .def("isOSBinFormatXCOFF", &llvm::Triple::isOSBinFormatXCOFF)
                .def("isPS4", &llvm::Triple::isPS4)
                .def("isPS5", &llvm::Triple::isPS5)
                .def("isPS", &llvm::Triple::isPS)
                .def("isAndroid", &llvm::Triple::isAndroid)
                .def("isAndroidVersionLT", &llvm::Triple::isAndroidVersionLT)
                .def("isMusl", &llvm::Triple::isMusl)
                .def("isSPIR", &llvm::Triple::isSPIR)
                .def("isSPIRV", &llvm::Triple::isSPIRV)
                .def("isNVPTX", &llvm::Triple::isNVPTX)
                .def("isAMDGCN", &llvm::Triple::isAMDGCN)
                .def("isAMDGPU", &llvm::Triple::isAMDGPU)
                .def("isThumb", &llvm::Triple::isThumb)
                .def("isARM", &llvm::Triple::isARM)
                .def("isTargetEHABICompatible", &llvm::Triple::isTargetEHABICompatible)
                .def("isArmT32", &llvm::Triple::isArmT32)
                .def("isArmMClass", &llvm::Triple::isArmMClass)
                .def("isAArch64", py::overload_cast<>(&llvm::Triple::isAArch64, py::const_))
                .def("isAArch64", py::overload_cast<int>(&llvm::Triple::isAArch64, py::const_), py::arg("PointerWidth"))
                .def("isMIPS32", &llvm::Triple::isMIPS32)
                .def("isMIPS64", &llvm::Triple::isMIPS64)
                .def("isMIPS", &llvm::Triple::isMIPS)
                .def("isPPC", &llvm::Triple::isPPC)
                .def("isPPC32", &llvm::Triple::isPPC32)
                .def("isPPC64", &llvm::Triple::isPPC64)
                .def("isRISCV", &llvm::Triple::isRISCV)
                .def("isSystemZ", &llvm::Triple::isSystemZ)
                .def("isX86", &llvm::Triple::isX86)
                .def("isVE", &llvm::Triple::isVE)
                .def("isWasm", &llvm::Triple::isWasm)
                .def("isCSKY", &llvm::Triple::isCSKY)
                .def("isArm64e", &llvm::Triple::isArm64e)
                .def("isX32", &llvm::Triple::isX32)
                .def("supportsCOMDAT", &llvm::Triple::supportsCOMDAT)
                .def("hasDefaultEmulatedTLS", &llvm::Triple::hasDefaultEmulatedTLS)
                .def("hasDefaultDataSections", &llvm::Triple::hasDefaultDataSections)
                .def("hasDLLImportExport", &llvm::Triple::hasDLLImportExport)
                .def("get32BitArchVariant", &llvm::Triple::get32BitArchVariant)
                .def("get64BitArchVariant", &llvm::Triple::get64BitArchVariant)
                .def("getBigEndianArchVariant", &llvm::Triple::getBigEndianArchVariant)
                .def("getLittleEndianArchVariant", &llvm::Triple::getLittleEndianArchVariant)
                .def("getARMCPUForArch", &llvm::Triple::getARMCPUForArch)
                .def("isLittleEndian", &llvm::Triple::isLittleEndian)
                .def("isCompatibleWith", &llvm::Triple::isCompatibleWith)
                .def("merge", &llvm::Triple::merge)
                //.def("getMinimumSupportedOSVersion", &llvm::Triple::getMinimumSupportedOSVersion)
                .def_static("normalize", py::overload_cast<llvm::StringRef>(&llvm::Triple::normalize));
        }
    };

    template<>
    struct enum_pybinder_t<llvm::Triple::ArchType> : pybinder_t {
        using binding_t = py::enum_<llvm::Triple::ArchType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Triple.ArchType"sv;
        static_assert(class_pybinder_t<llvm::Triple>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("Triple"), "ArchType" }
                .value("UnknownArch", llvm::Triple::ArchType::UnknownArch)
                .value("arm", llvm::Triple::ArchType::arm)
                .value("armeb", llvm::Triple::ArchType::armeb)
                .value("aarch64", llvm::Triple::ArchType::aarch64)
                .value("aarch64_be", llvm::Triple::ArchType::aarch64_be)
                .value("aarch64_32", llvm::Triple::ArchType::aarch64_32)
                .value("arc", llvm::Triple::ArchType::arc)
                .value("avr", llvm::Triple::ArchType::avr)
                .value("bpfel", llvm::Triple::ArchType::bpfel)
                .value("bpfeb", llvm::Triple::ArchType::bpfeb)
                .value("csky", llvm::Triple::ArchType::csky)
                .value("hexagon", llvm::Triple::ArchType::hexagon)
                .value("m68k", llvm::Triple::ArchType::m68k)
                .value("mips", llvm::Triple::ArchType::mips)
                .value("mipsel", llvm::Triple::ArchType::mipsel)
                .value("mips64", llvm::Triple::ArchType::mips64)
                .value("mips64el", llvm::Triple::ArchType::mips64el)
                .value("msp430", llvm::Triple::ArchType::msp430)
                .value("ppc", llvm::Triple::ArchType::ppc)
                .value("ppcle", llvm::Triple::ArchType::ppcle)
                .value("ppc64", llvm::Triple::ArchType::ppc64)
                .value("ppc64le", llvm::Triple::ArchType::ppc64le)
                .value("r600", llvm::Triple::ArchType::r600)
                .value("amdgcn", llvm::Triple::ArchType::amdgcn)
                .value("riscv32", llvm::Triple::ArchType::riscv32)
                .value("riscv64", llvm::Triple::ArchType::riscv64)
                .value("sparc", llvm::Triple::ArchType::sparc)
                .value("sparcv9", llvm::Triple::ArchType::sparcv9)
                .value("sparcel", llvm::Triple::ArchType::sparcel)
                .value("systemz", llvm::Triple::ArchType::systemz)
                .value("tce", llvm::Triple::ArchType::tce)
                .value("tcele", llvm::Triple::ArchType::tcele)
                .value("thumb", llvm::Triple::ArchType::thumb)
                .value("thumbeb", llvm::Triple::ArchType::thumbeb)
                .value("x86", llvm::Triple::ArchType::x86)
                .value("x86_64", llvm::Triple::ArchType::x86_64)
                .value("xcore", llvm::Triple::ArchType::xcore)
                .value("nvptx", llvm::Triple::ArchType::nvptx)
                .value("nvptx64", llvm::Triple::ArchType::nvptx64)
                .value("le32", llvm::Triple::ArchType::le32)
                .value("le64", llvm::Triple::ArchType::le64)
                .value("amdil", llvm::Triple::ArchType::amdil)
                .value("amdil64", llvm::Triple::ArchType::amdil64)
                .value("hsail", llvm::Triple::ArchType::hsail)
                .value("hsail64", llvm::Triple::ArchType::hsail64)
                .value("spir", llvm::Triple::ArchType::spir)
                .value("spir64", llvm::Triple::ArchType::spir64)
                .value("spirv32", llvm::Triple::ArchType::spirv32)
                .value("spirv64", llvm::Triple::ArchType::spirv64)
                .value("kalimba", llvm::Triple::ArchType::kalimba)
                .value("shave", llvm::Triple::ArchType::shave)
                .value("lanai", llvm::Triple::ArchType::lanai)
                .value("wasm32", llvm::Triple::ArchType::wasm32)
                .value("wasm64", llvm::Triple::ArchType::wasm64)
                .value("renderscript32", llvm::Triple::ArchType::renderscript32)
                .value("renderscript64", llvm::Triple::ArchType::renderscript64)
                .value("ve", llvm::Triple::ArchType::ve)
                .value("LastArchType", llvm::Triple::ArchType::LastArchType);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::Triple::SubArchType> : pybinder_t {
        using binding_t = py::enum_<llvm::Triple::SubArchType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Triple.SubArchType"sv;
        static_assert(class_pybinder_t<llvm::Triple>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("Triple"), "SubArchType" }
                .value("NoSubArch", llvm::Triple::SubArchType::NoSubArch)
                .value("ARMSubArch_v9_3a", llvm::Triple::SubArchType::ARMSubArch_v9_3a)
                .value("ARMSubArch_v9_2a", llvm::Triple::SubArchType::ARMSubArch_v9_2a)
                .value("ARMSubArch_v9_1a", llvm::Triple::SubArchType::ARMSubArch_v9_1a)
                .value("ARMSubArch_v9", llvm::Triple::SubArchType::ARMSubArch_v9)
                .value("ARMSubArch_v8_8a", llvm::Triple::SubArchType::ARMSubArch_v8_8a)
                .value("ARMSubArch_v8_7a", llvm::Triple::SubArchType::ARMSubArch_v8_7a)
                .value("ARMSubArch_v8_6a", llvm::Triple::SubArchType::ARMSubArch_v8_6a)
                .value("ARMSubArch_v8_5a", llvm::Triple::SubArchType::ARMSubArch_v8_5a)
                .value("ARMSubArch_v8_4a", llvm::Triple::SubArchType::ARMSubArch_v8_4a)
                .value("ARMSubArch_v8_3a", llvm::Triple::SubArchType::ARMSubArch_v8_3a)
                .value("ARMSubArch_v8_2a", llvm::Triple::SubArchType::ARMSubArch_v8_2a)
                .value("ARMSubArch_v8_1a", llvm::Triple::SubArchType::ARMSubArch_v8_1a)
                .value("ARMSubArch_v8", llvm::Triple::SubArchType::ARMSubArch_v8)
                .value("ARMSubArch_v8r", llvm::Triple::SubArchType::ARMSubArch_v8r)
                .value("ARMSubArch_v8m_baseline", llvm::Triple::SubArchType::ARMSubArch_v8m_baseline)
                .value("ARMSubArch_v8m_mainline", llvm::Triple::SubArchType::ARMSubArch_v8m_mainline)
                .value("ARMSubArch_v8_1m_mainline", llvm::Triple::SubArchType::ARMSubArch_v8_1m_mainline)
                .value("ARMSubArch_v7", llvm::Triple::SubArchType::ARMSubArch_v7)
                .value("ARMSubArch_v7em", llvm::Triple::SubArchType::ARMSubArch_v7em)
                .value("ARMSubArch_v7m", llvm::Triple::SubArchType::ARMSubArch_v7m)
                .value("ARMSubArch_v7s", llvm::Triple::SubArchType::ARMSubArch_v7s)
                .value("ARMSubArch_v7k", llvm::Triple::SubArchType::ARMSubArch_v7k)
                .value("ARMSubArch_v7ve", llvm::Triple::SubArchType::ARMSubArch_v7ve)
                .value("ARMSubArch_v6", llvm::Triple::SubArchType::ARMSubArch_v6)
                .value("ARMSubArch_v6m", llvm::Triple::SubArchType::ARMSubArch_v6m)
                .value("ARMSubArch_v6k", llvm::Triple::SubArchType::ARMSubArch_v6k)
                .value("ARMSubArch_v6t2", llvm::Triple::SubArchType::ARMSubArch_v6t2)
                .value("ARMSubArch_v5", llvm::Triple::SubArchType::ARMSubArch_v5)
                .value("ARMSubArch_v5te", llvm::Triple::SubArchType::ARMSubArch_v5te)
                .value("ARMSubArch_v4t", llvm::Triple::SubArchType::ARMSubArch_v4t)
                .value("AArch64SubArch_arm64e", llvm::Triple::SubArchType::AArch64SubArch_arm64e)
                .value("KalimbaSubArch_v3", llvm::Triple::SubArchType::KalimbaSubArch_v3)
                .value("KalimbaSubArch_v4", llvm::Triple::SubArchType::KalimbaSubArch_v4)
                .value("KalimbaSubArch_v5", llvm::Triple::SubArchType::KalimbaSubArch_v5)
                .value("MipsSubArch_r6", llvm::Triple::SubArchType::MipsSubArch_r6)
                .value("PPCSubArch_spe", llvm::Triple::SubArchType::PPCSubArch_spe);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::Triple::VendorType> : pybinder_t {
        using binding_t = py::enum_<llvm::Triple::VendorType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Triple.VendorType"sv;
        static_assert(class_pybinder_t<llvm::Triple>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("Triple"), "VendorType" }
                .value("UnknownVendor", llvm::Triple::VendorType::UnknownVendor)
                .value("Apple", llvm::Triple::VendorType::Apple)
                .value("PC", llvm::Triple::VendorType::PC)
                .value("SCEI", llvm::Triple::VendorType::SCEI)
                .value("Freescale", llvm::Triple::VendorType::Freescale)
                .value("IBM", llvm::Triple::VendorType::IBM)
                .value("ImaginationTechnologies", llvm::Triple::VendorType::ImaginationTechnologies)
                .value("MipsTechnologies", llvm::Triple::VendorType::MipsTechnologies)
                .value("NVIDIA", llvm::Triple::VendorType::NVIDIA)
                .value("CSR", llvm::Triple::VendorType::CSR)
                .value("Myriad", llvm::Triple::VendorType::Myriad)
                .value("AMD", llvm::Triple::VendorType::AMD)
                .value("Mesa", llvm::Triple::VendorType::Mesa)
                .value("SUSE", llvm::Triple::VendorType::SUSE)
                .value("OpenEmbedded", llvm::Triple::VendorType::OpenEmbedded)
                .value("LastVendorType", llvm::Triple::VendorType::LastVendorType);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::Triple::OSType> : pybinder_t {
        using binding_t = py::enum_<llvm::Triple::OSType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Triple.OSType"sv;
        static_assert(class_pybinder_t<llvm::Triple>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("Triple"), "OSType" }
                .value("UnknownOS", llvm::Triple::OSType::UnknownOS)
                .value("Ananas", llvm::Triple::OSType::Ananas)
                .value("CloudABI", llvm::Triple::OSType::CloudABI)
                .value("Darwin", llvm::Triple::OSType::Darwin)
                .value("DragonFly", llvm::Triple::OSType::DragonFly)
                .value("FreeBSD", llvm::Triple::OSType::FreeBSD)
                .value("Fuchsia", llvm::Triple::OSType::Fuchsia)
                .value("IOS", llvm::Triple::OSType::IOS)
                .value("KFreeBSD", llvm::Triple::OSType::KFreeBSD)
                .value("Linux", llvm::Triple::OSType::Linux)
                .value("Lv2", llvm::Triple::OSType::Lv2)
                .value("MacOSX", llvm::Triple::OSType::MacOSX)
                .value("NetBSD", llvm::Triple::OSType::NetBSD)
                .value("OpenBSD", llvm::Triple::OSType::OpenBSD)
                .value("Solaris", llvm::Triple::OSType::Solaris)
                .value("Win32", llvm::Triple::OSType::Win32)
                .value("ZOS", llvm::Triple::OSType::ZOS)
                .value("Haiku", llvm::Triple::OSType::Haiku)
                .value("Minix", llvm::Triple::OSType::Minix)
                .value("RTEMS", llvm::Triple::OSType::RTEMS)
                .value("NaCl", llvm::Triple::OSType::NaCl)
                .value("AIX", llvm::Triple::OSType::AIX)
                .value("CUDA", llvm::Triple::OSType::CUDA)
                .value("NVCL", llvm::Triple::OSType::NVCL)
                .value("AMDHSA", llvm::Triple::OSType::AMDHSA)
                .value("PS4", llvm::Triple::OSType::PS4)
                .value("ELFIAMCU", llvm::Triple::OSType::ELFIAMCU)
                .value("TvOS", llvm::Triple::OSType::TvOS)
                .value("WatchOS", llvm::Triple::OSType::WatchOS)
                .value("Mesa3D", llvm::Triple::OSType::Mesa3D)
                .value("Contiki", llvm::Triple::OSType::Contiki)
                .value("AMDPAL", llvm::Triple::OSType::AMDPAL)
                .value("HermitCore", llvm::Triple::OSType::HermitCore)
                .value("Hurd", llvm::Triple::OSType::Hurd)
                .value("WASI", llvm::Triple::OSType::WASI)
                .value("Emscripten", llvm::Triple::OSType::Emscripten)
                .value("LastOSType", llvm::Triple::OSType::LastOSType);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::Triple::EnvironmentType> : pybinder_t {
        using binding_t = py::enum_<llvm::Triple::EnvironmentType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Triple.EnvironmentType"sv;
        static_assert(class_pybinder_t<llvm::Triple>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("Triple"), "EnvironmentType" }
                .value("UnknownEnvironment", llvm::Triple::EnvironmentType::UnknownEnvironment)
                .value("GNU", llvm::Triple::EnvironmentType::GNU)
                .value("GNUABIN32", llvm::Triple::EnvironmentType::GNUABIN32)
                .value("GNUABI64", llvm::Triple::EnvironmentType::GNUABI64)
                .value("GNUEABI", llvm::Triple::EnvironmentType::GNUEABI)
                .value("GNUEABIHF", llvm::Triple::EnvironmentType::GNUEABIHF)
                .value("GNUX32", llvm::Triple::EnvironmentType::GNUX32)
                .value("GNUILP32", llvm::Triple::EnvironmentType::GNUILP32)
                .value("CODE16", llvm::Triple::EnvironmentType::CODE16)
                .value("EABI", llvm::Triple::EnvironmentType::EABI)
                .value("EABIHF", llvm::Triple::EnvironmentType::EABIHF)
                .value("Android", llvm::Triple::EnvironmentType::Android)
                .value("Musl", llvm::Triple::EnvironmentType::Musl)
                .value("MuslEABI", llvm::Triple::EnvironmentType::MuslEABI)
                .value("MuslEABIHF", llvm::Triple::EnvironmentType::MuslEABIHF)
                .value("MuslX32", llvm::Triple::EnvironmentType::MuslX32)
                .value("MSVC", llvm::Triple::EnvironmentType::MSVC)
                .value("Itanium", llvm::Triple::EnvironmentType::Itanium)
                .value("Cygnus", llvm::Triple::EnvironmentType::Cygnus)
                .value("CoreCLR", llvm::Triple::EnvironmentType::CoreCLR)
                .value("Simulator", llvm::Triple::EnvironmentType::Simulator)
                .value("MacABI", llvm::Triple::EnvironmentType::MacABI)
                .value("LastEnvironmentType", llvm::Triple::EnvironmentType::LastEnvironmentType);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::Triple::ObjectFormatType> : pybinder_t {
        using binding_t = py::enum_<llvm::Triple::ObjectFormatType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Triple.ObjectFormatType"sv;
        static_assert(class_pybinder_t<llvm::Triple>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(std::make_pair(binder_identifier, this));
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("Triple"), "ObjectFormatType" }
                .value("UnknownObjectFormat", llvm::Triple::ObjectFormatType::UnknownObjectFormat)
                .value("COFF", llvm::Triple::ObjectFormatType::COFF)
                .value("ELF", llvm::Triple::ObjectFormatType::ELF)
                .value("GOFF", llvm::Triple::ObjectFormatType::GOFF)
                .value("MachO", llvm::Triple::ObjectFormatType::MachO)
                .value("Wasm", llvm::Triple::ObjectFormatType::Wasm)
                .value("XCOFF", llvm::Triple::ObjectFormatType::XCOFF);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    static class_pybinder_t<llvm::Triple> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::Triple::ArchType> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::Triple::SubArchType> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::Triple::VendorType> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::Triple::OSType> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::Triple::EnvironmentType> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::Triple::ObjectFormatType> PYLLVM_UNIQUE_NAME(_);
}
