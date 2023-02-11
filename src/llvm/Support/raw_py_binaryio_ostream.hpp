#pragma once
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/FormattedStream.h>
#include "../../py.hpp"

namespace llvm {

    class raw_py_binaryio_ostream : public raw_ostream {
    private:
        py::BinaryIO& m_bio;
        py::object m_pytell;
        py::object m_pywrite;

        virtual uint64_t current_pos() const override {
            return m_pytell().cast<uint64_t>();
        }

        virtual void write_impl(const char *Ptr, size_t Size) override {
            auto data = py::memoryview::from_memory(std::string_view{ Ptr, Size });
            m_pywrite(data);
        }
    
    public:
        raw_py_binaryio_ostream(py::BinaryIO& bio) :
            m_bio{ bio }, m_pytell{ bio.attr("tell") }, m_pywrite{ bio.attr("write") } {}

        ~raw_py_binaryio_ostream() override { flush(); }
    };

}
