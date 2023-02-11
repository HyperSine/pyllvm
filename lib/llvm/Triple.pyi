from typing import Any, ClassVar, overload

class Triple:

    class ArchType:

        LastArchType: ClassVar[Triple.ArchType]
        UnknownArch: ClassVar[Triple.ArchType]
        aarch64: ClassVar[Triple.ArchType]
        aarch64_32: ClassVar[Triple.ArchType]
        aarch64_be: ClassVar[Triple.ArchType]
        amdgcn: ClassVar[Triple.ArchType]
        amdil: ClassVar[Triple.ArchType]
        amdil64: ClassVar[Triple.ArchType]
        arc: ClassVar[Triple.ArchType]
        arm: ClassVar[Triple.ArchType]
        armeb: ClassVar[Triple.ArchType]
        avr: ClassVar[Triple.ArchType]
        bpfeb: ClassVar[Triple.ArchType]
        bpfel: ClassVar[Triple.ArchType]
        csky: ClassVar[Triple.ArchType]
        hexagon: ClassVar[Triple.ArchType]
        hsail: ClassVar[Triple.ArchType]
        hsail64: ClassVar[Triple.ArchType]
        kalimba: ClassVar[Triple.ArchType]
        lanai: ClassVar[Triple.ArchType]
        le32: ClassVar[Triple.ArchType]
        le64: ClassVar[Triple.ArchType]
        m68k: ClassVar[Triple.ArchType]
        mips: ClassVar[Triple.ArchType]
        mips64: ClassVar[Triple.ArchType]
        mips64el: ClassVar[Triple.ArchType]
        mipsel: ClassVar[Triple.ArchType]
        msp430: ClassVar[Triple.ArchType]
        nvptx: ClassVar[Triple.ArchType]
        nvptx64: ClassVar[Triple.ArchType]
        ppc: ClassVar[Triple.ArchType]
        ppc64: ClassVar[Triple.ArchType]
        ppc64le: ClassVar[Triple.ArchType]
        ppcle: ClassVar[Triple.ArchType]
        r600: ClassVar[Triple.ArchType]
        renderscript32: ClassVar[Triple.ArchType]
        renderscript64: ClassVar[Triple.ArchType]
        riscv32: ClassVar[Triple.ArchType]
        riscv64: ClassVar[Triple.ArchType]
        shave: ClassVar[Triple.ArchType]
        sparc: ClassVar[Triple.ArchType]
        sparcel: ClassVar[Triple.ArchType]
        sparcv9: ClassVar[Triple.ArchType]
        spir: ClassVar[Triple.ArchType]
        spir64: ClassVar[Triple.ArchType]
        spirv32: ClassVar[Triple.ArchType]
        spirv64: ClassVar[Triple.ArchType]
        systemz: ClassVar[Triple.ArchType]
        tce: ClassVar[Triple.ArchType]
        tcele: ClassVar[Triple.ArchType]
        thumb: ClassVar[Triple.ArchType]
        thumbeb: ClassVar[Triple.ArchType]
        ve: ClassVar[Triple.ArchType]
        wasm32: ClassVar[Triple.ArchType]
        wasm64: ClassVar[Triple.ArchType]
        x86: ClassVar[Triple.ArchType]
        x86_64: ClassVar[Triple.ArchType]
        xcore: ClassVar[Triple.ArchType]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: Triple.ArchType) -> int:
            pass

        def __eq__(self, other: object) -> bool:
            pass

        def __getstate__(self) -> int:
            pass

        def __hash__(self) -> int:
            pass

        def __index__(self) -> int:
            pass

        def __init__(self, value: int) -> None:
            pass

        def __int__(self) -> int:
            pass

        def __ne__(self, other: object) -> bool:
            pass

        def __repr__(self) -> str:
            pass

        def __setstate__(self, state: int) -> None:
            pass

        def name(self) -> str:
            pass

    class EnvironmentType:

        Android: ClassVar[Triple.EnvironmentType]
        CODE16: ClassVar[Triple.EnvironmentType]
        CoreCLR: ClassVar[Triple.EnvironmentType]
        Cygnus: ClassVar[Triple.EnvironmentType]
        EABI: ClassVar[Triple.EnvironmentType]
        EABIHF: ClassVar[Triple.EnvironmentType]
        GNU: ClassVar[Triple.EnvironmentType]
        GNUABI64: ClassVar[Triple.EnvironmentType]
        GNUABIN32: ClassVar[Triple.EnvironmentType]
        GNUEABI: ClassVar[Triple.EnvironmentType]
        GNUEABIHF: ClassVar[Triple.EnvironmentType]
        GNUILP32: ClassVar[Triple.EnvironmentType]
        GNUX32: ClassVar[Triple.EnvironmentType]
        Itanium: ClassVar[Triple.EnvironmentType]
        LastEnvironmentType: ClassVar[Triple.EnvironmentType]
        MSVC: ClassVar[Triple.EnvironmentType]
        MacABI: ClassVar[Triple.EnvironmentType]
        Musl: ClassVar[Triple.EnvironmentType]
        MuslEABI: ClassVar[Triple.EnvironmentType]
        MuslEABIHF: ClassVar[Triple.EnvironmentType]
        MuslX32: ClassVar[Triple.EnvironmentType]
        Simulator: ClassVar[Triple.EnvironmentType]
        UnknownEnvironment: ClassVar[Triple.EnvironmentType]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: Triple.EnvironmentType) -> int:
            pass

        def __eq__(self, other: object) -> bool:
            pass

        def __getstate__(self) -> int:
            pass

        def __hash__(self) -> int:
            pass

        def __index__(self) -> int:
            pass

        def __init__(self, value: int) -> None:
            pass

        def __int__(self) -> int:
            pass

        def __ne__(self, other: object) -> bool:
            pass

        def __repr__(self) -> str:
            pass

        def __setstate__(self, state: int) -> None:
            pass

        def name(self) -> str:
            pass

    class OSType:

        AIX: ClassVar[Triple.OSType]
        AMDHSA: ClassVar[Triple.OSType]
        AMDPAL: ClassVar[Triple.OSType]
        Ananas: ClassVar[Triple.OSType]
        CUDA: ClassVar[Triple.OSType]
        CloudABI: ClassVar[Triple.OSType]
        Contiki: ClassVar[Triple.OSType]
        Darwin: ClassVar[Triple.OSType]
        DragonFly: ClassVar[Triple.OSType]
        ELFIAMCU: ClassVar[Triple.OSType]
        Emscripten: ClassVar[Triple.OSType]
        FreeBSD: ClassVar[Triple.OSType]
        Fuchsia: ClassVar[Triple.OSType]
        Haiku: ClassVar[Triple.OSType]
        HermitCore: ClassVar[Triple.OSType]
        Hurd: ClassVar[Triple.OSType]
        IOS: ClassVar[Triple.OSType]
        KFreeBSD: ClassVar[Triple.OSType]
        LastOSType: ClassVar[Triple.OSType]
        Linux: ClassVar[Triple.OSType]
        Lv2: ClassVar[Triple.OSType]
        MacOSX: ClassVar[Triple.OSType]
        Mesa3D: ClassVar[Triple.OSType]
        Minix: ClassVar[Triple.OSType]
        NVCL: ClassVar[Triple.OSType]
        NaCl: ClassVar[Triple.OSType]
        NetBSD: ClassVar[Triple.OSType]
        OpenBSD: ClassVar[Triple.OSType]
        PS4: ClassVar[Triple.OSType]
        RTEMS: ClassVar[Triple.OSType]
        Solaris: ClassVar[Triple.OSType]
        TvOS: ClassVar[Triple.OSType]
        UnknownOS: ClassVar[Triple.OSType]
        WASI: ClassVar[Triple.OSType]
        WatchOS: ClassVar[Triple.OSType]
        Win32: ClassVar[Triple.OSType]
        ZOS: ClassVar[Triple.OSType]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: Triple.OSType) -> int:
            pass

        def __eq__(self, other: object) -> bool:
            pass

        def __getstate__(self) -> int:
            pass

        def __hash__(self) -> int:
            pass

        def __index__(self) -> int:
            pass

        def __init__(self, value: int) -> None:
            pass

        def __int__(self) -> int:
            pass

        def __ne__(self, other: object) -> bool:
            pass

        def __repr__(self) -> str:
            pass

        def __setstate__(self, state: int) -> None:
            pass

        def name(self) -> str:
            pass

    class ObjectFormatType:

        COFF: ClassVar[Triple.ObjectFormatType]
        ELF: ClassVar[Triple.ObjectFormatType]
        GOFF: ClassVar[Triple.ObjectFormatType]
        MachO: ClassVar[Triple.ObjectFormatType]
        UnknownObjectFormat: ClassVar[Triple.ObjectFormatType]
        Wasm: ClassVar[Triple.ObjectFormatType]
        XCOFF: ClassVar[Triple.ObjectFormatType]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: Triple.ObjectFormatType) -> int:
            pass

        def __eq__(self, other: object) -> bool:
            pass

        def __getstate__(self) -> int:
            pass

        def __hash__(self) -> int:
            pass

        def __index__(self) -> int:
            pass

        def __init__(self, value: int) -> None:
            pass

        def __int__(self) -> int:
            pass

        def __ne__(self, other: object) -> bool:
            pass

        def __repr__(self) -> str:
            pass

        def __setstate__(self, state: int) -> None:
            pass

        def name(self) -> str:
            pass

    class SubArchType:

        AArch64SubArch_arm64e: ClassVar[Triple.SubArchType]
        ARMSubArch_v4t: ClassVar[Triple.SubArchType]
        ARMSubArch_v5: ClassVar[Triple.SubArchType]
        ARMSubArch_v5te: ClassVar[Triple.SubArchType]
        ARMSubArch_v6: ClassVar[Triple.SubArchType]
        ARMSubArch_v6k: ClassVar[Triple.SubArchType]
        ARMSubArch_v6m: ClassVar[Triple.SubArchType]
        ARMSubArch_v6t2: ClassVar[Triple.SubArchType]
        ARMSubArch_v7: ClassVar[Triple.SubArchType]
        ARMSubArch_v7em: ClassVar[Triple.SubArchType]
        ARMSubArch_v7k: ClassVar[Triple.SubArchType]
        ARMSubArch_v7m: ClassVar[Triple.SubArchType]
        ARMSubArch_v7s: ClassVar[Triple.SubArchType]
        ARMSubArch_v7ve: ClassVar[Triple.SubArchType]
        ARMSubArch_v8: ClassVar[Triple.SubArchType]
        ARMSubArch_v8_1a: ClassVar[Triple.SubArchType]
        ARMSubArch_v8_1m_mainline: ClassVar[Triple.SubArchType]
        ARMSubArch_v8_2a: ClassVar[Triple.SubArchType]
        ARMSubArch_v8_3a: ClassVar[Triple.SubArchType]
        ARMSubArch_v8_4a: ClassVar[Triple.SubArchType]
        ARMSubArch_v8_5a: ClassVar[Triple.SubArchType]
        ARMSubArch_v8_6a: ClassVar[Triple.SubArchType]
        ARMSubArch_v8_7a: ClassVar[Triple.SubArchType]
        ARMSubArch_v8_8a: ClassVar[Triple.SubArchType]
        ARMSubArch_v8m_baseline: ClassVar[Triple.SubArchType]
        ARMSubArch_v8m_mainline: ClassVar[Triple.SubArchType]
        ARMSubArch_v8r: ClassVar[Triple.SubArchType]
        ARMSubArch_v9: ClassVar[Triple.SubArchType]
        ARMSubArch_v9_1a: ClassVar[Triple.SubArchType]
        ARMSubArch_v9_2a: ClassVar[Triple.SubArchType]
        ARMSubArch_v9_3a: ClassVar[Triple.SubArchType]
        KalimbaSubArch_v3: ClassVar[Triple.SubArchType]
        KalimbaSubArch_v4: ClassVar[Triple.SubArchType]
        KalimbaSubArch_v5: ClassVar[Triple.SubArchType]
        MipsSubArch_r6: ClassVar[Triple.SubArchType]
        NoSubArch: ClassVar[Triple.SubArchType]
        PPCSubArch_spe: ClassVar[Triple.SubArchType]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: Triple.SubArchType) -> int:
            pass

        def __eq__(self, other: object) -> bool:
            pass

        def __getstate__(self) -> int:
            pass

        def __hash__(self) -> int:
            pass

        def __index__(self) -> int:
            pass

        def __init__(self, value: int) -> None:
            pass

        def __int__(self) -> int:
            pass

        def __ne__(self, other: object) -> bool:
            pass

        def __repr__(self) -> str:
            pass

        def __setstate__(self, state: int) -> None:
            pass

        def name(self) -> str:
            pass

    class VendorType:

        AMD: ClassVar[Triple.VendorType]
        Apple: ClassVar[Triple.VendorType]
        CSR: ClassVar[Triple.VendorType]
        Freescale: ClassVar[Triple.VendorType]
        IBM: ClassVar[Triple.VendorType]
        ImaginationTechnologies: ClassVar[Triple.VendorType]
        LastVendorType: ClassVar[Triple.VendorType]
        Mesa: ClassVar[Triple.VendorType]
        MipsTechnologies: ClassVar[Triple.VendorType]
        Myriad: ClassVar[Triple.VendorType]
        NVIDIA: ClassVar[Triple.VendorType]
        OpenEmbedded: ClassVar[Triple.VendorType]
        PC: ClassVar[Triple.VendorType]
        SCEI: ClassVar[Triple.VendorType]
        SUSE: ClassVar[Triple.VendorType]
        UnknownVendor: ClassVar[Triple.VendorType]

        @property
        def name(self) -> str:
            pass

        @property
        def value(arg0: Triple.VendorType) -> int:
            pass

        def __eq__(self, other: object) -> bool:
            pass

        def __getstate__(self) -> int:
            pass

        def __hash__(self) -> int:
            pass

        def __index__(self) -> int:
            pass

        def __init__(self, value: int) -> None:
            pass

        def __int__(self) -> int:
            pass

        def __ne__(self, other: object) -> bool:
            pass

        def __repr__(self) -> str:
            pass

        def __setstate__(self, state: int) -> None:
            pass

        def name(self) -> str:
            pass

    @staticmethod
    def normalize(arg0: str) -> str:
        pass

    def __eq__(self, arg0: Triple) -> bool:
        pass

    def __hash__(self) -> int:
        pass

    @overload
    def __init__(self) -> None:
        pass

    @overload
    def __init__(self, Str: str) -> None:
        pass

    @overload
    def __init__(self, ArchStr: str, VendorStr: str, OSStr: str) -> None:
        pass

    @overload
    def __init__(self, ArchStr: str, VendorStr: str, OSStr: str, EnvironmentStr: str) -> None:
        pass

    def __ne__(self, arg0: Triple) -> bool:
        pass

    def __str__(self) -> str:
        pass

    def get32BitArchVariant(self) -> Triple:
        pass

    def get64BitArchVariant(self) -> Triple:
        pass

    def getARMCPUForArch(self, arg0: str) -> str:
        pass

    def getArch(self) -> Triple.ArchType:
        pass

    def getBigEndianArchVariant(self) -> Triple:
        pass

    def getEnvironment(self) -> Triple.EnvironmentType:
        pass

    def getLittleEndianArchVariant(self) -> Triple:
        pass

    def getOS(self) -> Triple.OSType:
        pass

    def getOSMajorVersion(self) -> int:
        pass

    def getObjectFormat(self) -> Triple.ObjectFormatType:
        pass

    def getSubArch(self) -> Triple.SubArchType:
        pass

    def getTriple(self) -> str:
        pass

    def getVendor(self) -> Triple.VendorType:
        pass

    def hasDLLImportExport(self) -> bool:
        pass

    def hasDefaultDataSections(self) -> bool:
        pass

    def hasDefaultEmulatedTLS(self) -> bool:
        pass

    def hasEnvironment(self) -> bool:
        pass

    @overload
    def isAArch64(self) -> bool:
        pass

    @overload
    def isAArch64(self, PointerWidth: int) -> bool:
        pass

    def isAMDGCN(self) -> bool:
        pass

    def isAMDGPU(self) -> bool:
        pass

    def isARM(self) -> bool:
        pass

    def isAndroid(self) -> bool:
        pass

    def isAndroidVersionLT(self, arg0: int) -> bool:
        pass

    def isArch16Bit(self) -> bool:
        pass

    def isArch32Bit(self) -> bool:
        pass

    def isArch64Bit(self) -> bool:
        pass

    def isArm64e(self) -> bool:
        pass

    def isArmMClass(self) -> bool:
        pass

    def isArmT32(self) -> bool:
        pass

    def isCSKY(self) -> bool:
        pass

    def isCompatibleWith(self, arg0: Triple) -> bool:
        pass

    def isGNUEnvironment(self) -> bool:
        pass

    def isKnownWindowsMSVCEnvironment(self) -> bool:
        pass

    def isLittleEndian(self) -> bool:
        pass

    def isMIPS(self) -> bool:
        pass

    def isMIPS32(self) -> bool:
        pass

    def isMIPS64(self) -> bool:
        pass

    def isMacCatalystEnvironment(self) -> bool:
        pass

    def isMacOSX(self) -> bool:
        pass

    def isMacOSXVersionLT(self, arg0: int, arg1: int, arg2: int) -> bool:
        pass

    def isMusl(self) -> bool:
        pass

    def isNVPTX(self) -> bool:
        pass

    def isOSAIX(self) -> bool:
        pass

    def isOSBinFormatCOFF(self) -> bool:
        pass

    def isOSBinFormatELF(self) -> bool:
        pass

    def isOSBinFormatGOFF(self) -> bool:
        pass

    def isOSBinFormatMachO(self) -> bool:
        pass

    def isOSBinFormatWasm(self) -> bool:
        pass

    def isOSBinFormatXCOFF(self) -> bool:
        pass

    def isOSContiki(self) -> bool:
        pass

    def isOSCygMing(self) -> bool:
        pass

    def isOSDarwin(self) -> bool:
        pass

    def isOSDragonFly(self) -> bool:
        pass

    def isOSEmscripten(self) -> bool:
        pass

    def isOSFreeBSD(self) -> bool:
        pass

    def isOSFuchsia(self) -> bool:
        pass

    def isOSGlibc(self) -> bool:
        pass

    def isOSHaiku(self) -> bool:
        pass

    def isOSHurd(self) -> bool:
        pass

    def isOSIAMCU(self) -> bool:
        pass

    def isOSKFreeBSD(self) -> bool:
        pass

    def isOSLinux(self) -> bool:
        pass

    def isOSMSVCRT(self) -> bool:
        pass

    def isOSNaCl(self) -> bool:
        pass

    def isOSNetBSD(self) -> bool:
        pass

    def isOSOpenBSD(self) -> bool:
        pass

    def isOSSolaris(self) -> bool:
        pass

    def isOSUnknown(self) -> bool:
        pass

    @overload
    def isOSVersionLT(self, arg0: int, arg1: int, arg2: int) -> bool:
        pass

    @overload
    def isOSVersionLT(self, arg0: Triple) -> bool:
        pass

    def isOSWASI(self) -> bool:
        pass

    def isOSWindows(self) -> bool:
        pass

    def isOSzOS(self) -> bool:
        pass

    def isPPC(self) -> bool:
        pass

    def isPPC32(self) -> bool:
        pass

    def isPPC64(self) -> bool:
        pass

    def isPS(self) -> bool:
        pass

    def isPS4(self) -> bool:
        pass

    def isPS5(self) -> bool:
        pass

    def isRISCV(self) -> bool:
        pass

    def isSPIR(self) -> bool:
        pass

    def isSPIRV(self) -> bool:
        pass

    def isSimulatorEnvironment(self) -> bool:
        pass

    def isSystemZ(self) -> bool:
        pass

    def isTargetEHABICompatible(self) -> bool:
        pass

    def isTargetMachineMac(self) -> bool:
        pass

    def isThumb(self) -> bool:
        pass

    def isTvOS(self) -> bool:
        pass

    def isVE(self) -> bool:
        pass

    def isWasm(self) -> bool:
        pass

    def isWatchABI(self) -> bool:
        pass

    def isWatchOS(self) -> bool:
        pass

    def isWindowsCoreCLREnvironment(self) -> bool:
        pass

    def isWindowsCygwinEnvironment(self) -> bool:
        pass

    def isWindowsGNUEnvironment(self) -> bool:
        pass

    def isWindowsItaniumEnvironment(self) -> bool:
        pass

    def isWindowsMSVCEnvironment(self) -> bool:
        pass

    def isX32(self) -> bool:
        pass

    def isX86(self) -> bool:
        pass

    def isiOS(self) -> bool:
        pass

    def merge(self, arg0: Triple) -> str:
        pass

    @overload
    def setArch(self, Kind: Triple.ArchType) -> None:
        pass

    @overload
    def setArch(self, Kind: Triple.ArchType, SubArch: Triple.SubArchType) -> None:
        pass

    def setEnvironment(self, arg0: Triple.EnvironmentType) -> None:
        pass

    def setOS(self, arg0: Triple.OSType) -> None:
        pass

    def setObjectFormat(self, arg0: Triple.ObjectFormatType) -> None:
        pass

    def setVendor(self, arg0: Triple.VendorType) -> None:
        pass

    def supportsCOMDAT(self) -> bool:
        pass
