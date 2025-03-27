#include "X43RegisterInfo.h"

#define GET_REGINFO_ENUM
#include "X43GenRegisterInfo.inc"

namespace llvm {
X43RegisterInfo::X43RegisterInfo() : llvm::X43GenRegisterInfo(llvm::X43::X0) {}
} // namespace llvm
