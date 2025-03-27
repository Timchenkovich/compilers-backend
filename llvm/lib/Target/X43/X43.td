include "llvm/Target/Target.td"
include "X43RegisterInfo.td"
include "X43InstrInfo.td"

def X43InstrInfo : InstrInfo;

def X43 : Target {
    let InstructionSet = X43InstrInfo;
}