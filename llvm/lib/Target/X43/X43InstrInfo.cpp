#include "X43InstrInfo.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "X43GenInstrInfo.inc"

namespace llvm {
X43InstrInfo::X43InstrInfo() : X43GenInstrInfo() {}
} // namespace llvm
