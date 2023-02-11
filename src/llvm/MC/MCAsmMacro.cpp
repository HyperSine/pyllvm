#include <llvm/MC/MCAsmMacro.h>
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::AsmToken> : pybinder_t {
        using binding_t = py::class_<llvm::AsmToken>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.AsmToken"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "AsmToken" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("AsmToken").cast<binding_t>()
                .def(py::init<>())
                //.def(py::init<llvm::AsmToken::TokenKind, llvm::StringRef, llvm::APInt>())
                .def(
                    py::init<llvm::AsmToken::TokenKind, llvm::StringRef, int64_t>(),
                    py::arg("Kind"),
                    py::arg("Str"),
                    py::arg("IntVal")
                )
                .def("getKind", &llvm::AsmToken::getKind)
                //.def("is", &llvm::AsmToken::is)       // `is` is a keyword reserved by Python, other name needed?
                .def("isNot", &llvm::AsmToken::isNot, py::arg("K"))
                .def("getLoc", &llvm::AsmToken::getLoc)
                .def("getEndLoc", &llvm::AsmToken::getEndLoc)
                //.def("getLocRange", &llvm::AsmToken::getLocRange)
                .def("getStringContents", &llvm::AsmToken::getStringContents)
                .def("getIdentifier", &llvm::AsmToken::getIdentifier)
                .def("getString", &llvm::AsmToken::getString)
                .def("getIntVal", &llvm::AsmToken::getIntVal)
                //.def("getAPIntVal", &llvm::AsmToken::getAPIntVal)
                ;
        }
    };

    template<>
    struct enum_pybinder_t<llvm::AsmToken::TokenKind> : pybinder_t {
        using binding_t = py::enum_<llvm::AsmToken::TokenKind>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.AsmToken.TokenKind"sv;
        static_assert(class_pybinder_t<llvm::AsmToken>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("AsmToken"), "TokenKind" }
                .value("Eof", llvm::AsmToken::TokenKind::Eof)
                .value("Error", llvm::AsmToken::TokenKind::Error)
                .value("Identifier", llvm::AsmToken::TokenKind::Identifier)
                .value("String", llvm::AsmToken::TokenKind::String)
                .value("Integer", llvm::AsmToken::TokenKind::Integer)
                .value("BigNum", llvm::AsmToken::TokenKind::BigNum)
                .value("Real", llvm::AsmToken::TokenKind::Real)
                .value("Comment", llvm::AsmToken::TokenKind::Comment)
                .value("HashDirective", llvm::AsmToken::TokenKind::HashDirective)
                .value("EndOfStatement", llvm::AsmToken::TokenKind::EndOfStatement)
                .value("Colon", llvm::AsmToken::TokenKind::Colon)
                .value("Space", llvm::AsmToken::TokenKind::Space)
                .value("Plus", llvm::AsmToken::TokenKind::Plus)
                .value("Minus", llvm::AsmToken::TokenKind::Minus)
                .value("Tilde", llvm::AsmToken::TokenKind::Tilde)
                .value("Slash", llvm::AsmToken::TokenKind::Slash)
                .value("BackSlash", llvm::AsmToken::TokenKind::BackSlash)
                .value("LParen", llvm::AsmToken::TokenKind::LParen)
                .value("RParen", llvm::AsmToken::TokenKind::RParen)
                .value("LBrac", llvm::AsmToken::TokenKind::LBrac)
                .value("RBrac", llvm::AsmToken::TokenKind::RBrac)
                .value("LCurly", llvm::AsmToken::TokenKind::LCurly)
                .value("RCurly", llvm::AsmToken::TokenKind::RCurly)
                .value("Star", llvm::AsmToken::TokenKind::Star)
                .value("Dot", llvm::AsmToken::TokenKind::Dot)
                .value("Comma", llvm::AsmToken::TokenKind::Comma)
                .value("Dollar", llvm::AsmToken::TokenKind::Dollar)
                .value("Equal", llvm::AsmToken::TokenKind::Equal)
                .value("EqualEqual", llvm::AsmToken::TokenKind::EqualEqual)
                .value("Pipe", llvm::AsmToken::TokenKind::Pipe)
                .value("PipePipe", llvm::AsmToken::TokenKind::PipePipe)
                .value("Caret", llvm::AsmToken::TokenKind::Caret)
                .value("Amp", llvm::AsmToken::TokenKind::Amp)
                .value("AmpAmp", llvm::AsmToken::TokenKind::AmpAmp)
                .value("Exclaim", llvm::AsmToken::TokenKind::Exclaim)
                .value("ExclaimEqual", llvm::AsmToken::TokenKind::ExclaimEqual)
                .value("Percent", llvm::AsmToken::TokenKind::Percent)
                .value("Hash", llvm::AsmToken::TokenKind::Hash)
                .value("Less", llvm::AsmToken::TokenKind::Less)
                .value("LessEqual", llvm::AsmToken::TokenKind::LessEqual)
                .value("LessLess", llvm::AsmToken::TokenKind::LessLess)
                .value("LessGreater", llvm::AsmToken::TokenKind::LessGreater)
                .value("Greater", llvm::AsmToken::TokenKind::Greater)
                .value("GreaterEqual", llvm::AsmToken::TokenKind::GreaterEqual)
                .value("GreaterGreater", llvm::AsmToken::TokenKind::GreaterGreater)
                .value("At", llvm::AsmToken::TokenKind::At)
                .value("MinusGreater", llvm::AsmToken::TokenKind::MinusGreater)
                .value("PercentCall16", llvm::AsmToken::TokenKind::PercentCall16)
                .value("PercentCall_Hi", llvm::AsmToken::TokenKind::PercentCall_Hi)
                .value("PercentCall_Lo", llvm::AsmToken::TokenKind::PercentCall_Lo)
                .value("PercentDtprel_Hi", llvm::AsmToken::TokenKind::PercentDtprel_Hi)
                .value("PercentDtprel_Lo", llvm::AsmToken::TokenKind::PercentDtprel_Lo)
                .value("PercentGot", llvm::AsmToken::TokenKind::PercentGot)
                .value("PercentGot_Disp", llvm::AsmToken::TokenKind::PercentGot_Disp)
                .value("PercentGot_Hi", llvm::AsmToken::TokenKind::PercentGot_Hi)
                .value("PercentGot_Lo", llvm::AsmToken::TokenKind::PercentGot_Lo)
                .value("PercentGot_Ofst", llvm::AsmToken::TokenKind::PercentGot_Ofst)
                .value("PercentGot_Page", llvm::AsmToken::TokenKind::PercentGot_Page)
                .value("PercentGottprel", llvm::AsmToken::TokenKind::PercentGottprel)
                .value("PercentGp_Rel", llvm::AsmToken::TokenKind::PercentGp_Rel)
                .value("PercentHi", llvm::AsmToken::TokenKind::PercentHi)
                .value("PercentHigher", llvm::AsmToken::TokenKind::PercentHigher)
                .value("PercentHighest", llvm::AsmToken::TokenKind::PercentHighest)
                .value("PercentLo", llvm::AsmToken::TokenKind::PercentLo)
                .value("PercentNeg", llvm::AsmToken::TokenKind::PercentNeg)
                .value("PercentPcrel_Hi", llvm::AsmToken::TokenKind::PercentPcrel_Hi)
                .value("PercentPcrel_Lo", llvm::AsmToken::TokenKind::PercentPcrel_Lo)
                .value("PercentTlsgd", llvm::AsmToken::TokenKind::PercentTlsgd)
                .value("PercentTlsldm", llvm::AsmToken::TokenKind::PercentTlsldm)
                .value("PercentTprel_Hi", llvm::AsmToken::TokenKind::PercentTprel_Hi)
                .value("PercentTprel_Lo", llvm::AsmToken::TokenKind::PercentTprel_Lo);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::MCAsmMacroParameter> : pybinder_t {
        using binding_t = py::class_<llvm::MCAsmMacroParameter>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmMacroParameter"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCAsmMacroParameter" };
        }

        virtual void make_binding(py::module_& m) override {
            // todo
        }
    };

    template<>
    struct class_pybinder_t<llvm::MCAsmMacro> : pybinder_t {
        using binding_t = py::class_<llvm::MCAsmMacro>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmMacro"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCAsmMacro" };
        }

        virtual void make_binding(py::module_& m) override {
            // todo
        }
    };

    static class_pybinder_t<llvm::AsmToken> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::AsmToken::TokenKind> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::MCAsmMacroParameter> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::MCAsmMacro> PYLLVM_UNIQUE_NAME(_);
}
