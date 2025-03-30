#include "X43RegisterInfo.h"
#include "MCTargetDesc/X43MCTargetDesc.h"
#include "X43FrameLowering.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFunction.h"
#include <llvm/CodeGen/TargetSubtargetInfo.h>

#define GET_REGINFO_TARGET_DESC
#include "X43GenRegisterInfo.inc"

namespace llvm {
X43RegisterInfo::X43RegisterInfo() : llvm::X43GenRegisterInfo(llvm::X43::X0) {}
const MCPhysReg *
X43RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  return CSR_X43_SaveList;
}

BitVector X43RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector reserved(getNumRegs());
  reserved.set(X43::FP);
  reserved.set(X43::SP);
  reserved.set(X43::X0);
  return reserved;
}

bool X43RegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  return false;
}

Register X43RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return llvm::X43::FP;
}

const uint32_t *
X43RegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  return CSR_X43_RegMask;
}
} // namespace llvm
