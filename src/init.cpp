#include "init.hpp"

namespace pyllvm {
    pybinder_t::binder_map_t& pybinder_t::registered_binders() {
        static binder_map_t binders;
        return binders;
    }
}

PYBIND11_MODULE(pyllvm, m) {
    m.def_submodule("llvm");

    for (auto& [_, binder] : pyllvm::pybinder_t::registered_binders()) {
        binder->declare(m);
    }

    for (auto& [_, binder] : pyllvm::pybinder_t::registered_binders()) {
        binder->make_binding(m);
    }
}
