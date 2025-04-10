
class X43Register<bits<5> enc, string name,  list<Register> subregs = []> : Register<name> {
    let HWEncoding{4...0} = enc;
    let Namespace = "X43";
    let SubRegs = subregs;
}


def sub32: SubRegIndex<32>;


// H for half
foreach I = 0-28 in {
    def XH#I : X43Register<I, "xh"#I>;
}

let SubRegIndices = [sub32] in {
foreach I = 0-28 in {
    def X#I : X43Register<I, "x"#I, [!cast<X43Register>("XH"#I)]>;
}
}

def SP : X43Register<29, "sp">;
def R : X43Register<30, "r">;
def FP : X43Register<31, "fp">;

def GPRH : RegisterClass<"X43", [i32], 32, !dag(add, RegsRange<0, 29, "XH">.Regs, ?)>;
def GPR : RegisterClass<"X43", [i64], 64, !dag(add, RegsRange<0, 29>.Regs, ?)>;
