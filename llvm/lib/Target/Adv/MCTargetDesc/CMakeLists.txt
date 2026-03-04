add_llvm_component_library(LLVMAdvDesc
    AdvMCTargetDesc.cpp

    LINK_COMPONENTS
    MC
    Support
    AdvInfo

    ADD_TO_COMPONENT
    Adv
)