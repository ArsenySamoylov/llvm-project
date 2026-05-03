#include "Adv.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

void AdvTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__adv__");
}

ArrayRef<Builtin::Info> AdvTargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}