#pragma once

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class AdvELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit AdvELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm