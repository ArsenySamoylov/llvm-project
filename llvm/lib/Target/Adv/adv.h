#pragma once

#include "llvm/Support/raw_ostream.h"

#include "llvm/Target/TargetMachine.h"

#include "MCTargetDesc/AdvMCTargetDesc.h"

#define ADV_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define ADV_DUMP(Color) {}

#define ADV_DUMP_RED     ADV_DUMP(llvm::raw_ostream::RED)
#define ADV_DUMP_GREEN   ADV_DUMP(llvm::raw_ostream::GREEN)
#define ADV_DUMP_YELLOW  ADV_DUMP(llvm::raw_ostream::YELLOW)
#define ADV_DUMP_CYAN    ADV_DUMP(llvm::raw_ostream::CYAN)
#define ADV_DUMP_MAGENTA ADV_DUMP(llvm::raw_ostream::MAGENTA)
#define ADV_DUMP_WHITE   ADV_DUMP(llvm::raw_ostream::WHITE)

namespace llvm {
class AdvTargetMachine;
class FunctionPass;

FunctionPass *createAdvISelDag(AdvTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm