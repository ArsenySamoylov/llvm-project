#pragma once

// Defines symbolic names for Adv registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "AdvGenRegisterInfo.inc"

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;

MCCodeEmitter *createAdvMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
} // namespace llvm


// Defines symbolic names for the Adv instructions.
#define GET_INSTRINFO_ENUM
#include "AdvGenInstrInfo.inc"