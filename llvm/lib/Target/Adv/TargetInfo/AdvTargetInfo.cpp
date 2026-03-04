#include "TargetInfo/AdvTargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

#include "adv.h"

using namespace llvm;

Target &llvm::getTheAdvTarget() {
  ADV_DUMP_YELLOW
  static Target TheAdvTarget;
  return TheAdvTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAdvTargetInfo() {
  ADV_DUMP_YELLOW
  RegisterTarget<Triple::adv> X(getTheAdvTarget(), "adv",
                                "Advanced Arseny Ltd. target for LLVM course", "ADV");
}