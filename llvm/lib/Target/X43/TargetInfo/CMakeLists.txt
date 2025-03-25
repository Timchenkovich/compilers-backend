add_llvm_component_library(LLVMX43Info
   X43TargetInfo.cpp
 
   LINK_COMPONENTS
   MC
   Support
 
   ADD_TO_COMPONENT
   X43
)