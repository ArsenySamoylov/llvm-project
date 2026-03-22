#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/MC/MCInstrInfo.h"

#include "TargetInfo/AdvTargetInfo.h"
#include "MCTargetDesc/AdvInfo.h"

#include "adv.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "AdvGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "AdvGenInstrInfo.inc"

static MCRegisterInfo *createAdvMCRegisterInfo(const Triple &TT) {
  ADV_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitAdvMCRegisterInfo(X, Adv::R0);


  return X;
}

static MCInstrInfo *createAdvMCInstrInfo() {
  ADV_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitAdvMCInstrInfo(X);
  return X;
}

// We need to define this function
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAdvTargetMC() {
    ADV_DUMP_MAGENTA
    Target &TheAdvTarget = getTheAdvTarget();
    // Register the MC register info.
    TargetRegistry::RegisterMCRegInfo(TheAdvTarget, createAdvMCRegisterInfo);
    // Register the MC instruction info.
    TargetRegistry::RegisterMCInstrInfo(TheAdvTarget, createAdvMCInstrInfo);
}