#pragma once

#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/TargetRegistry.h"

namespace llvm {
MCCodeEmitter *createX43MCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createX43AsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createX43ELFObjectWriter(bool Is64Bit,
                                                               uint8_t OSABI);
} // namespace llvm

#define GET_REGINFO_ENUM
#include "X43GenRegisterInfo.inc"

// Defines symbolic names for the Sim instructions.
#define GET_INSTRINFO_ENUM
#include "X43GenInstrInfo.inc"