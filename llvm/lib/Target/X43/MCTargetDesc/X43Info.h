#pragma once

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace X43Op {
enum OperandType : unsigned {
  OPERAND_SIMM64 = MCOI::OPERAND_FIRST_TARGET,
};

} // namespace X43Op

namespace X43Form {
// Format
enum : unsigned { NoOp, RI64 };

inline constexpr unsigned FormatMask = (1 << 5) - 1;
} // namespace X43Form

} // end namespace llvm
