#include "TargetInfo/X43TargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheX43Target() {
  static Target TheX43Target;
  return TheX43Target;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeX43TargetInfo() {
  RegisterTarget<Triple::x43> X(getTheX43Target(), "x43",
                                "Simple x86-like target", "X43");
}