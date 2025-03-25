#ifndef LLVM_LIB_TARGET_X43_X43TARGETMACHINE_H
#define LLVM_LIB_TARGET_X43_X43TARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
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
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_X43_X43TARGETMACHINE_H