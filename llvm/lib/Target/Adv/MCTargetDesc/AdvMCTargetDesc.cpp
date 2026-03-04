#include "llvm/Support/raw_ostream.h"

#include "../adv.h"

// We need to define this function
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeAdvTargetMC() { ADV_DUMP_MAGENTA }

