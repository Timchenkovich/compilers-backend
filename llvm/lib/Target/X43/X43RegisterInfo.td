
class X43Register<bits<5> enc, string name> : Register<name> {
    let HWEncoding{4...0} = enc;
    let Namespace = "X43";
}


foreach I = 0-28 in {
    def X#I : X43Register<I, "x"#I>;
}

def SP : X43Register<29, "sp">;
def R : X43Register<30, "r">;
def FP : X43Register<31, "fp">;

def GPR : RegisterClass<"X43", [i64], 64, !dag(add, RegsRange<0, 29>.Regs, ?)>;
