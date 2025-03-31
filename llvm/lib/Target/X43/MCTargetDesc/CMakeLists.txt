add_llvm_component_library(LLVMX43Desc
   X43MCTargetDesc.cpp
   X43MCAsmInfo.cpp
   X43InstPrinter.cpp
   X43MCCodeEmitter.cpp
   X43AsmBackend.cpp
   X43ELFObjectWriter.cpp
 
   LINK_COMPONENTS
   MC
   Support
   X43Info
 
   ADD_TO_COMPONENT
   X43
  )