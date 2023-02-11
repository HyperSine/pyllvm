#include <llvm/Support/SourceMgr.h>
#include <llvm/TableGen/Record.h>
#include <llvm/TableGen/Parser.h>
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    struct TableGen_Parser_tag {};

    template<>
    struct function_pybinder_t<TableGen_Parser_tag> : pybinder_t {
        static constexpr std::string_view binder_identifier = "pyllvm.llvm.functions@TableGen/Parser"sv;

        function_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {}

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").cast<py::module_>()
                .def("TableGenParseFile", &llvm::TableGenParseFile, py::arg("InputSrcMgr"), py::arg("Records"));
        }
    };

    static function_pybinder_t<TableGen_Parser_tag> PYLLVM_UNIQUE_NAME(_);
}
