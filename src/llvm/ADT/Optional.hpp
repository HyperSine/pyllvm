#pragma once
#include <llvm/ADT/Optional.h>
#include "../../py.hpp"

namespace PYBIND11_NAMESPACE { namespace detail {
    template <typename T>
    struct type_caster<llvm::Optional<T>> : optional_caster<llvm::Optional<T>> {};
}}
