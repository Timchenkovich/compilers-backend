#pragma once

#define GET_REGINFO_HEADER
#include "X43GenRegisterInfo.inc"

namespace llvm {
struct X43RegisterInfo : public llvm::X43GenRegisterInfo {
  X43RegisterInfo();
};
} // namespace llvm
