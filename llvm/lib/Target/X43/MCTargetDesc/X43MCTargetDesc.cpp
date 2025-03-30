#include "X43MCTargetDesc.h"
#include "TargetInfo/X43TargetInfo.h"
#include "X43Info.h"
#include "X43InstPrinter.h"
#include "X43MCAsmInfo.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"

#define GET_REGINFO_MC_DESC
#include "X43GenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "X43GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "X43GenSubtargetInfo.inc"

using namespace llvm;

namespace {
MCInstrInfo *createInstructionInfo() {
  MCInstrInfo *instrInfo = new MCInstrInfo();
  InitX43MCInstrInfo(instrInfo);
  return instrInfo;
}

MCRegisterInfo *createRegisterInfo(const Triple &triple) {
  MCRegisterInfo *registerInfo = new MCRegisterInfo();
  InitX43MCRegisterInfo(registerInfo, X43::X0);
  return registerInfo;
}

MCSubtargetInfo *createSubtargetInfo(const Triple &TT, StringRef CPU,
                                     StringRef Features) {
  return createX43MCSubtargetInfoImpl(TT, CPU, CPU, Features);
}

MCAsmInfo *createMCAsmInfo(const MCRegisterInfo &MRI, const Triple &TT,
                           const MCTargetOptions &Options) {
  MCAsmInfo *MAI = new X43ELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(X43::SP, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

MCInstPrinter *createInstPrinter(const Triple &T, unsigned SyntaxVariant,
                                 const MCAsmInfo &MAI, const MCInstrInfo &MII,
                                 const MCRegisterInfo &MRI) {
  return new X43InstPrinter(MAI, MII, MRI);
}
} // namespace

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeX43TargetMC() {
  Target &target = getTheX43Target();

  TargetRegistry::RegisterMCAsmInfo(target, createMCAsmInfo);
  TargetRegistry::RegisterMCRegInfo(target, createRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(target, createInstructionInfo);
  TargetRegistry::RegisterMCSubtargetInfo(target, createSubtargetInfo);
  TargetRegistry::RegisterMCInstPrinter(target, createInstPrinter);
}