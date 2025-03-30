#pragma once

#include "X43Subtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include <optional>

namespace llvm {
extern Target TheX43Target;

class X43TargetMachine : public CodeGenTargetMachineImpl {
private:
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  X43Subtarget SubTarget;

public:
  X43TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
  const TargetSubtargetInfo *getSubtargetImpl(const Function &) const override;
};

} // end namespace llvm
