
#include "TargetInfo/X43TargetInfo.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/StackMaps.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Target/TargetMachine.h"

namespace {
class X43AsmPrinter : public llvm::AsmPrinter {
public:
  X43AsmPrinter(llvm::TargetMachine &TM,
                std::unique_ptr<llvm::MCStreamer> &&Streamer)
      : llvm::AsmPrinter(TM, std::move(Streamer)) {}

public:
  llvm::StringRef getPassName() const override {
    return "X43 assembly printer";
  }
};

llvm::AsmPrinter *
createAsmPrinter(llvm::TargetMachine &TM,
                 std::unique_ptr<llvm::MCStreamer> &&Streamer) {
  return new X43AsmPrinter(TM, std::move(Streamer));
}

} // namespace
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeX43AsmPrinter() {
  llvm::TargetRegistry::RegisterAsmPrinter(llvm::getTheX43Target(),
                                           createAsmPrinter);
}