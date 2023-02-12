#include <llvm/MC/MCAsmInfo.h>
#include <llvm/MC/MCContext.h>
#include <llvm/MC/MCParser/MCAsmLexer.h>
#include <llvm/MC/MCParser/MCAsmParser.h>
#include <llvm/MC/MCStreamer.h>
#include <llvm/Support/SourceMgr.h>
#include "../../ADT/StringRef.hpp"
#include "../../../init.hpp"
#include "../../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::MCAsmParser> : pybinder_t {
        using binding_t = py::class_<llvm::MCAsmParser>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.MCAsmParser"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "MCAsmParser" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("MCAsmParser").cast<binding_t>()
                .def(
                    "addAliasForDirective",
                    &llvm::MCAsmParser::addAliasForDirective,
                    py::arg("Directive"),
                    py::arg("Alias")
                )
                .def(
                    "getSourceManager",
                    &llvm::MCAsmParser::getSourceManager,
                    py::return_value_policy::reference
                )
                .def(
                    "getLexer",
                    py::overload_cast<>(&llvm::MCAsmParser::getLexer),
                    py::return_value_policy::reference_internal
                )
                .def(
                    "getContext",
                    &llvm::MCAsmParser::getContext,
                    py::return_value_policy::reference
                )
                .def(
                    "getStreamer",
                    &llvm::MCAsmParser::getStreamer,
                    py::return_value_policy::reference
                )
                //.def("getTargetParser")
                //.def("setTargetParser")
                .def("getAssemblerDialect", &llvm::MCAsmParser::getAssemblerDialect)
                .def("setAssemblerDialect", &llvm::MCAsmParser::setAssemblerDialect, py::arg("i"))
                .def("getShowParsedOperands", &llvm::MCAsmParser::getShowParsedOperands)
                .def("setShowParsedOperands", &llvm::MCAsmParser::setShowParsedOperands, py::arg("Value"))
                .def(
                    "Run",
                    &llvm::MCAsmParser::Run,
                    py::arg("NoInitialTextSection"),
                    py::arg("NoFinalize") = false
                )
                .def("isParsingMSInlineAsm", &llvm::MCAsmParser::isParsingMSInlineAsm)
                .def("setParsingMSInlineAsm", &llvm::MCAsmParser::setParsingMSInlineAsm, py::arg("V"))
                //.def("discardLTOSymbol", &llvm::MCAsmParser::discardLTOSymbol)
                .def("isParsingMasm", &llvm::MCAsmParser::isParsingMasm)
                //.def("defineMacro", &llvm::MCAsmParser::defineMacro)
                //.def("lookUpField", &llvm::MCAsmParser::lookUpField)
                //.def("lookUpField", &llvm::MCAsmParser::lookUpField)
                //.def("lookUpType", &llvm::MCAsmParser::lookUpType)
                //.def("parseMSInlineAsm", &llvm::MCAsmParser::parseMSInlineAsm)
                //.def("Note", &llvm::MCAsmParser::Note)
                //.def("Warning", &llvm::MCAsmParser::Warning)
                //.def("Error", &llvm::MCAsmParser::Error)
                //.def("printError", &llvm::MCAsmParser::printError)
                .def("hasPendingError", &llvm::MCAsmParser::hasPendingError)
                .def("printPendingErrors", &llvm::MCAsmParser::printPendingErrors)
                .def("clearPendingErrors", &llvm::MCAsmParser::clearPendingErrors)
                //.def("addErrorSuffix", &llvm::MCAsmParser::addErrorSuffix)
                //.def("Lex", &llvm::MCAsmParser::Lex)
                //.def("TokError", &llvm::MCAsmParser::TokError)
                .def("parseTokenLoc", &llvm::MCAsmParser::parseTokenLoc)
                //.def("parseToken", &llvm::MCAsmParser::parseToken)
                .def("parseOptionalToken", &llvm::MCAsmParser::parseOptionalToken, py::arg("T"))
                .def("parseComma", &llvm::MCAsmParser::parseComma)
                .def("parseRParen", &llvm::MCAsmParser::parseRParen)
                //.def("parseEOL", &llvm::MCAsmParser::parseEOL)
                //.def("parseEOL", &llvm::MCAsmParser::parseEOL)
                //.def("parseMany", &llvm::MCAsmParser::parseMany)
                //.def("parseIntToken", &llvm::MCAsmParser::parseIntToken)
                //.def("check", &llvm::MCAsmParser::check)
                //.def("check", &llvm::MCAsmParser::check)
                //.def("parseIdentifier", &llvm::MCAsmParser::parseIdentifier)
                .def("parseStringToEndOfStatement", &llvm::MCAsmParser::parseStringToEndOfStatement)
                //.def("parseEscapedString", &llvm::MCAsmParser::parseEscapedString)
                //.def("parseAngleBracketString", &llvm::MCAsmParser::parseAngleBracketString)
                .def("eatToEndOfStatement", &llvm::MCAsmParser::eatToEndOfStatement)
                //.def("parseExpression", &llvm::MCAsmParser::parseExpression)
                //.def("parseExpression", &llvm::MCAsmParser::parseExpression)
                //.def("parsePrimaryExpr", &llvm::MCAsmParser::parsePrimaryExpr)
                //.def("parseParenExpression", &llvm::MCAsmParser::parseParenExpression)
                //.def("parseAbsoluteExpression", &llvm::MCAsmParser::parseAbsoluteExpression)
                .def("checkForValidSection", &llvm::MCAsmParser::checkForValidSection)
                //.def("parseParenExprOfDepth", &llvm::MCAsmParser::parseParenExprOfDepth)
                //.def("parseGNUAttribute", &llvm::MCAsmParser::parseGNUAttribute)
                ;
        }
    };

    struct MC_MCParser_MCAsmParser_tag {};

    template<>
    struct function_pybinder_t<MC_MCParser_MCAsmParser_tag> : pybinder_t {
        static constexpr std::string_view binder_identifier = "pyllvm.llvm.funtions@MC/MCParser/MCAsmParser"sv;

        function_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {}

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").cast<py::module_>()
                .def(
                    "createMCAsmParser",
                    &llvm::createMCAsmParser,
                    py::arg("SM"),
                    py::arg("C"),
                    py::arg("Out"),
                    py::arg("MAI"),
                    py::arg("CB") = 0,
                    py::keep_alive<0, 1>(),
                    py::keep_alive<0, 2>(),
                    py::keep_alive<0, 3>(),
                    py::keep_alive<0, 4>()
                )
                // .def(
                //     "createMCMasmParser",
                //     &llvm::createMCMasmParser,
                //     py::arg("SM"),
                //     py::arg("C"),
                //     py::arg("Out"),
                //     py::arg("MAI"),
                //     py::arg("TM"),
                //     py::arg("CB"),
                // )
                ;
        }
    };

    static class_pybinder_t<llvm::MCAsmParser> PYLLVM_UNIQUE_NAME(_);
    static function_pybinder_t<MC_MCParser_MCAsmParser_tag> PYLLVM_UNIQUE_NAME(_);
}
