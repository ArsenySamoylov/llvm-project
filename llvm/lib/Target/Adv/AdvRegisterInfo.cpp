#include "llvm/CodeGen/TargetInstrInfo.h"

#include "adv.h"
#include "AdvRegisterInfo.h"
#include "AdvFrameLowering.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "AdvGenRegisterInfo.inc"

AdvRegisterInfo::AdvRegisterInfo() : AdvGenRegisterInfo(Adv::R0) {
  ADV_DUMP_GREEN
}