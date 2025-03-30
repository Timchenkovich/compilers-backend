#pragma once

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace X43Op {
enum OperandType : unsigned {
  OPERAND_SIMM64 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace X43Op

} // end namespace llvm
