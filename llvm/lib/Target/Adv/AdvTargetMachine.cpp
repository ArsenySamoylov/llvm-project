#include "llvm/MC/TargetRegistry.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"

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
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()) {
  ADV_DUMP_CYAN
  initAsmInfo();
}

namespace {

/// Adv Code Generator Pass Configuration Options.
class AdvPassConfig : public TargetPassConfig {
public:
  AdvPassConfig(AdvTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  AdvTargetMachine &getAdvTargetMachine() const {
    return getTM<AdvTargetMachine>();
  }

  bool addInstSelector() override {
    ADV_DUMP_CYAN
    addPass(createAdvISelDag(getAdvTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *AdvTargetMachine::createPassConfig(PassManagerBase &PM) {
  ADV_DUMP_CYAN
  return new AdvPassConfig(*this, PM);
}

TargetLoweringObjectFile *AdvTargetMachine::getObjFileLowering() const {
  ADV_DUMP_CYAN
  return TLOF.get();
}