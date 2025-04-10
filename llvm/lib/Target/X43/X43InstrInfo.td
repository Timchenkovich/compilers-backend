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

def simm32 : Operand<i32>, ImmLeaf<i32, [{return isInt<32>(Imm);}]> {
   let ParserMatchClass = SImmAsmOperand<32>;
   let EncoderMethod = "getSimm32OpValue";
   let DecoderMethod = "decodeSImmOperand<32>";
   let MCOperandPredicate = [{
     int64_t Imm;
     if (MCOp.evaluateAsConstantImm(Imm))
       return isInt<32>(Imm);
     return MCOp.isBareSymbolRef();
   }];
   let OperandType = "OPERAND_SIMM32";
   let OperandNamespace = "X43Op";
 }



def ret : SDNode<"X43ISD::RET", SDTNone, [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;
def call : SDNode<"X43ISD::CALL", SDTypeProfile<0, -1, []>, [SDNPHasChain, SDNPOutGlue, SDNPOptInGlue, SDNPVariadic]>;

let isBranch = 1, isTerminator = 1 in
def Ret : X43Short<0x1, (outs), (ins), "ret", [(ret)]>;

let isCall = 1, isTerminator = 1 in
def Call : X43Short<0x0, (outs), (ins GPR:$dst), "call $dst", [(call GPR:$dst)]>;


let isAsCheapAsAMove = 1, isReMaterializable = 1 in {
def MovRI64 : X43RI64<0x2, (outs GPR:$reg), (ins simm64:$imm),
                      "mov $reg $imm",
                      [(set GPR:$reg, simm64:$imm)]>;

// def MovRI32 : X43RI32<0x6, (outs GPR:$reg), (ins simm32:$imm), "mov $reg $imm", [(set GPR:$reg, (sext simm32:$imm))]>;

def MovRHI32 : X43RI32<0x7, (outs GPRH:$reg), (ins simm32:$imm), "mov $reg $imm", [(set GPRH:$reg, simm32:$imm)]>;
}
 
def PutPixel :
   X43RRR<0x3, (outs), (ins GPRH:$r0, GPRH:$r1, GPRH:$r2), "putpxl $r0 $r1 $r2", [(int_x43_putpixel GPRH:$r0, GPRH:$r1, GPRH:$r2)]>;

def Flush : X43Short<0x4, (outs), (ins), "flush", [(int_x43_flush)]>;

def Rnd : X43R<0x5, (outs GPRH:$reg), (ins), "rnd $reg", [(set GPRH:$reg, (int_x43_rnd))]>;
