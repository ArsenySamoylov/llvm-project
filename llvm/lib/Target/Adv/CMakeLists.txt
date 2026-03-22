add_llvm_component_group(Adv)


set(LLVM_TARGET_DEFINITIONS Adv.td)

tablegen(LLVM AdvGenRegisterInfo.inc -gen-register-info)

add_public_tablegen_target(AdvCommonTableGen)

add_llvm_target(AdvCodeGen
    AdvTargetMachine.cpp
    AdvRegisterInfo.cpp
    
    LINK_COMPONENTS
    CodeGen
    Core
    Support
    Target
    AdvInfo


    ADD_TO_COMPONENT
    Adv
)

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)