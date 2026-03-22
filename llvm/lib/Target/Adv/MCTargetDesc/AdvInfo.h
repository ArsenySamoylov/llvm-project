#pragma once

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace AdvOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace AdvOp

} // end namespace llvm