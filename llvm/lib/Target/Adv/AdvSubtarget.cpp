
#include "AdvSubtarget.h"
#include "adv.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "sim-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "AdvGenSubtargetInfo.inc"

AdvSubtarget::AdvSubtarget(const StringRef &CPU, const StringRef &TuneCPU,
                           const StringRef &FS, const TargetMachine &TM)
    : AdvGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  ADV_DUMP_CYAN
}