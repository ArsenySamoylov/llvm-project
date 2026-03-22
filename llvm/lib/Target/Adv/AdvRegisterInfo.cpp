#include "llvm/CodeGen/TargetInstrInfo.h"

#include "adv.h"
#include "AdvRegisterInfo.h"
#include "AdvFrameLowering.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "AdvGenRegisterInfo.inc"

AdvRegisterInfo::AdvRegisterInfo() : AdvGenRegisterInfo(Adv::R0) {
  ADV_DUMP_GREEN
}

const MCPhysReg *
AdvRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  ADV_DUMP_GREEN
  return CSR_Adv_SaveList;
}

BitVector AdvRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  ADV_DUMP_GREEN
  AdvFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(Adv::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(Adv::R2);
  }
  return Reserved;
}

bool AdvRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool AdvRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  ADV_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register AdvRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  ADV_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? Adv::R2 : Adv::R1;
}

const uint32_t *
AdvRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  ADV_DUMP_GREEN
  return CSR_Adv_RegMask;
}