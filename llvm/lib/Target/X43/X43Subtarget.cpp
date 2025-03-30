#include "X43Subtarget.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"
#include "llvm/Target/TargetMachine.h"

#define GET_SUBTARGETINFO_CTOR
#include "X43GenSubtargetInfo.inc"

namespace llvm {
X43Subtarget::X43Subtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : X43GenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS),
      TL(TM, *this), FL(TargetFrameLowering::StackGrowsDown, Align(4), 0) {}

const TargetLowering *X43Subtarget::getTargetLowering() const { return &TL; }
const TargetFrameLowering *X43Subtarget::getFrameLowering() const {
  return &FL;
}

const TargetInstrInfo *X43Subtarget::getInstrInfo() const { return &II; }

const TargetRegisterInfo *X43Subtarget::getRegisterInfo() const { return &RI; }
const SelectionDAGTargetInfo *X43Subtarget::getSelectionDAGInfo() const {
  return &TSInfo;
}
} // namespace llvm
