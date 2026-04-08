#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCDwarf.h"

#include "llvm/Support/ErrorHandling.h"

#include "TargetInfo/AdvTargetInfo.h"
#include "MCTargetDesc/AdvInfo.h"
#include "AdvMCAsmInfo.h"

#include "adv.h"
#include "AdvInstrPrinter.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "AdvGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "AdvGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "AdvGenSubtargetInfo.inc"

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

static MCSubtargetInfo *createAdvMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  ADV_DUMP_MAGENTA
  return createAdvMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createAdvMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  ADV_DUMP_MAGENTA
  MCAsmInfo *MAI = new AdvELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(Adv::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createAdvMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  ADV_DUMP_MAGENTA
  return new AdvInstPrinter(MAI, MII, MRI);
}


// We need to define this function
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAdvTargetMC() {
    ADV_DUMP_MAGENTA
    Target &TheAdvTarget = getTheAdvTarget();
    RegisterMCAsmInfoFn X(TheAdvTarget, createAdvMCAsmInfo);
    // Register the MC register info.
    TargetRegistry::RegisterMCRegInfo(TheAdvTarget, createAdvMCRegisterInfo);
    // Register the MC instruction info.
    TargetRegistry::RegisterMCInstrInfo(TheAdvTarget, createAdvMCInstrInfo);
    // Register the MC subtarget info.
    TargetRegistry::RegisterMCSubtargetInfo(TheAdvTarget,
                                          createAdvMCSubtargetInfo);
    
    // Register the MCInstPrinter
    TargetRegistry::RegisterMCInstPrinter(TheAdvTarget, createAdvMCInstPrinter);
    // Register the MC Code Emitter.
    TargetRegistry::RegisterMCCodeEmitter(TheAdvTarget, createAdvMCCodeEmitter);
}