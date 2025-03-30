#include "X43TargetMachine.h"
#include "TargetInfo/X43TargetInfo.h"
#include "X43.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

namespace {
class X43PassConfig : public TargetPassConfig {
public:
  using TargetPassConfig::TargetPassConfig;

  bool addInstSelector() override {
    addPass(createX43ISelDag(getX43TargetMachine(), getOptLevel()));
    return false;
  }

  X43TargetMachine &getX43TargetMachine() const {
    return getTM<X43TargetMachine>();
  }
};
} // namespace

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeX43Target() {
  // Register the target.
  RegisterTargetMachine<X43TargetMachine> A(getTheX43Target());
}

X43TargetMachine::X43TargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:64:64-i8:8:8-i16:16-i64:64-n64", TT,
                               CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()), // just ELF for now
      SubTarget(CPU, CPU, FS, *this) {
  initAsmInfo();
}

TargetPassConfig *X43TargetMachine::createPassConfig(PassManagerBase &PM) {
  return new X43PassConfig(*this, PM);
}

TargetLoweringObjectFile *X43TargetMachine::getObjFileLowering() const {
  return TLOF.get();
}

const TargetSubtargetInfo *
X43TargetMachine::getSubtargetImpl(const Function &) const {
  return &SubTarget;
}