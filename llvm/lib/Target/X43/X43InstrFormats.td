class Format<bits<5> val> {
    bits<5> Value = val;
}

def NoOp : Format<0>;
def RI64 : Format<1>;

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

class X43RI64<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern> : X43Inst<outs, ins, asmstr, pattern, RI64> {
    field bits<16> Inst;
    bits<8> reg;

    let Inst{7...0} = op;
    let Inst{15...8} = reg;
}
