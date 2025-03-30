add_llvm_component_group(X43)

set(LLVM_TARGET_DEFINITIONS X43.td)

tablegen(LLVM X43GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM X43GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM X43GenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM X43GenCallingConv.inc -gen-callingconv)
tablegen(LLVM X43GenDAGISel.inc -gen-dag-isel)
tablegen(LLVM X43GenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(X43CommonTableGen)

 
 add_llvm_target(X43CodeGen
   X43TargetMachine.cpp
   X43RegisterInfo.cpp
   X43InstrInfo.cpp
   X43Subtarget.cpp
   X43AsmPrinter.cpp
   X43ISelLowering.cpp
   X43FrameLowering.cpp
   X43MCInstLower.cpp
  
   LINK_COMPONENTS
   CodeGen
   Core
   Support
   Target
   X43Info
   AsmPrinter
   SelectionDAG
 
   ADD_TO_COMPONENT
   X43
   )
 
 add_subdirectory(MCTargetDesc)
 add_subdirectory(TargetInfo)