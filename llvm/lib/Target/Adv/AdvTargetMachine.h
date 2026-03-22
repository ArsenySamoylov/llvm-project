#pragma once

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>


#include "AdvSubtarget.h"

namespace llvm {
extern Target TheAdvTarget;

class AdvTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  AdvSubtarget Subtarget;

public:
  AdvTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const AdvSubtarget *getSubtargetImpl(const Function &) const override {
    ADV_DUMP_CYAN
    return &Subtarget;
  }

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm
