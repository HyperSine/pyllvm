#include <llvm/MC/MCDirectives.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct enum_pybinder_t<llvm::MCSymbolAttr> : pybinder_t {
        using binding_t = py::enum_<llvm::MCSymbolAttr>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCSymbolAttr"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCSymbolAttr" }
                .value("Invalid", llvm::MCSymbolAttr::MCSA_Invalid)
                .value("Cold", llvm::MCSymbolAttr::MCSA_Cold)
                .value("ELF_TypeFunction", llvm::MCSymbolAttr::MCSA_ELF_TypeFunction)
                .value("ELF_TypeIndFunction", llvm::MCSymbolAttr::MCSA_ELF_TypeIndFunction)
                .value("ELF_TypeObject", llvm::MCSymbolAttr::MCSA_ELF_TypeObject)
                .value("ELF_TypeTLS", llvm::MCSymbolAttr::MCSA_ELF_TypeTLS)
                .value("ELF_TypeCommon", llvm::MCSymbolAttr::MCSA_ELF_TypeCommon)
                .value("ELF_TypeNoType", llvm::MCSymbolAttr::MCSA_ELF_TypeNoType)
                .value("ELF_TypeGnuUniqueObject", llvm::MCSymbolAttr::MCSA_ELF_TypeGnuUniqueObject)
                .value("Global", llvm::MCSymbolAttr::MCSA_Global)
                .value("LGlobal", llvm::MCSymbolAttr::MCSA_LGlobal)
                .value("Extern", llvm::MCSymbolAttr::MCSA_Extern)
                .value("Hidden", llvm::MCSymbolAttr::MCSA_Hidden)
                .value("IndirectSymbol", llvm::MCSymbolAttr::MCSA_IndirectSymbol)
                .value("Internal", llvm::MCSymbolAttr::MCSA_Internal)
                .value("LazyReference", llvm::MCSymbolAttr::MCSA_LazyReference)
                .value("Local", llvm::MCSymbolAttr::MCSA_Local)
                .value("NoDeadStrip", llvm::MCSymbolAttr::MCSA_NoDeadStrip)
                .value("SymbolResolver", llvm::MCSymbolAttr::MCSA_SymbolResolver)
                .value("AltEntry", llvm::MCSymbolAttr::MCSA_AltEntry)
                .value("PrivateExtern", llvm::MCSymbolAttr::MCSA_PrivateExtern)
                .value("Protected", llvm::MCSymbolAttr::MCSA_Protected)
                .value("Reference", llvm::MCSymbolAttr::MCSA_Reference)
                .value("Weak", llvm::MCSymbolAttr::MCSA_Weak)
                .value("WeakDefinition", llvm::MCSymbolAttr::MCSA_WeakDefinition)
                .value("WeakReference", llvm::MCSymbolAttr::MCSA_WeakReference)
                .value("WeakDefAutoPrivate", llvm::MCSymbolAttr::MCSA_WeakDefAutoPrivate);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::MCAssemblerFlag> : pybinder_t {
        using binding_t = py::enum_<llvm::MCAssemblerFlag>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAssemblerFlag"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCAssemblerFlag" }
                .value("SyntaxUnified", llvm::MCAssemblerFlag::MCAF_SyntaxUnified)
                .value("SubsectionsViaSymbols", llvm::MCAssemblerFlag::MCAF_SubsectionsViaSymbols)
                .value("Code16", llvm::MCAssemblerFlag::MCAF_Code16)
                .value("Code32", llvm::MCAssemblerFlag::MCAF_Code32)
                .value("Code64", llvm::MCAssemblerFlag::MCAF_Code64);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::MCDataRegionType> : pybinder_t {
        using binding_t = py::enum_<llvm::MCDataRegionType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCDataRegionType"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCDataRegionType" }
                .value("DataRegion", llvm::MCDataRegionType::MCDR_DataRegion)
                .value("DataRegionJT8", llvm::MCDataRegionType::MCDR_DataRegionJT8)
                .value("DataRegionJT16", llvm::MCDataRegionType::MCDR_DataRegionJT16)
                .value("DataRegionJT32", llvm::MCDataRegionType::MCDR_DataRegionJT32)
                .value("DataRegionEnd", llvm::MCDataRegionType::MCDR_DataRegionEnd);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct enum_pybinder_t<llvm::MCVersionMinType> : pybinder_t {
        using binding_t = py::enum_<llvm::MCVersionMinType>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCVersionMinType"sv;

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCVersionMinType" }
                .value("IOSVersionMin", llvm::MCVersionMinType::MCVM_IOSVersionMin)
                .value("OSXVersionMin", llvm::MCVersionMinType::MCVM_OSXVersionMin)
                .value("TvOSVersionMin", llvm::MCVersionMinType::MCVM_TvOSVersionMin)
                .value("WatchOSVersionMin", llvm::MCVersionMinType::MCVM_WatchOSVersionMin);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    static enum_pybinder_t<llvm::MCSymbolAttr> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCAssemblerFlag> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCDataRegionType> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCVersionMinType> PYLLVM_UNIQUE_NAME(_);
}
