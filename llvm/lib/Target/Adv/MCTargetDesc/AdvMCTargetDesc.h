#pragma once

// Defines symbolic names for Adv registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "AdvGenRegisterInfo.inc"

#include <memory>

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createAdvMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createAdvAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);

std::unique_ptr<MCObjectTargetWriter> createAdvELFObjectWriter(bool Is64Bit,
                                                               uint8_t OSABI);
} // namespace llvm


// Defines symbolic names for the Adv instructions.
#define GET_INSTRINFO_ENUM
#include "AdvGenInstrInfo.inc"