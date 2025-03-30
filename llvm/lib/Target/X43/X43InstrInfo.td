include "X43InstrFormats.td"


def ret : SDNode<"X43ISD::RET", SDTNone, [SDNPHasChain, SDNPOptInGlue]>;
def call : SDNode<"X43ISD::CALL", SDTypeProfile<0, -1, []>, [SDNPHasChain, SDNPOutGlue, SDNPOptInGlue]>;

let isBranch = 1, isTerminator = 1 in
def Ret : X43Short<0x1, (outs), (ins), "ret", [(ret)]>;

let isCall = 1 in
def Call : X43Short<0x0, (outs), (ins GPR:$dst), "call $dst", [(call GPR:$dst)]>;