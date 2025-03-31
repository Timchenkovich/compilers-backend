def RetCC_X43 : CallingConv<[
    CCIfType<[i64], CCAssignToReg<[X1, X2]>>
]>;

def CC_X43 : CallingConv<[
    CCIfType<[i8, i16, i32], CCPromoteToType<i64>>,
    CCIfType<[i64], CCAssignToReg<RegsRange<5, 10>.Regs>>,
    CCIfType<[i32], CCAssignToStack<4, 4>>,
    CCIfType<[i64], CCAssignToStack<8, 8>>
]>;

def CSR_X43 : CalleeSavedRegs<!dag(add, RegsRange<10, 15>.Regs, ?)>;