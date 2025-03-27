#pragma once

#include <llvm/CodeGen/TargetInstrInfo.h>

#define GET_INSTRINFO_HEADER
#include "X43GenInstrInfo.inc"

struct X43InstrInfo : public llvm::X43GenInstrInfo {
    X43InstrInfo();
};