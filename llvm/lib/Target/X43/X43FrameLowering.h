#pragma once

#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class X43FrameLowering : public llvm::TargetFrameLowering {
public:
  using llvm::TargetFrameLowering::TargetFrameLowering;

public:
  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  bool hasFPImpl(const MachineFunction &MF) const override;
};
} // namespace llvm
