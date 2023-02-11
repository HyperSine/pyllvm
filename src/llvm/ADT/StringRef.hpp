#pragma once
#include <llvm/ADT/StringRef.h>
#include "../../py.hpp"

namespace PYBIND11_NAMESPACE { namespace detail {

    template<>
    struct type_caster<llvm::StringRef> {
        PYBIND11_TYPE_CASTER(llvm::StringRef, const_name("str"));

        bool load(handle src, bool convert) {
            if (!src) {
                return false;
            }

            if (PyUnicode_Check(src.ptr())) {
                Py_ssize_t size = -1;
                const char* buffer = PyUnicode_AsUTF8AndSize(src.ptr(), &size);
                if (buffer) {
                    value = llvm::StringRef{ buffer, static_cast<size_t>(size) };
                    return true;
                } else {
                    return false;
                }
            } else if (PyBytes_Check(src.ptr())) {
                const char* buffer = PyBytes_AsString(src.ptr());
                if (!buffer) {
                    pybind11_fail("Unexpected PyBytes_AsString() failure.");
                }
                value = llvm::StringRef{ buffer, static_cast<size_t>(PyBytes_Size(src.ptr())) };
                return true;
            } else if (PyByteArray_Check(src.ptr())) {
                const char* buffer = PyByteArray_AsString(src.ptr());
                if (!buffer) {
                    pybind11_fail("Unexpected PyByteArray_AsString() failure.");
                }
                value = llvm::StringRef{ buffer, static_cast<size_t>(PyByteArray_Size(src.ptr())) };
                return true;
            } else {
                return false;
            }
        }

        static handle cast(const llvm::StringRef& src, return_value_policy, handle) {
            handle string{ PyUnicode_DecodeUTF8(src.data(), static_cast<py::ssize_t>(src.size()), nullptr) };
            if (static_cast<bool>(string)) {
                return string;
            } else {
                throw error_already_set{};
            }
        }
    };
}}
