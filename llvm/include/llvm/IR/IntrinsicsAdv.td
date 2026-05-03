let TargetPrefix = "adv" in {  // All intrinsics start with "llvm.adv.".
 
 def int_adv_putpixel:
   Intrinsic<[], [llvm_i32_ty, llvm_i32_ty, llvm_i32_ty], [IntrNoMem, IntrHasSideEffects]>;
 
 def int_adv_flush:
   Intrinsic<[], [], [IntrNoMem, IntrHasSideEffects]>;

def int_adv_rand:
   Intrinsic<[llvm_i32_ty], [], [IntrNoMem, IntrHasSideEffects]>;
 
 } // TargetPrefix = "adv"