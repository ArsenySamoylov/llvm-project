include "llvm/Target/Target.td"

include "AdvRegisterInfo.td"
include "AdvInstrInfo.td"

def AdvInstrInfo : InstrInfo;

def Adv : Target {
    let InstructionSet = AdvInstrInfo;
}