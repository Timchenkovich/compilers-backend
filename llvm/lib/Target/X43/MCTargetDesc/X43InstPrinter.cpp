#include "X43InstPrinter.h"
#include "llvm/MC/MCRegister.h"
#include <cassert>

namespace llvm {
std::pair<const char *, uint64_t>
X43InstPrinter::getMnemonic(const MCInst &MI) const {
  assert(false && "not yet implemented");
}

void X43InstPrinter::printInst(const MCInst *MI, uint64_t Address,
                               StringRef Annot, const MCSubtargetInfo &STI,
                               raw_ostream &OS) {
  assert(false && "not yet implemented");
}

void X43InstPrinter::printRegName(raw_ostream &OS, MCRegister Reg) {
  assert(false && "not yet implemented");
}
} // namespace llvm
