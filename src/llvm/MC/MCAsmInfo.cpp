#include "MCAsmInfo.hpp"
#include "../../macro.hpp"

namespace pyllvm {
    static class_pybinder_t<llvm::MCAsmInfo> PYLLVM_UNIQUE_NAME(_);
    static enum_pybinder_t<llvm::MCAsmInfo::AsmCharLiteralSyntax> PYLLVM_UNIQUE_NAME(_);
}
