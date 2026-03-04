
add_llvm_component_library(LLVMAdvInfo
  AdvTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  Adv
  )