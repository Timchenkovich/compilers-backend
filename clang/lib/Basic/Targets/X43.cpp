#include "X43.h"
#include "clang/Basic/Builtins.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"
#include <optional>

using namespace clang;

namespace {
constexpr Builtin::Info BuiltinInfo[] = {
#define BUILTIN(ID, TYPE, ATTRS)                                               \
  {#ID, TYPE, ATTRS, nullptr, HeaderDesc::NO_HEADER, ALL_LANGUAGES},
#include "clang/Basic/BuiltinsX43.def"
};
} // namespace

namespace clang::targets {
X43TargetInfo::X43TargetInfo(const llvm::Triple &Triple,
                             const TargetOptions &Opts)
    : TargetInfo(Triple) {
  NoAsmVariants = true;
  LongLongAlign = 64;
  SuitableAlign = 32;
  DoubleAlign = LongDoubleAlign = 64;
  SizeType = UnsignedLongLong;
  PtrDiffType = SignedLongLong;
  IntPtrType = SignedLongLong;
  WCharType = UnsignedChar;
  WIntType = UnsignedInt;
  resetDataLayout("e-m:e-p:64:64-i8:8:8-i16:16-i64:64-n64");
}

void X43TargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__x43__");
}

ArrayRef<Builtin::Info> X43TargetInfo::getTargetBuiltins() const {
  return llvm::ArrayRef(BuiltinInfo,
                        clang::X43::LastTSBuiltin - Builtin::FirstTSBuiltin);
}

auto X43TargetInfo::getBuiltinVaListKind() const -> BuiltinVaListKind {
  return TargetInfo::VoidPtrBuiltinVaList;
}

std::string_view X43TargetInfo::getClobbers() const { return ""; }

ArrayRef<const char *> X43TargetInfo::getGCCRegNames() const {
  static const char *const GCCRegNames[] = {
      "x0",  "x1",  "x2",  "x3",  "x4",  "x5",  "x6",  "x7",  "x8",
      "x9",  "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17",
      "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26",
      "x27", "x28", "x29", "sp",  "r",   "fp"};
  return llvm::ArrayRef(GCCRegNames);
}

ArrayRef<TargetInfo::GCCRegAlias> X43TargetInfo::getGCCRegAliases() const {
  return std::nullopt;
}

bool X43TargetInfo::validateAsmConstraint(
    const char *&Name, TargetInfo::ConstraintInfo &Info) const {
  return false;
}
} // namespace clang::targets
