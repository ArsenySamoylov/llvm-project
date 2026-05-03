//===----------------------------------------------------------------------===//
// Adv profiles and nodes
//===----------------------------------------------------------------------===//

def adv_ret      : SDNode<"AdvISD::RET", SDTNone,
                            [SDNPHasChain, SDNPOptInGlue, SDNPVariadic]>;

//===----------------------------------------------------------------------===//
// Instruction format superclass
//===----------------------------------------------------------------------===//

include "AdvInstrFormats.td"

//===----------------------------------------------------------------------===//
// Adv Operand, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

class SImmAsmOperand<int width> : AsmOperandClass {
  let Name = "SImm" # width;
  let RenderMethod = "addImmOperands";
  let DiagnosticType = !strconcat("Invalid", Name);
}

def simm16 : Operand<i32>, ImmLeaf<i32, [{return isInt<16>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<16>;
  let EncoderMethod = "getSImm16OpValue";
  let DecoderMethod = "decodeSImmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isInt<16>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_SIMM16";
  let OperandNamespace = "AdvOp";
}

//===----------------------------------------------------------------------===//
// Adv Instructions
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0, isCall = 1, isBranch = 1, isTerminator = 1, r2 = 0, r3_imm = 0 in
def BR : AdvInst<0xBB, (outs), (ins GPR:$r1), "BR $r1",
                  [(brind GPR:$r1)]>;

let isBarrier = 1, isReturn = 1, isTerminator = 1 in
def PseudoRET : AdvPseudoInst<(outs), (ins), "# PseudoRET",
                [(adv_ret)]>,
                PseudoInstExpansion<(BR R0)>;

// movli
let isAsCheapAsAMove = 1, isCodeGenOnly = 1, isReMaterializable = 1, r2 = 0 in
def MOVLI : AdvInst<0xAA, (outs GPR:$r1), (ins simm16:$r3_imm),
                     "MOVli $r1 $r3_imm",
                     [(set GPR:$r1, simm16:$r3_imm)]>;

// flush
let r1 = 0, r2 = 0, r3_imm = 0 in
def FLUSH : AdvInst<0xFF, (outs), (ins), "FLUSH", [(int_adv_flush)]>;

// putpixel
def PUTPIXEL : AdvInst<0xEE, (outs), (ins GPR:$r1, GPR:$r2, GPR:$r3_imm),
                      "PUTPIXEL $r1 $r2 $r3_imm", [(int_adv_putpixel GPR:$r1, GPR:$r2, GPR:$r3_imm)]>;

// rand
let r1 = 0, r2 = 0, r3_imm = 0 in
def RAND : AdvInst<0xAD, (outs GPR:$r1), (ins), 
                      "RAND $r1", 
                      [(set GPR:$r1, (int_adv_rand))]>;