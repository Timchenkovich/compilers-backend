#pragma once

namespace llvm {}

#define GET_REGINFO_ENUM
#include "X43GenRegisterInfo.inc"

// Defines symbolic names for the Sim instructions.
#define GET_INSTRINFO_ENUM
#include "X43GenInstrInfo.inc"