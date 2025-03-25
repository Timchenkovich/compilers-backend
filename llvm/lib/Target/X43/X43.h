#ifndef LLVM_LIB_TARGET_X43_X43_H
#define LLVM_LIB_TARGET_X43_X43_H

#include "llvm/Support/raw_ostream.h"

#define X43_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define SIM_DUMP(Color) {}

#define X43_DUMP_RED X43_DUMP(llvm::raw_ostream::RED)
#define X43_DUMP_GREEN X43_DUMP(llvm::raw_ostream::GREEN)
#define X43_DUMP_YELLOW X43_DUMP(llvm::raw_ostream::YELLOW)
#define X43_DUMP_CYAN X43_DUMP(llvm::raw_ostream::CYAN)
#define X43_DUMP_MAGENTA X43_DUMP(llvm::raw_ostream::MAGENTA)

#endif // LLVM_LIB_TARGET_Sim_Sim_H