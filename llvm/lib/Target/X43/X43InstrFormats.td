class Format<bits<5> val> {
    bits<5> Value = val;
}

def NoOp : Format<0>;
def RI64 : Format<1>;
def R1: Format<2>;
def RRR: Format<3>;
def RI32: Format<4>;

class X43Inst<dag outs, dag ins, string asmstr, list<dag> pattern, Format form> : Instruction {
    let Namespace = "X43";
    let DecoderNamespace = "X43";

    let AsmString = asmstr;

    let OutOperandList = outs;
    let InOperandList = ins;

    let Pattern = pattern;
    let TSFlags{4...0} = form.Value;
}


class X43Short<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern> : X43Inst<outs, ins, asmstr, pattern, NoOp> {
    field bits<8> Inst;
    let Inst{7...0} = op;
}


class X43RBase<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern, Format f> : X43Inst<outs, ins, asmstr, pattern, f> {
    field bits<16> Inst;
    bits<8> reg;

    let Inst{7...0} = op;
    let Inst{15...8} = reg;
}


class X43RI32<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern> : X43RBase<op, outs, ins, asmstr, pattern, RI32>;
class X43RI64<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern> : X43RBase<op, outs, ins, asmstr, pattern, RI64>;
class X43R<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern> : X43RBase<op, outs, ins, asmstr, pattern, R1>;

class X43RRR<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern> : X43Inst<outs, ins, asmstr, pattern, RRR> {
    field bits<32> Inst;
    bits<8> r0;
    bits<8> r1;
    bits<8> r2;

    let Inst{7...0} = op;
    let Inst{15...8} = r0;
    let Inst{23...16} = r1;
    let Inst{31...24} = r2;
}