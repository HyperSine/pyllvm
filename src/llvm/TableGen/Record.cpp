#include <llvm/TableGen/Record.h>
#include "../ADT/ArrayRef.hpp"
#include "../ADT/Optional.hpp"
#include "../ADT/StringRef.hpp"
#include "../../init.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    using namespace std::string_view_literals;

    template<>
    struct class_pybinder_t<llvm::RecTy> : pybinder_t {
        using binding_t = py::class_<llvm::RecTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecTy"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "RecTy" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("RecTy").cast<binding_t>()
                .def("__str__", &llvm::RecTy::getAsString)
                .def("getRecTyKind", &llvm::RecTy::getRecTyKind)
                .def("getRecordKeeper", &llvm::RecTy::getRecordKeeper, py::return_value_policy::reference)
                .def("typeIsConvertibleTo", &llvm::RecTy::typeIsConvertibleTo, py::arg("RHS").none(false))
                .def("typeIsA", &llvm::RecTy::typeIsA, py::arg("RHS").none(false));

        }
    };

    template<>
    struct enum_pybinder_t<llvm::RecTy::RecTyKind> : pybinder_t {
        using binding_t = py::enum_<llvm::RecTy::RecTyKind>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecTy.RecTyKind"sv;
        static_assert(class_pybinder_t<llvm::RecTy>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("RecTy"), "RecTyKind" }
                .value("Bit", llvm::RecTy::RecTyKind::BitRecTyKind)
                .value("Bits", llvm::RecTy::RecTyKind::BitsRecTyKind)
                .value("Int", llvm::RecTy::RecTyKind::IntRecTyKind)
                .value("String", llvm::RecTy::RecTyKind::StringRecTyKind)
                .value("List", llvm::RecTy::RecTyKind::ListRecTyKind)
                .value("Dag", llvm::RecTy::RecTyKind::DagRecTyKind)
                .value("Record", llvm::RecTy::RecTyKind::RecordRecTyKind);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::BitRecTy> : pybinder_t {
        using binding_t = py::class_<llvm::BitRecTy, llvm::RecTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecTy@BitRecTy"sv;
        static_assert(class_pybinder_t<llvm::RecTy>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "BitRecTy" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("BitRecTy").cast<binding_t>()
                //.def("__str__", &llvm::BitRecTy::getAsString)
                //.def("typeIsConvertibleTo", &llvm::BitRecTy::typeIsConvertibleTo, py::arg("RHS").none(false))
                .def_static("classof", &llvm::BitRecTy::classof, py::arg("RT").none(false))
                .def_static("get", &llvm::BitRecTy::get, py::arg("RK").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::BitsRecTy> : pybinder_t {
        using binding_t = py::class_<llvm::BitsRecTy, llvm::RecTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecTy@BitsRecTy"sv;
        static_assert(class_pybinder_t<llvm::RecTy>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "BitsRecTy" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("BitsRecTy").cast<binding_t>()
                //.def("__str__", &llvm::BitsRecTy::getAsString)
                //.def("typeIsConvertibleTo", &llvm::BitsRecTy::typeIsConvertibleTo, py::arg("RHS").none(false))
                //.def("typeIsA", &llvm::BitsRecTy::typeIsA, py::arg("RHS").none(false))
                .def("getNumBits", &llvm::BitsRecTy::getNumBits)
                .def_static("classof", &llvm::BitsRecTy::classof, py::arg("RT").none(false))
                .def_static("get", &llvm::BitsRecTy::get, py::arg("RK").none(false), py::arg("Sz"), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::IntRecTy> : pybinder_t {
        using binding_t = py::class_<llvm::IntRecTy, llvm::RecTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecTy@IntRecTy"sv;
        static_assert(class_pybinder_t<llvm::RecTy>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "IntRecTy" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("IntRecTy").cast<binding_t>()
                //.def("__str__", &llvm::IntRecTy::getAsString)
                //.def("typeIsConvertibleTo", &llvm::IntRecTy::typeIsConvertibleTo, py::arg("RHS").none(false))
                .def_static("classof", &llvm::IntRecTy::classof, py::arg("RT").none(false))
                .def_static("get", &llvm::IntRecTy::get, py::arg("RK").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::StringRecTy> : pybinder_t {
        using binding_t = py::class_<llvm::StringRecTy, llvm::RecTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecTy@StringRecTy"sv;
        static_assert(class_pybinder_t<llvm::RecTy>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "StringRecTy" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("StringRecTy").cast<binding_t>()
                //.def("__str__", &llvm::StringRecTy::getAsString)
                //.def("typeIsConvertibleTo", &llvm::StringRecTy::typeIsConvertibleTo, py::arg("RHS").none(false))
                .def_static("classof", &llvm::StringRecTy::classof, py::arg("RT").none(false))
                .def_static("get", &llvm::StringRecTy::get, py::arg("RK").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::ListRecTy> : pybinder_t {
        using binding_t = py::class_<llvm::ListRecTy, llvm::RecTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecTy@ListRecTy"sv;
        static_assert(class_pybinder_t<llvm::RecTy>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "ListRecTy" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("ListRecTy").cast<binding_t>()
                //.def("__str__", &llvm::ListRecTy::getAsString)
                //.def("typeIsConvertibleTo", &llvm::ListRecTy::typeIsConvertibleTo, py::arg("RHS").none(false))
                //.def("typeIsA", &llvm::ListRecTy::typeIsA, py::arg("RHS").none(false))
                .def("getElementType", &llvm::ListRecTy::getElementType, py::return_value_policy::reference)
                .def_static("classof", &llvm::ListRecTy::classof, py::arg("RT").none(false))
                .def_static("get", &llvm::ListRecTy::get, py::arg("RK").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::DagRecTy> : pybinder_t {
        using binding_t = py::class_<llvm::DagRecTy, llvm::RecTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecTy@DagRecTy"sv;
        static_assert(class_pybinder_t<llvm::RecTy>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "DagRecTy" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("DagRecTy").cast<binding_t>()
                //.def("__str__", &llvm::DagRecTy::getAsString)
                .def_static("classof", &llvm::DagRecTy::classof, py::arg("RT").none(false))
                .def_static("get", &llvm::DagRecTy::get, py::arg("RK").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::RecordRecTy> : pybinder_t {
        using binding_t = py::class_<llvm::RecordRecTy, llvm::RecTy>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecTy@RecordRecTy";
        static_assert(class_pybinder_t<llvm::RecTy>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "RecordRecTy" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("RecordRecTy").cast<binding_t>()
                //.def("__str__", &llvm::RecordRecTy::getAsString)
                //.def("typeIsConvertibleTo", &llvm::RecordRecTy::typeIsConvertibleTo, py::arg("RHS").none(false))
                //.def("typeIsA", &llvm::RecordRecTy::typeIsA, py::arg("RHS").none(false))
                .def(
                    "getClasses",
                    [](llvm::RecordRecTy& self) -> std::vector<llvm::Record*> {
                        auto classes = self.getClasses();
                        return std::vector<llvm::Record*>{ classes.begin(), classes.end() };
                    },
                    py::return_value_policy::reference
                )
                .def("isSubClassOf", &llvm::RecordRecTy::isSubClassOf, py::arg("Class").none(false))
                .def_static("classof", &llvm::RecordRecTy::classof, py::arg("RT").none(false))
                //.def_static("get", &llvm::RecordRecTy::get, py::arg("RK").none(false), py::return_value_policy::reference)
                ;
        }
    };

    template<>
    struct class_pybinder_t<llvm::Init> : pybinder_t {
        using binding_t = py::class_<llvm::Init>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init";

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "Init" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("Init").cast<binding_t>()
                .def("__str__", &llvm::Init::getAsString)
                .def("getRecordKeeper", &llvm::Init::getRecordKeeper, py::return_value_policy::reference)
                .def("isComplete", &llvm::Init::isComplete)
                .def("isConcrete", &llvm::Init::isConcrete)
                .def("getAsString", &llvm::Init::getAsString)
                .def("getAsUnquotedString", &llvm::Init::getAsUnquotedString)
                .def("getCastTo", &llvm::Init::getCastTo, py::arg("Ty").none(false), py::return_value_policy::reference)
                .def("convertInitializerTo", &llvm::Init::convertInitializerTo, py::arg("Ty").none(false), py::return_value_policy::reference)
                .def(
                    "convertInitializerBitRange",
                    [](llvm::Init& self, std::vector<unsigned> Bits) {
                        return self.convertInitializerBitRange(llvm::ArrayRef<unsigned>{ Bits });
                    },
                    py::arg("Bits"),
                    py::return_value_policy::reference
                )
                .def(
                    "convertInitListSlice",
                    [](llvm::Init& self, std::vector<unsigned> Elements) {
                        return self.convertInitListSlice(llvm::ArrayRef<unsigned>{ Elements });
                    },
                    py::arg("Elements"),
                    py::return_value_policy::reference
                )
                // .def(
                //     "getFieldType",
                //     [](llvm::Init& self, /*todo*/) {

                //     },
                //     py::arg("FieldName"),
                //     py::return_value_policy::reference
                // )
                // .def(
                //     "resolveReferences",
                //     &llvm::Init::resolveReferences,
                //     py::arg("R"),
                //     py::return_value_policy::reference
                // )
                .def("getBit", &llvm::Init::getBit, py::arg("Bit"), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::TypedInit> : pybinder_t {
        using binding_t = py::class_<llvm::TypedInit, llvm::Init>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit";
        static_assert(class_pybinder_t<llvm::Init>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "TypedInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("TypedInit").cast<binding_t>()
                .def("getType", &llvm::TypedInit::getType, py::return_value_policy::reference)
                .def("getRecordKeeper", &llvm::TypedInit::getRecordKeeper, py::return_value_policy::reference)
                .def_static("classof", &llvm::TypedInit::classof, py::arg("I").none(false));
        }
    };

    template<>
    struct class_pybinder_t<llvm::UnsetInit> : pybinder_t {
        using binding_t = py::class_<llvm::UnsetInit, llvm::Init>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@UnsetInit";
        static_assert(class_pybinder_t<llvm::Init>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "UnsetInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("UnsetInit").cast<binding_t>()
                .def("getRecordKeeper", &llvm::UnsetInit::getRecordKeeper, py::return_value_policy::reference)
                .def_static("classof", &llvm::UnsetInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::UnsetInit::get, py::arg("RK").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::BitInit> : pybinder_t {
        using binding_t = py::class_<llvm::BitInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@BitInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "BitInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("BitInit").cast<binding_t>()
                .def("getValue", &llvm::BitInit::getValue)
                .def_static("classof", &llvm::BitInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::BitInit::get, py::arg("RK").none(false), py::arg("V"), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::BitsInit> : pybinder_t {
        using binding_t = py::class_<llvm::BitsInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@BitsInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "BitsInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("BitsInit").cast<binding_t>()
                //.def("Profile", &llvm::BitsInit::Profile)
                .def("getNumBits", &llvm::BitsInit::getNumBits)
                .def("allInComplete", &llvm::BitsInit::allInComplete)
                .def_static("classof", &llvm::BitsInit::classof, py::arg("I").none(false))
                // .def_static(
                //     "get",
                //     [](llvm::RecordKeeper& RK, /*ArrayRef<Init*> Range*/) {

                //     },
                //     py::arg("RK").none(false),
                //     py::arg("Range"),
                //     py::return_value_policy::reference
                // )
                ;
        }
    };

    template<>
    struct class_pybinder_t<llvm::IntInit> : pybinder_t {
        using binding_t = py::class_<llvm::IntInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@IntInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "IntInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("IntInit").cast<binding_t>()
                .def("getValue", &llvm::IntInit::getValue)
                .def_static("classof", &llvm::IntInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::IntInit::get, py::arg("RK"), py::arg("V"), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::AnonymousNameInit> : pybinder_t {
        using binding_t = py::class_<llvm::AnonymousNameInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@AnonymousNameInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "AnonymousNameInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("AnonymousNameInit").cast<binding_t>()
                .def("getValue", &llvm::AnonymousNameInit::getValue)
                .def("getNameInit", &llvm::AnonymousNameInit::getNameInit, py::return_value_policy::reference)
                .def("getAsString", &llvm::AnonymousNameInit::getAsString)
                .def_static("classof", &llvm::AnonymousNameInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::AnonymousNameInit::get, py::arg("RK"), py::arg("unused"), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::StringInit> : pybinder_t {
        using binding_t = py::class_<llvm::StringInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@StringInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "StringInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("StringInit").cast<binding_t>()
                .def("getValue", &llvm::StringInit::getValue)
                .def("getFormat", &llvm::StringInit::getFormat)
                .def("hasCodeFormat", &llvm::StringInit::hasCodeFormat)
                .def_static("classof", &llvm::StringInit::classof, py::arg("I").none(false))
                .def_static(
                    "get",
                    [](llvm::RecordKeeper& RK, llvm::StringRef V) {
                        llvm::StringInit::get(RK, V);
                    },
                    py::arg("RK"),
                    py::arg("V"),
                    py::return_value_policy::reference
                )
                .def_static(
                    "get",
                    [](llvm::RecordKeeper& RK, llvm::StringRef V, llvm::StringInit::StringFormat Fmt) {
                        llvm::StringInit::get(RK, V, Fmt);
                    },
                    py::arg("RK"),
                    py::arg("V"),
                    py::arg("Fmt"),
                    py::return_value_policy::reference
                )
                .def_static("determineFormat", &llvm::StringInit::determineFormat, py::arg("Fmt1"), py::arg("Fmt2"));
        }
    };

    template<>
    struct enum_pybinder_t<llvm::StringInit::StringFormat> : pybinder_t {
        using binding_t = py::enum_<llvm::StringInit::StringFormat>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@StringInit.StringFormat";
        static_assert(class_pybinder_t<llvm::StringInit>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("StringInit"), "StringFormat" }
                .value("String", llvm::StringInit::StringFormat::SF_String)
                .value("Code", llvm::StringInit::StringFormat::SF_Code);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::ListInit> : pybinder_t {
        using binding_t = py::class_<llvm::ListInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@ListInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "ListInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("ListInit").cast<binding_t>()
                .def(
                    "__iter__",
                    [](llvm::ListInit& self) {
                        return py::make_iterator(self.begin(), self.end());
                    },
                    py::return_value_policy::reference
                )
                .def("getElement", &llvm::ListInit::getElement, py::arg("i"), py::return_value_policy::reference)
                .def("getElementType", &llvm::ListInit::getElementType, py::return_value_policy::reference)
                .def("getElementAsRecord", &llvm::ListInit::getElementAsRecord, py::arg("i"), py::return_value_policy::reference)
                .def(
                    "getValues",
                    [](llvm::ListInit& self) -> std::vector<llvm::Init*> {
                        auto values = self.getValues();
                        return std::vector<llvm::Init*>{ values.begin(), values.end() };
                    },
                    py::return_value_policy::reference
                )
                .def("size", &llvm::ListInit::size)
                .def("empty", &llvm::ListInit::empty)
                .def_static("classof", &llvm::ListInit::classof, py::arg("I").none(false))
                //.def_static("get", []() { /*todo*/ })
                ;
        }
    };

    template<>
    struct class_pybinder_t<llvm::OpInit> : pybinder_t {
        using binding_t = py::class_<llvm::OpInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@OpInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "OpInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("OpInit").cast<binding_t>()
                .def(
                    "clone",
                    [](llvm::OpInit& self, std::vector<llvm::Init*> Operands) {
                        return self.clone(llvm::ArrayRef<llvm::Init*>{ Operands });
                    },
                    py::arg("Operands"),
                    py::return_value_policy::reference
                )
                .def("getNumOperands", &llvm::OpInit::getNumOperands)
                .def("getOperand", &llvm::OpInit::getOperand, py::arg("i"), py::return_value_policy::reference)
                .def_static("classof", &llvm::OpInit::classof, py::arg("I").none(false));
        }
    };

    template<>
    struct class_pybinder_t<llvm::UnOpInit> : pybinder_t {
        using binding_t = py::class_<llvm::UnOpInit, llvm::OpInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@OpInit@UnOpInit";
        static_assert(class_pybinder_t<llvm::OpInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "UnOpInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("UnOpInit").cast<binding_t>()
                .def("getOpcode", &llvm::UnOpInit::getOpcode)
                .def("getOperand", py::overload_cast<>(&llvm::UnOpInit::getOpcode, py::const_), py::return_value_policy::reference)
                .def("Fold", &llvm::UnOpInit::Fold, py::arg("CurRec"), py::arg("IsFinal") = false, py::return_value_policy::reference)
                .def_static("classof", &llvm::UnOpInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::UnOpInit::get, py::arg("opc"), py::arg("lhs").none(false), py::arg("Type").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct enum_pybinder_t<llvm::UnOpInit::UnaryOp> : pybinder_t {
        using binding_t = py::enum_<llvm::UnOpInit::UnaryOp>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@OpInit@UnOpInit.UnaryOp";
        static_assert(class_pybinder_t<llvm::UnOpInit>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("UnOpInit"), "UnaryOp" }
                .value("CAST", llvm::UnOpInit::UnaryOp::CAST)
                .value("NOT", llvm::UnOpInit::UnaryOp::NOT)
                .value("HEAD", llvm::UnOpInit::UnaryOp::HEAD)
                .value("TAIL", llvm::UnOpInit::UnaryOp::TAIL)
                .value("SIZE", llvm::UnOpInit::UnaryOp::SIZE)
                .value("EMPTY", llvm::UnOpInit::UnaryOp::EMPTY)
                .value("GETDAGOP", llvm::UnOpInit::UnaryOp::GETDAGOP);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::BinOpInit> : pybinder_t {
        using binding_t = py::class_<llvm::BinOpInit, llvm::OpInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@OpInit@BinOpInit";
        static_assert(class_pybinder_t<llvm::OpInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "BinOpInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("BinOpInit").cast<binding_t>()
                .def("getOpcode", &llvm::BinOpInit::getOpcode)
                .def("getLHS", &llvm::BinOpInit::getLHS, py::return_value_policy::reference)
                .def("getRHS", &llvm::BinOpInit::getRHS, py::return_value_policy::reference)
                .def("Fold", &llvm::BinOpInit::Fold, py::arg("CurRec"), py::return_value_policy::reference)
                .def_static("classof", &llvm::BinOpInit::classof, py::arg("I").none(false))
                .def_static(
                    "get",
                    &llvm::BinOpInit::get,
                    py::arg("opc"),
                    py::arg("lhs").none(false),
                    py::arg("rhs").none(false),
                    py::arg("Type").none(false),
                    py::return_value_policy::reference
                )
                .def_static(
                    "getStrConcat",
                    &llvm::BinOpInit::getStrConcat,
                    py::arg("lhs").none(false),
                    py::arg("rhs").none(false),
                    py::return_value_policy::reference
                )
                .def_static(
                    "getListConcat",
                    &llvm::BinOpInit::getListConcat,
                    py::arg("lhs").none(false),
                    py::arg("rhs").none(false),
                    py::return_value_policy::reference
                );
        }
    };

    template<>
    struct enum_pybinder_t<llvm::BinOpInit::BinaryOp> : pybinder_t {
        using binding_t = py::enum_<llvm::BinOpInit::BinaryOp>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@OpInit@BinOpInit.BinaryOp";
        static_assert(class_pybinder_t<llvm::BinOpInit>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("BinOpInit"), "BinaryOp" }
                .value("ADD", llvm::BinOpInit::BinaryOp::ADD)
                .value("SUB", llvm::BinOpInit::BinaryOp::SUB)
                .value("MUL", llvm::BinOpInit::BinaryOp::MUL)
                .value("AND", llvm::BinOpInit::BinaryOp::AND)
                .value("OR", llvm::BinOpInit::BinaryOp::OR)
                .value("XOR", llvm::BinOpInit::BinaryOp::XOR)
                .value("SHL", llvm::BinOpInit::BinaryOp::SHL)
                .value("SRA", llvm::BinOpInit::BinaryOp::SRA)
                .value("SRL", llvm::BinOpInit::BinaryOp::SRL)
                .value("LISTCONCAT", llvm::BinOpInit::BinaryOp::LISTCONCAT)
                .value("LISTSPLAT", llvm::BinOpInit::BinaryOp::LISTSPLAT)
                .value("STRCONCAT", llvm::BinOpInit::BinaryOp::STRCONCAT)
                .value("INTERLEAVE", llvm::BinOpInit::BinaryOp::INTERLEAVE)
                .value("CONCAT", llvm::BinOpInit::BinaryOp::CONCAT)
                .value("EQ", llvm::BinOpInit::BinaryOp::EQ)
                .value("NE", llvm::BinOpInit::BinaryOp::NE)
                .value("LE", llvm::BinOpInit::BinaryOp::LE)
                .value("LT", llvm::BinOpInit::BinaryOp::LT)
                .value("GE", llvm::BinOpInit::BinaryOp::GE)
                .value("GT", llvm::BinOpInit::BinaryOp::GT)
                .value("SETDAGOP", llvm::BinOpInit::BinaryOp::SETDAGOP);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::TernOpInit> : pybinder_t {
        using binding_t = py::class_<llvm::TernOpInit, llvm::OpInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@OpInit@TernOpInit";
        static_assert(class_pybinder_t<llvm::OpInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "TernOpInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("TernOpInit").cast<binding_t>()
                .def("getOpcode", &llvm::TernOpInit::getOpcode)
                .def("getLHS", &llvm::TernOpInit::getLHS, py::return_value_policy::reference)
                .def("getMHS", &llvm::TernOpInit::getMHS, py::return_value_policy::reference)
                .def("getRHS", &llvm::TernOpInit::getRHS, py::return_value_policy::reference)
                .def("Fold", &llvm::TernOpInit::Fold, py::arg("CurRec"), py::return_value_policy::reference)
                .def_static("classof", &llvm::TernOpInit::classof, py::arg("I").none(false))
                .def_static(
                    "get",
                    &llvm::TernOpInit::get,
                    py::arg("opc"),
                    py::arg("lhs").none(false),
                    py::arg("mhs").none(false),
                    py::arg("rhs").none(false),
                    py::arg("Type").none(false),
                    py::return_value_policy::reference
                );
        }
    };

    template<>
    struct enum_pybinder_t<llvm::TernOpInit::TernaryOp> : pybinder_t {
        using binding_t = py::enum_<llvm::TernOpInit::TernaryOp>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@OpInit@TernOpInit.TernaryOp";
        static_assert(class_pybinder_t<llvm::TernOpInit>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("TernOpInit"), "TernaryOp" }
                .value("SUBST", llvm::TernOpInit::TernaryOp::SUBST)
                .value("FOREACH", llvm::TernOpInit::TernaryOp::FOREACH)
                .value("FILTER", llvm::TernOpInit::TernaryOp::FILTER)
                .value("IF", llvm::TernOpInit::TernaryOp::IF)
                .value("DAG", llvm::TernOpInit::TernaryOp::DAG)
                .value("SUBSTR", llvm::TernOpInit::TernaryOp::SUBSTR)
                .value("FIND", llvm::TernOpInit::TernaryOp::FIND);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::CondOpInit> : pybinder_t {
        using binding_t = py::class_<llvm::CondOpInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@CondOpInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "CondOpInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("CondOpInit").cast<binding_t>()
                .def("getValType", &llvm::CondOpInit::getValType, py::return_value_policy::reference)
                .def("getNumConds", &llvm::CondOpInit::getNumConds)
                .def("getCond", &llvm::CondOpInit::getCond, py::arg("Num"), py::return_value_policy::reference)
                .def("getVal", &llvm::CondOpInit::getVal, py::arg("Num"), py::return_value_policy::reference)
                .def("getConds", &llvm::CondOpInit::getConds, py::return_value_policy::reference)
                .def("getVals", &llvm::CondOpInit::getVals, py::return_value_policy::reference)
                .def("Fold", &llvm::CondOpInit::Fold, py::arg("CurRec"), py::return_value_policy::reference)
                .def_static("classof", &llvm::CondOpInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::CondOpInit::get, py::arg("C").none(false), py::arg("V").none(false), py::arg("Type").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::FoldOpInit> : pybinder_t {
        using binding_t = py::class_<llvm::FoldOpInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@FoldOpInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "FoldOpInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("FoldOpInit").cast<binding_t>()
                .def("Fold", &llvm::FoldOpInit::Fold, py::arg("CurRec"), py::return_value_policy::reference)
                .def_static("classof", &llvm::FoldOpInit::classof, py::arg("I").none(false))
                .def_static(
                    "get",
                    &llvm::FoldOpInit::get,
                    py::arg("Start").none(false),
                    py::arg("List").none(false),
                    py::arg("A").none(false),
                    py::arg("B").none(false),
                    py::arg("Expr").none(false),
                    py::arg("Type").none(false),
                    py::return_value_policy::reference
                );
        }
    };

    template<>
    struct class_pybinder_t<llvm::IsAOpInit> : pybinder_t {
        using binding_t = py::class_<llvm::IsAOpInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@IsAOpInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "IsAOpInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("IsAOpInit").cast<binding_t>()
                .def("Fold", &llvm::IsAOpInit::Fold, py::return_value_policy::reference)
                .def_static("classof", &llvm::IsAOpInit::classof, py::arg("I").none(false))
                .def_static(
                    "get",
                    &llvm::IsAOpInit::get,
                    py::arg("CheckType").none(false),
                    py::arg("Expr").none(false),
                    py::return_value_policy::reference
                );
        }
    };

    template<>
    struct class_pybinder_t<llvm::ExistsOpInit> : pybinder_t {
        using binding_t = py::class_<llvm::ExistsOpInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@ExistsOpInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "ExistsOpInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("ExistsOpInit").cast<binding_t>()
                .def("Fold", &llvm::ExistsOpInit::Fold, py::arg("CurRec").none(false), py::arg("IsFinal") = false, py::return_value_policy::reference)
                .def_static("classof", &llvm::ExistsOpInit::classof, py::arg("I").none(false))
                .def_static(
                    "get",
                    &llvm::ExistsOpInit::get,
                    py::arg("CheckType").none(false),
                    py::arg("Expr").none(false),
                    py::return_value_policy::reference
                );
        }
    };

    template<>
    struct class_pybinder_t<llvm::VarInit> : pybinder_t {
        using binding_t = py::class_<llvm::VarInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@VarInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "VarInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("VarInit").cast<binding_t>()
                .def("getName", &llvm::VarInit::getName)
                .def("getNameInit", &llvm::VarInit::getNameInit, py::return_value_policy::reference)
                .def("getNameInitAsString", &llvm::VarInit::getNameInitAsString)
                .def_static("classof", &llvm::VarInit::classof, py::arg("I").none(false))
                .def_static(
                    "get",
                    py::overload_cast<llvm::StringRef, llvm::RecTy*>(&llvm::VarInit::get),
                    py::arg("VN").none(false),
                    py::arg("T").none(false),
                    py::return_value_policy::reference
                )
                .def_static(
                    "get",
                    py::overload_cast<llvm::Init*, llvm::RecTy*>(&llvm::VarInit::get),
                    py::arg("VN").none(false),
                    py::arg("T").none(false),
                    py::return_value_policy::reference
                );
        }
    };

    template<>
    struct class_pybinder_t<llvm::VarBitInit> : pybinder_t {
        using binding_t = py::class_<llvm::VarBitInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@VarBitInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "VarBitInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("VarBitInit").cast<binding_t>()
                .def("getBitVar", &llvm::VarBitInit::getBitVar, py::return_value_policy::reference)
                .def("getBitNum", &llvm::VarBitInit::getBitNum)
                .def_static("classof", &llvm::VarBitInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::VarBitInit::get, py::arg("T").none(false), py::arg("B").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::VarListElementInit> : pybinder_t {
        using binding_t = py::class_<llvm::VarListElementInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@VarListElementInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "VarListElementInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("VarListElementInit").cast<binding_t>()
                .def("getVariable", &llvm::VarListElementInit::getVariable, py::return_value_policy::reference)
                .def("getElementNum", &llvm::VarListElementInit::getElementNum)
                .def_static("classof", &llvm::VarListElementInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::VarListElementInit::get, py::arg("T").none(false), py::arg("E").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::DefInit> : pybinder_t {
        using binding_t = py::class_<llvm::DefInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@DefInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "DefInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("DefInit").cast<binding_t>()
                .def("getDef", &llvm::DefInit::getDef, py::return_value_policy::reference)
                .def_static("classof", &llvm::DefInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::DefInit::get, py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::VarDefInit> : pybinder_t {
        using binding_t = py::class_<llvm::VarDefInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@VarDefInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "VarDefInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("VarDefInit").cast<binding_t>()
                .def("Fold", &llvm::VarDefInit::Fold, py::return_value_policy::reference)
                .def("getArg", &llvm::VarDefInit::getArg, py::arg("i"), py::return_value_policy::reference)
                .def("args", &llvm::VarDefInit::args, py::return_value_policy::reference)
                .def("args_size", &llvm::VarDefInit::args_size, py::return_value_policy::reference)
                .def("args_empty", &llvm::VarDefInit::args_empty)
                .def_static("classof", &llvm::VarDefInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::VarDefInit::get, py::arg("Class").none(false), py::arg("Args"), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::FieldInit> : pybinder_t {
        using binding_t = py::class_<llvm::FieldInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@FieldInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "FieldInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("FieldInit").cast<binding_t>()
                .def("getRecord", &llvm::FieldInit::getRecord, py::return_value_policy::reference)
                .def("getFieldName", &llvm::FieldInit::getFieldName, py::return_value_policy::reference)
                .def("Fold", &llvm::FieldInit::Fold, py::arg("CurRec").none(false), py::return_value_policy::reference)
                .def_static("classof", &llvm::FieldInit::classof, py::arg("I").none(false))
                .def_static("get", &llvm::FieldInit::get, py::arg("R").none(false), py::arg("FN").none(false), py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::DagInit> : pybinder_t {
        using binding_t = py::class_<llvm::DagInit, llvm::TypedInit>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Init@TypedInit@DagInit";
        static_assert(class_pybinder_t<llvm::TypedInit>::binder_identifier < binder_identifier);

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "DagInit" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("DagInit").cast<binding_t>()
                .def("getOperator", &llvm::DagInit::getOperator, py::return_value_policy::reference)
                //.def("getOperatorAsDef", &llvm::DagInit::getOperatorAsDef, py::return_value_policy::reference)
                .def("getName", &llvm::DagInit::getName, py::return_value_policy::reference)
                .def("getNameStr", &llvm::DagInit::getNameStr)
                .def("getNumArgs", &llvm::DagInit::getNumArgs)
                .def("getArg", &llvm::DagInit::getArg, py::arg("Num"), py::return_value_policy::reference)
                .def("getArgName", &llvm::DagInit::getArgName, py::arg("Num"), py::return_value_policy::reference)
                .def("getArgNameStr", &llvm::DagInit::getArgNameStr, py::arg("Num"))
                .def("getArgs", &llvm::DagInit::getArgs, py::return_value_policy::reference)
                .def("getArgNames", &llvm::DagInit::getArgNames, py::return_value_policy::reference)
                .def("arg_size", &llvm::DagInit::arg_size)
                .def("arg_empty", &llvm::DagInit::arg_empty)
                .def("name_size", &llvm::DagInit::name_size)
                .def("name_empty", &llvm::DagInit::name_empty)
                .def_static("classof", &llvm::DagInit::classof, py::arg("I").none(false))
                .def_static(
                    "get",
                    py::overload_cast<llvm::Init*, llvm::StringInit*, llvm::ArrayRef<llvm::Init*>, llvm::ArrayRef<llvm::StringInit*>>(&llvm::DagInit::get),
                    py::arg("V").none(false),
                    py::arg("VN").none(false),
                    py::arg("ArgRange").none(false),
                    py::arg("NameRange").none(false),
                    py::return_value_policy::reference
                )
                .def_static(
                    "get",
                    py::overload_cast<llvm::Init*, llvm::StringInit*, llvm::ArrayRef<std::pair<llvm::Init*, llvm::StringInit*>>>(&llvm::DagInit::get),
                    py::arg("V").none(false),
                    py::arg("VN").none(false),
                    py::arg("Args").none(false),
                    py::return_value_policy::reference
                );
        }
    };

    template<>
    struct class_pybinder_t<llvm::RecordVal> : pybinder_t {
        using binding_t = py::class_<llvm::RecordVal>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecordVal";

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "RecordVal" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("RecordVal").cast<binding_t>()
                .def("getRecordKeeper", &llvm::RecordVal::getRecordKeeper, py::return_value_policy::reference)
                .def("getName", &llvm::RecordVal::getName)
                .def("getNameInit", &llvm::RecordVal::getNameInit, py::return_value_policy::reference)
                .def("getNameInitAsString", &llvm::RecordVal::getNameInitAsString)
                //.def("getLoc", &llvm::RecordVal::getLoc, py::return_value_policy::reference_internal)
                .def("isNonconcreteOK", &llvm::RecordVal::isNonconcreteOK)
                .def("isTemplateArg", &llvm::RecordVal::isTemplateArg)
                .def("getType", &llvm::RecordVal::getType, py::return_value_policy::reference)
                .def("getValue", &llvm::RecordVal::getValue, py::return_value_policy::reference)
                // .def("setValue", &llvm::RecordVal::setValue)
                // .def("setValue", &llvm::RecordVal::setValue)
                .def("setUsed", &llvm::RecordVal::setUsed)
                .def("isUsed", &llvm::RecordVal::isUsed);
        }
    };

    template<>
    struct enum_pybinder_t<llvm::RecordVal::FieldKind> : pybinder_t {
        using binding_t = py::enum_<llvm::RecordVal::FieldKind>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecordVal.FieldKind";
        static_assert(class_pybinder_t<llvm::RecordVal>::binder_identifier < binder_identifier);

        enum_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm").attr("RecordVal"), "FieldKind" }
                .value("Normal", llvm::RecordVal::FieldKind::FK_Normal)
                .value("NonconcreteOK", llvm::RecordVal::FieldKind::FK_NonconcreteOK)
                .value("TemplateArg", llvm::RecordVal::FieldKind::FK_TemplateArg);
        }

        virtual void make_binding(py::module_& m) override {}
    };

    template<>
    struct class_pybinder_t<llvm::Record> : pybinder_t {
        using binding_t = py::class_<llvm::Record>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.Record"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "Record" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("Record").cast<binding_t>()
                .def("getID", &llvm::Record::getID)
                .def("getName", &llvm::Record::getName)
                .def("getNameInit", &llvm::Record::getNameInit, py::return_value_policy::reference)
                .def("getNameInitAsString", &llvm::Record::getNameInitAsString)
                //.def("setName", &llvm::Record::setName)
                //.def("getLoc", &llvm::Record::getLoc)
                //.def("getForwardDeclarationLocs", &llvm::Record::getForwardDeclarationLocs)
                //.def("updateClassLoc", &llvm::Record::updateClassLoc)
                .def("getType", &llvm::Record::getType, py::return_value_policy::reference)
                .def("getDefInit", &llvm::Record::getDefInit)
                .def("isClass", &llvm::Record::isClass)
                .def(
                    "getTemplateArgs",
                    [](llvm::Record& self) -> std::vector<llvm::Init*> {
                        auto args = self.getTemplateArgs();
                        return std::vector<llvm::Init*>{ args.begin(), args.end() };
                    },
                    py::return_value_policy::reference
                )
                //.def("getValues", &llvm::Record::getValues)
                //.def("getAssertions", &llvm::Record::getAssertions)
                //.def("getSuperClasses", &llvm::Record::getSuperClasses)
                .def("hasDirectSuperClass", &llvm::Record::hasDirectSuperClass)
                //.def("getDirectSuperClasses", &llvm::Record::getDirectSuperClasses)
                .def("isTemplateArg", &llvm::Record::isTemplateArg)
                .def(
                    "getValue",
                    py::overload_cast<const llvm::Init*>(&llvm::Record::getValue),
                    py::arg("Name").none(false),
                    py::return_value_policy::reference
                )
                .def(
                    "getValue",
                    py::overload_cast<const llvm::StringRef>(&llvm::Record::getValue),
                    py::arg("Name"),
                    py::return_value_policy::reference
                )
                //.def("addTemplateArg", &llvm::Record::addTemplateArg)
                //.def("addValue", &llvm::Record::addValue);
                .def(
                    "removeValue",
                    py::overload_cast<llvm::Init*>(&llvm::Record::removeValue),
                    py::arg("Name").none(false)
                )
                .def(
                    "removeValue",
                    py::overload_cast<llvm::StringRef>(&llvm::Record::removeValue),
                    py::arg("Name")
                )
                // .def("addAssertion", &llvm::Record::addAssertion)
                // .def("appendAssertions", &llvm::Record::appendAssertions)
                .def("checkRecordAssertions", &llvm::Record::checkRecordAssertions)
                .def("checkUnusedTemplateArgs", &llvm::Record::checkUnusedTemplateArgs)
                .def(
                    "isSubClassOf",
                    py::overload_cast<const llvm::Record*>(&llvm::Record::isSubClassOf, py::const_),
                    py::arg("R").none(false))
                .def(
                    "isSubClassOf",
                    py::overload_cast<const llvm::StringRef>(&llvm::Record::isSubClassOf, py::const_),
                    py::arg("Name")
                )
                //.def("addSuperClass", &llvm::Record::addSuperClass)
                //.def("resolveReferences", )
                //.def("resolveReferences", )
                .def("getRecords", &llvm::Record::getRecords, py::return_value_policy::reference)
                .def("isAnonymous", &llvm::Record::isAnonymous)
                //.def("getFieldLoc", &llvm::Record::getFieldLoc)
                .def("getValueInit", &llvm::Record::getValueInit, py::return_value_policy::reference)
                .def("isValueUnset", &llvm::Record::isValueUnset)
                .def("getValueAsString", &llvm::Record::getValueAsString)
                .def("getValueAsOptionalString", &llvm::Record::getValueAsOptionalString)
                .def("getValueAsBitsInit", &llvm::Record::getValueAsBitsInit, py::return_value_policy::reference)
                .def("getValueAsListInit", &llvm::Record::getValueAsListInit, py::return_value_policy::reference)
                .def("getValueAsListOfDefs", &llvm::Record::getValueAsListOfDefs, py::return_value_policy::reference)
                .def("getValueAsListOfInts", &llvm::Record::getValueAsListOfInts)
                .def("getValueAsListOfStrings", &llvm::Record::getValueAsListOfStrings)
                .def("getValueAsDef", &llvm::Record::getValueAsDef, py::return_value_policy::reference)
                //.def("getValueAsOptionalDef", &llvm::Record::getValueAsOptionalDef)
                //.def("getValueAsBitOrUnset", &llvm::Record::getValueAsBitOrUnset)
                .def("getValueAsInt", &llvm::Record::getValueAsInt)
                .def("getValueAsDag", &llvm::Record::getValueAsDag, py::return_value_policy::reference);
        }
    };

    template<>
    struct class_pybinder_t<llvm::RecordKeeper> : pybinder_t {
        using binding_t = py::class_<llvm::RecordKeeper>;

        static constexpr std::string_view binder_identifier = "pyllvm.llvm.RecordKeeper"sv;

        class_pybinder_t() {
            auto [_, inserted] = pybinder_t::registered_binders().emplace(binder_identifier, this);
            assert(inserted);
        }

        virtual void declare(py::module_& m) override {
            binding_t{ m.attr("llvm"), "RecordKeeper" };
        }

        virtual void make_binding(py::module_& m) override {
            m.attr("llvm").attr("RecordKeeper").cast<binding_t>()
                .def(py::init<>())
                .def("getInputFilename", &llvm::RecordKeeper::getInputFilename)
                //.def("getClasses", &llvm::RecordKeeper::getClasses)
                //.def("getDefs", &llvm::RecordKeeper::getDefs)
                //.def("getGlobals", &llvm::RecordKeeper::getGlobals)
                .def(
                    "getClass",
                    &llvm::RecordKeeper::getClass,
                    py::arg("Name"),
                    py::return_value_policy::reference_internal
                )
                .def(
                    "getDef",
                    &llvm::RecordKeeper::getDef,
                    py::arg("Name"),
                    py::return_value_policy::reference_internal
                )
                .def(
                    "getGlobal",
                    &llvm::RecordKeeper::getGlobal,
                    py::arg("Name"),
                    py::return_value_policy::reference_internal
                )
                .def("saveInputFilename", &llvm::RecordKeeper::saveInputFilename, py::arg("Filename"))
                //.def("addClass", &llvm::RecordKeeper::addClass, py::arg("R"))
                //.def("addDef", &llvm::RecordKeeper::addDef, py::arg("R"))
                //.def("addExtraGlobal", &llvm::RecordKeeper::addExtraGlobal, py::arg("Name"), py::arg("I"))
                .def(
                    "getNewAnonymousName",
                    &llvm::RecordKeeper::getNewAnonymousName,
                    py::return_value_policy::reference_internal
                )
                .def("startPhaseTiming", &llvm::RecordKeeper::startPhaseTiming)
                .def("stopPhaseTiming", &llvm::RecordKeeper::stopPhaseTiming)
                .def("startTimer", &llvm::RecordKeeper::startTimer, py::arg("Name"))
                .def("stopTimer", &llvm::RecordKeeper::stopTimer)
                .def("startBackendTimer", &llvm::RecordKeeper::startBackendTimer, py::arg("Name"))
                .def("stopBackendTimer", &llvm::RecordKeeper::stopBackendTimer)
                .def(
                    "getAllDerivedDefinitions",
                    py::overload_cast<llvm::StringRef>(&llvm::RecordKeeper::getAllDerivedDefinitions, py::const_),
                    py::arg("ClassName"),
                    py::return_value_policy::reference_internal
                )
                .def(
                    "getAllDerivedDefinitions",
                    py::overload_cast<llvm::ArrayRef<llvm::StringRef>>(&llvm::RecordKeeper::getAllDerivedDefinitions, py::const_),
                    py::arg("ClassNames"),
                    py::return_value_policy::reference_internal
                )
                //.def("dump", &llvm::RecordKeeper::dump)
                ;
        }
    };

    static class_pybinder_t<llvm::RecTy> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::RecTy::RecTyKind> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::BitRecTy> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::BitsRecTy> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::IntRecTy> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::StringRecTy> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::ListRecTy> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::DagRecTy> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::RecordRecTy> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::Init> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::TypedInit> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::UnsetInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::BitInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::BitsInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::IntInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::AnonymousNameInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::StringInit> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::StringInit::StringFormat> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::ListInit> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::OpInit> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::UnOpInit> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::UnOpInit::UnaryOp> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::BinOpInit> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::BinOpInit::BinaryOp> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::TernOpInit> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::TernOpInit::TernaryOp> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::CondOpInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::FoldOpInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::IsAOpInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::ExistsOpInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::VarInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::VarBitInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::VarListElementInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::DefInit> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::VarDefInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::FieldInit> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::DagInit> PYLLVM_UNIQUE_NAME(_);

    static class_pybinder_t<llvm::RecordVal> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::Record> PYLLVM_UNIQUE_NAME(_);
    static class_pybinder_t<llvm::RecordKeeper> PYLLVM_UNIQUE_NAME(_);

    // static class_pybinder_t<llvm::LessRecord> PYLLVM_UNIQUE_NAME(_);
    // static class_pybinder_t<llvm::LessRecordByID> PYLLVM_UNIQUE_NAME(_);
    // static class_pybinder_t<llvm::LessRecordFieldName> PYLLVM_UNIQUE_NAME(_);
    // static class_pybinder_t<llvm::LessRecordRegister> PYLLVM_UNIQUE_NAME(_);

    // static class_pybinder_t<llvm::Resolver> PYLLVM_UNIQUE_NAME(_);
    // static class_pybinder_t<llvm::RecordResolver> PYLLVM_UNIQUE_NAME(_);
    // static class_pybinder_t<llvm::ShadowResolver> PYLLVM_UNIQUE_NAME(_);
    // static class_pybinder_t<llvm::TrackUnresolvedResolver> PYLLVM_UNIQUE_NAME(_);
    // static class_pybinder_t<llvm::HasReferenceResolver> PYLLVM_UNIQUE_NAME(_);
}
