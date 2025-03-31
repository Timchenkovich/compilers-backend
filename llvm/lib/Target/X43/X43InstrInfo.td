include "X43InstrFormats.td"

class SImmAsmOperand<int width> : AsmOperandClass {
   let Name = "SImm" # width;
   let RenderMethod = "addImmOperands";
   let DiagnosticType = !strconcat("Invalid", Name);
 }

def simm64 : Operand<i64>, ImmLeaf<i64, [{return isInt<64>(Imm);}]> {
   let ParserMatchClass = SImmAsmOperand<64>;
   let EncoderMethod = "getSimm64OpValue";
   let DecoderMethod = "decodeSImmOperand<64>";
   let MCOperandPredicate = [{
     int64_t Imm;
     if (MCOp.evaluateAsConstantImm(Imm))
       return isInt<64>(Imm);
     return MCOp.isBareSymbolRef();
   }];
   let OperandType = "OPERAND_SIMM64";
   let OperandNamespace = "X43Op";
 }


def ret : SDNode<"X43ISD::RET", SDTNone, [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;
def call : SDNode<"X43ISD::CALL", SDTypeProfile<0, -1, []>, [SDNPHasChain, SDNPOutGlue, SDNPOptInGlue, SDNPVariadic]>;

let isBranch = 1, isTerminator = 1 in
def Ret : X43Short<0x1, (outs), (ins), "ret", [(ret)]>;

let isCall = 1, isTerminator = 1 in
def Call : X43Short<0x0, (outs), (ins GPR:$dst), "call $dst", [(call GPR:$dst)]>;


let isAsCheapAsAMove = 1, isReMaterializable = 1 in
 def MovRImm : X43Reg<0x2, (outs GPR:$reg), (ins simm64:$imm),
                      "mov $reg $imm",
                      [(set GPR:$reg, simm64:$imm)]> {
}