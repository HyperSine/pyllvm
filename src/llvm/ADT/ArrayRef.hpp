#pragma once
#include <llvm/ADT/ArrayRef.h>
#include "../../py.hpp"

namespace PYBIND11_NAMESPACE { namespace detail {
    template<typename Type>
    struct type_caster<llvm::ArrayRef<Type>> {
        using value_conv = make_caster<Type>;
        PYBIND11_TYPE_CASTER(llvm::ArrayRef<Type>, const_name("List[") + value_conv::name + const_name("]"));

        std::vector<Type> storage;

        bool load(handle src, bool convert) {
            if (!isinstance<sequence>(src)) {
                return false;
            }

            auto seq = reinterpret_borrow<sequence>(src);
            storage.reserve(seq.size());

            for (auto entry : seq) {
                value_conv conv;
                if (conv.load(entry, convert)) {
                    storage.push_back(cast_op<Type&&>(std::move(conv)));
                } else {
                    return false;
                }
            }

            value = llvm::ArrayRef<Type>{ storage };
            return true;
        }

        template<typename T>
        static handle cast(T&& src, return_value_policy policy, handle parent) {
            if (!std::is_lvalue_reference<T>::value) {
                policy = return_value_policy_override<Type>::policy(policy);
            }

            list l{ src.size() };

            ssize_t index = 0;
            for (auto&& v : src) {
                auto v_ = reinterpret_steal<object>(value_conv::cast(detail::forward_like<T>(v), policy, parent));
                if (!v_) {
                    return handle{};
                }
                PyList_SET_ITEM(l.ptr(), index++, v_.release().ptr());
            }
            
            return l.release();
        }
    };
}}
