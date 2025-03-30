#include "X43FrameLowering.h"

namespace llvm {
void X43FrameLowering::emitPrologue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {}
void X43FrameLowering::emitEpilogue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {}
bool X43FrameLowering::hasFPImpl(const MachineFunction &MF) const {
  return false;
}
} // namespace llvm
