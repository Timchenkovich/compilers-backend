#include "X43InstPrinter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCRegister.h"
#include <cassert>

using namespace llvm;

#include "X43GenAsmWriter.inc"

namespace llvm {

void X43InstPrinter::printInst(const MCInst *MI, uint64_t Address,
                               StringRef Annot, const MCSubtargetInfo &STI,
                               raw_ostream &OS) {
  printInstruction(MI, Address, OS);
  printAnnotation(OS, Annot);
}

void X43InstPrinter::printRegName(raw_ostream &OS, MCRegister Reg) {
  OS << getRegisterName(Reg);
}

void X43InstPrinter::printOperand(const MCInst *MI, int OpNo, raw_ostream &OS) {
  const MCOperand &MO = MI->getOperand(OpNo);

  if (MO.isReg()) {
    printRegName(OS, MO.getReg());
    return;
  }

  if (MO.isImm()) {
    OS << MO.getImm();
    return;
  }

  assert(MO.isExpr() && "Unknown operand kind in printOperand");
  MO.getExpr()->print(OS, &MAI);
}
} // namespace llvm
