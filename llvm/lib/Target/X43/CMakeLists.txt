add_llvm_component_group(X43)

set(LLVM_TARGET_DEFINITIONS X43.td)

tablegen(LLVM X43GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM X43GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM X43GenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(X43CommonTableGen)

 
 add_llvm_target(X43CodeGen
   X43TargetMachine.cpp
   X43RegisterInfo.cpp
   X43InstrInfo.cpp
   X43Subtarget.cpp
  
   LINK_COMPONENTS
   CodeGen
   Core
   Support
   Target
   X43Info
 
   ADD_TO_COMPONENT
   X43
   )
 
 add_subdirectory(MCTargetDesc)
 add_subdirectory(TargetInfo)