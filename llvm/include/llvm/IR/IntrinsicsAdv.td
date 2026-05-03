let TargetPrefix = "adv" in {  // All intrinsics start with "llvm.adv.".
 
 def int_adv_putpixel: ClangBuiltin<"simPutPixel">,
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_adv_flush: ClangBuiltin<"simFlush">,
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

def int_adv_rand: ClangBuiltin<"simRand">,
   Intrinsic<[llvm_i32_ty], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "adv"