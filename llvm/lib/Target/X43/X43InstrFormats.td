class X43Inst<dag outs, dag ins, string asmstr, list<dag> pattern> : Instruction {
    let Namespace = "X43";
    let DecoderNamespace = "X43";

    let AsmString = asmstr;

    let OutOperandList = outs;
    let InOperandList = ins;

    let Pattern = pattern;
}


class X43Short<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern> : X43Inst<outs, ins, asmstr, pattern> {
    field bits<8> Inst;
    let Inst{7...0} = op;
}

class X43Reg<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern> : X43Inst<outs, ins, asmstr, pattern> {
    field bits<16> Inst;
    bits<8> reg;

    let Inst{7...0} = op;
    let Inst{15...8} = reg;
}
