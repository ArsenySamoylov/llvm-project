#include "llvm/MC/TargetRegistry.h"
#include <optional>

#include "AdvTargetMachine.h"
#include "TargetInfo/AdvTargetInfo.h"

#include "adv.h"

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAdvTarget() {
  // Register the target.
  ADV_DUMP_CYAN
  RegisterTargetMachine<AdvTargetMachine> A(getTheAdvTarget());
}

AdvTargetMachine::AdvTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(
          T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32", TT, CPU, FS, Options,
          Reloc::Static, getEffectiveCodeModel(CM, CodeModel::Small), OL) {
  ADV_DUMP_CYAN
  initAsmInfo();
}