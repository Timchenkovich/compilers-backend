#pragma once

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class X43ELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit X43ELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm