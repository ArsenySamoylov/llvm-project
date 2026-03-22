#pragma once

#include "AdvRegisterInfo.h"
#include "MCTargetDesc/AdvInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "AdvGenInstrInfo.inc"

namespace llvm {

class AdvSubtarget;

class AdvInstrInfo : public AdvGenInstrInfo {
public:
  AdvInstrInfo();

};

} // end namespace llvm