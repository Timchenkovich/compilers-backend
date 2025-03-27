#pragma once

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include <optional>

namespace llvm {
extern Target TheX43Target;

class X43TargetMachine : public CodeGenTargetMachineImpl {
public:
  X43TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};

} // end namespace llvm
