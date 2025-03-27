#include "X43Subtarget.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
X43Subtarget::X43Subtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : X43GenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {}
} // namespace llvm
