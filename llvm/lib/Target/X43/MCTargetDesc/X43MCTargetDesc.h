#pragma once

#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInstrInfo.h"
namespace llvm {
MCCodeEmitter *createX43MCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
}

#define GET_REGINFO_ENUM
#include "X43GenRegisterInfo.inc"

// Defines symbolic names for the Sim instructions.
#define GET_INSTRINFO_ENUM
#include "X43GenInstrInfo.inc"