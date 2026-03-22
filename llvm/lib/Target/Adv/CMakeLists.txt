add_llvm_component_group(Adv)


set(LLVM_TARGET_DEFINITIONS Adv.td)

tablegen(LLVM AdvGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM AdvGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM AdvGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM AdvGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM AdvGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM AdvGenCallingConv.inc -gen-callingconv)
tablegen(LLVM AdvGenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(AdvCommonTableGen)

add_llvm_target(AdvCodeGen
    AdvTargetMachine.cpp
    AdvRegisterInfo.cpp
    AdvInstrInfo.cpp
    AdvSubtarget.cpp
    AdvAsmPrinter.cpp
    AdvISelDagToDag.cpp
    AdvISelLowering.cpp
    
    LINK_COMPONENTS
    CodeGen
    Core
    Support
    Target
    AdvInfo
    AsmPrinter
    SelectionDAG


    ADD_TO_COMPONENT
    Adv
)

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)