#pragma once

#include "X43TargetMachine.h"
#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
class SimTargetMachine;
class FunctionPass;
class SimSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerX43MachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerX43MachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createX43ISelDag(X43TargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm