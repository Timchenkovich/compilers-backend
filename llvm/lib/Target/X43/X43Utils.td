class X43Register;

class RegsRange<int start, int end> {
    list<X43Register> Regs = !foreach(i, !range(start, end), !cast<X43Register>("X"#i));
}