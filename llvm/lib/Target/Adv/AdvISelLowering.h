#pragma once

#include "adv.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class AdvSubtarget;
class AdvTargetMachine;

namespace AdvISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace AdvISD

class AdvTargetLowering : public TargetLowering {
public:
  explicit AdvTargetLowering(const TargetMachine &TM, const AdvSubtarget &STI);

  /// This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  AdvSubtarget const &getSubtarget() const { return STI; }

private:
  const AdvSubtarget &STI;
};


} // end namespace llvm