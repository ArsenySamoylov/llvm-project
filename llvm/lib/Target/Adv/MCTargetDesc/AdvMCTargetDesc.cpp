#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"

#include "TargetInfo/AdvTargetInfo.h"
#include "adv.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "AdvGenRegisterInfo.inc"

static MCRegisterInfo *createAdvMCRegisterInfo(const Triple &TT) {
  ADV_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitAdvMCRegisterInfo(X, Adv::R0);
  return X;
}

// We need to define this function
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAdvTargetMC() {
    ADV_DUMP_MAGENTA
    Target &TheAdvTarget = getTheAdvTarget();
    // Register the MC register info.
    TargetRegistry::RegisterMCRegInfo(TheAdvTarget, createAdvMCRegisterInfo);
}