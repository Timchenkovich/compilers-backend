add_llvm_component_group(X43)
 
 add_llvm_target(X43CodeGen
   X43TargetMachine.cpp
 
   LINK_COMPONENTS
   CodeGen
   Core
   Support
   Target
   SimInfo
 
   ADD_TO_COMPONENT
   X43
   )
 
 add_subdirectory(MCTargetDesc)
 add_subdirectory(TargetInfo)