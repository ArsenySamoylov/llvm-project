add_llvm_component_group(Adv)

add_llvm_target(AdvCodeGen
    AdvTargetMachine.cpp

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