#include "TargetInfo/X43TargetInfo.h"
#include "X43.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheX43Target() {
  X43_DUMP_YELLOW
  static Target TheX43Target;
  return TheX43Target;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeX43TargetInfo() {
  X43_DUMP_YELLOW
  RegisterTarget<Triple::x43> X(getTheX43Target(), "X43",
                                "X43ulator target for LLVM course", "X43");
}