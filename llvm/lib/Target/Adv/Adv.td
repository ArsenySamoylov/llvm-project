include "llvm/Target/Target.td"

include "AdvRegisterInfo.td"
include "AdvInstrInfo.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def AdvInstrInfo : InstrInfo;

def Adv : Target {
    let InstructionSet = AdvInstrInfo;
}