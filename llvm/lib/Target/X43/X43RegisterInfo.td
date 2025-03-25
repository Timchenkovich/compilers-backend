
class X43Register<bits<5> enc, string name> : Register<name> {
    let HWEncoding{4...0} = enc;
    let Namespace = "X43";
}


foreach I = 0-31 in {
    def X#I : X43Register<I, "x"#I>;
}


def GPR : RegisterClass<"X43", [i64], 64, !dag(add, !foreach(i, !range(0, 32), !cast<X43Register>("X"#i)), ?)>;

