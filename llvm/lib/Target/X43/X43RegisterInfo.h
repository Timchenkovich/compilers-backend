#pragma once

#define GET_REGINFO_ENUM
#define GET_REGINFO_HEADER
#include "X43GenRegisterInfo.inc"

namespace llvm {
class X43RegisterInfo : public llvm::X43GenRegisterInfo {
public:
  X43RegisterInfo();

public:
  const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const override;
  BitVector getReservedRegs(const MachineFunction &MF) const override;
  bool eliminateFrameIndex(MachineBasicBlock::iterator MI, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;
  Register getFrameRegister(const MachineFunction &MF) const override;
  const uint32_t *getCallPreservedMask(const MachineFunction &MF,
                                       CallingConv::ID CC) const override;
};
} // namespace llvm
