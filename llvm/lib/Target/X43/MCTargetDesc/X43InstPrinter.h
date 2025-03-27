#pragma once

#include "llvm/MC/MCInstPrinter.h"
namespace llvm {
class X43InstPrinter : public MCInstPrinter {
public:
  using MCInstPrinter::MCInstPrinter;

public:
  std::pair<const char *, uint64_t>
  getMnemonic(const MCInst &MI) const override;

  void printInst(const MCInst *MI, uint64_t Address, StringRef Annot,
                 const MCSubtargetInfo &STI, raw_ostream &OS) override;

  void printRegName(raw_ostream &OS, MCRegister Reg) override;
};
} // namespace llvm
