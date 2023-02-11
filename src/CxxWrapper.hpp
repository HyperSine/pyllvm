#pragma once
#include <memory>
#include <string>
#include "py.hpp"

namespace pyllvm {
    struct CxxWrapper {
        virtual ~CxxWrapper() = default;

        [[nodiscard]]
        virtual bool isEmpty() const noexcept = 0;

        [[nodiscard]]
        virtual py::str repr() const = 0;

        [[nodiscard]]
        virtual py::Any unwrap() = 0;
    };

    template<typename T>
    struct CxxWrapperFor;

    template<typename T>
    struct CxxWrapperFor<std::unique_ptr<T>> : CxxWrapper {
        std::unique_ptr<T> ptr;

        CxxWrapperFor() noexcept = default;

        CxxWrapperFor(std::nullptr_t) noexcept : ptr{ nullptr } {}

        CxxWrapperFor(std::unique_ptr<T> p) noexcept : ptr{ std::move(p) } {}

        virtual ~CxxWrapperFor() override = default;

        [[nodiscard]]
        virtual bool isEmpty() const noexcept override {
            return !static_cast<bool>(ptr);
        }

        [[nodiscard]]
        virtual py::str repr() const override {
            return py::str("{}(ptr = 0x{:x})").format(py::type_id<decltype(*this)>(), reinterpret_cast<uintptr_t>(ptr.get()));
        }

        [[nodiscard]]
        virtual py::Any unwrap() override {
            if (ptr) {
                return py::cast(std::move(ptr));
            } else {
                py::pybind11_fail("Nothing to unwrap.");
            }
        }
    };
}
