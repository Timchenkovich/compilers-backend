let TargetPrefix = "x43" in {
    def int_x43_putpixel: ClangBuiltin<"simPutPixel">, 
        Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
    def int_x43_flush : ClangBuiltin<"simFlush">,
        Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;
    def int_x43_rnd: ClangBuiltin<"simRand">,
        Intrinsic<[llvm_i32_ty], [], [IntrNoMem]>;
}