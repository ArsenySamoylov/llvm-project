#include "llvm/ADT/Statistic.h"

#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/CodeGen/MachineModuleInfo.h"

#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/TargetRegistry.h"

#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

#include "adv.h"
#include "AdvSubtarget.h"
#include "AdvTargetMachine.h"
#include "TargetInfo/AdvTargetInfo.h"
#include "MCTargetDesc/AdvInstrPrinter.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"

namespace {

class AdvAsmPrinter : public AsmPrinter {
  const MCSubtargetInfo *STI;

public:
  explicit AdvAsmPrinter(TargetMachine &TM,
                         std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)), STI(TM.getMCSubtargetInfo()) {
    ADV_DUMP_GREEN
  }

  void emitInstruction(const MachineInstr *MI) override;

  StringRef getPassName() const override { return "Adv Assembly Printer"; }

  bool lowerPseudoInstExpansion(const MachineInstr *MI, MCInst &Inst);

  // Used in pseudo lowerings
  bool lowerOperand(const MachineOperand &MO, MCOperand &MCOp) const {
    return LowerAdvMachineOperandToMCOperand(MO, MCOp, *this);
  }
};

} // end anonymous namespace

// Simple pseudo-instructions have their lowering (with expansion to real
// instructions) auto-generated.
#include "AdvGenMCPseudoLowering.inc"

void AdvAsmPrinter::emitInstruction(const MachineInstr *MI) {
  ADV_DUMP_GREEN
  // Do any auto-generated pseudo lowerings.
  if (MCInst OutInst; lowerPseudoInstExpansion(MI, OutInst)) {
    EmitToStreamer(*OutStreamer, OutInst);
    return;
  }

  MCInst TmpInst;
  if (!lowerAdvMachineInstrToMCInst(MI, TmpInst, *this))
    EmitToStreamer(*OutStreamer, TmpInst);
}

// Force static initialization.
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAdvAsmPrinter() {
  RegisterAsmPrinter<AdvAsmPrinter> X(getTheAdvTarget());
}