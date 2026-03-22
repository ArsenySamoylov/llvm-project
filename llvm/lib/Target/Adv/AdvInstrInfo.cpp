#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

#include "AdvInstrInfo.h"
#include "adv.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "AdvGenInstrInfo.inc"

#define DEBUG_TYPE "Adv-inst-info"

AdvInstrInfo::AdvInstrInfo() : AdvGenInstrInfo() { ADV_DUMP_GREEN }