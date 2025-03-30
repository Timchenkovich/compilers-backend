include "llvm/Target/Target.td"

include "X43Utils.td"
include "X43RegisterInfo.td"

include "X43InstrInfo.td"
include "X43CallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
  : Processor<Name, NoItineraries, Features>;
 
def : Proc<"generic", []>;

def X43InstrInfo : InstrInfo;

def X43 : Target {
    let InstructionSet = X43InstrInfo;
}