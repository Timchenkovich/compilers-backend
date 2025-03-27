#include "TargetInfo/X43TargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"

#define GET_REGINFO_ENUM
#define GET_REGINFO_MC_DESC
#include "X43GenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "X43GenInstrInfo.inc"

using namespace llvm;

namespace {
  MCInstrInfo* createInstructionInfo() {
    MCInstrInfo* instrInfo = new MCInstrInfo();
    InitX43MCInstrInfo(instrInfo);
    return instrInfo;
  }


  MCRegisterInfo* createRegisterInfo(const Triple& triple) {
    MCRegisterInfo* registerInfo = new MCRegisterInfo();
    InitX43MCRegisterInfo(registerInfo, X43::X0);
    return registerInfo;
  }
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeX43TargetMC() {
  Target& target = getTheX43Target();
  TargetRegistry::RegisterMCRegInfo(target, createRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(target, createInstructionInfo);
}