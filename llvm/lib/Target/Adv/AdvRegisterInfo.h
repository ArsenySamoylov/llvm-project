#pragma once

#define GET_REGINFO_HEADER
#include "AdvGenRegisterInfo.inc"

namespace llvm {

struct AdvRegisterInfo : public AdvGenRegisterInfo {
public:
  AdvRegisterInfo();
};

} // end namespace llvm
