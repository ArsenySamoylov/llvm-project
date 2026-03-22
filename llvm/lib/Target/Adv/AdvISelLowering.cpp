#include "AdvISelLowering.h"
#include "adv.h"
#include "AdvRegisterInfo.h"
#include "AdvSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "Adv-lower"

using namespace llvm;

AdvTargetLowering::AdvTargetLowering(const TargetMachine &TM,
                                     const AdvSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  ADV_DUMP_RED
  addRegisterClass(MVT::i32, &Adv::GPRRegClass);
}

const char *AdvTargetLowering::getTargetNodeName(unsigned Opcode) const {
  ADV_DUMP_RED
  switch (Opcode) {
  case AdvISD::CALL:
    return "AdvISD::CALL";
  case AdvISD::RET:
    return "AdvISD::RET";
  }
  return nullptr;
}