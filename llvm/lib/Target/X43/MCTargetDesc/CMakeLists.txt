add_llvm_component_library(LLVMX43Desc
   X43MCTargetDesc.cpp
   X43MCAsmInfo.cpp
   X43InstPrinter.cpp
 
   LINK_COMPONENTS
   MC
   Support
   X43Info
 
   ADD_TO_COMPONENT
   X43
  )