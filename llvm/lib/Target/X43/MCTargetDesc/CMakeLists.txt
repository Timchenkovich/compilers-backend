add_llvm_component_library(LLVMSimDesc
   X43MCTargetDesc.cpp
 
   LINK_COMPONENTS
   MC
   Support
   X43Info
 
   ADD_TO_COMPONENT
   X43
  )