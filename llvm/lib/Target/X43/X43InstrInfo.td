include "X43InstrFormats.td"


def ret : SDNode<"X43ISD::RET", SDTNone>;

let isBranch = 1, isTerminator = 1 in
def Ret : X43NoOp<0x1, (outs), (ins), "ret", [(ret)]>;