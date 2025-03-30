#pragma once

#include "X43FrameLowering.h"
#include "X43RegisterInfo.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {
class X43Subtarget;
}

namespace X43ISD {
enum NodeType { FIRST_NUMBER = llvm::ISD::BUILTIN_OP_END, RET, CALL };
} // namespace X43ISD

namespace llvm {
class X43TargetLowering : public TargetLowering {
private:
  const X43Subtarget &Subtarget;

public:
  X43TargetLowering(const TargetMachine &TM, const X43Subtarget &subtarget);

  SDValue LowerCall(CallLoweringInfo & /*CLI*/,
                    SmallVectorImpl<SDValue> & /*InVals*/) const override;

  SDValue LowerReturn(SDValue /*Chain*/, CallingConv::ID /*CallConv*/,
                      bool /*isVarArg*/,
                      const SmallVectorImpl<ISD::OutputArg> & /*Outs*/,
                      const SmallVectorImpl<SDValue> & /*OutVals*/,
                      const SDLoc & /*dl*/,
                      SelectionDAG & /*DAG*/) const override;

  SDValue
  LowerFormalArguments(SDValue /*Chain*/, CallingConv::ID /*CallConv*/,
                       bool /*isVarArg*/,
                       const SmallVectorImpl<ISD::InputArg> & /*Ins*/,
                       const SDLoc & /*dl*/, SelectionDAG & /*DAG*/,
                       SmallVectorImpl<SDValue> & /*InVals*/) const override;

  bool CanLowerReturn(CallingConv::ID CallConv, MachineFunction &MF,
                      bool IsVarArg,
                      const SmallVectorImpl<ISD::OutputArg> &Outs,
                      LLVMContext &Context, const Type *RetTy) const override;

private:
  SDValue LowerMemArgument(SDValue Chain, CallingConv::ID CallConv,
                           const SmallVectorImpl<ISD::InputArg> &Ins,
                           const SDLoc &dl, SelectionDAG &DAG,
                           const CCValAssign &VA, MachineFrameInfo &MFI,
                           unsigned i) const;
};
} // namespace llvm