class X43Register;

class RegsRange<int start, int end, string prefix = "X"> {
    list<X43Register> Regs = !foreach(i, !range(start, end), !cast<X43Register>(prefix#i));
}