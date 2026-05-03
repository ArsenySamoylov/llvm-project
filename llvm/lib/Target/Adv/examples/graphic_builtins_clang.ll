; ModuleID = '../llvm-project/llvm/lib/Target/Adv/examples/graphic_builtins.c'
source_filename = "../llvm-project/llvm/lib/Target/Adv/examples/graphic_builtins.c"
target datalayout = "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32"
target triple = "adv"

; Function Attrs: noinline nounwind optnone
define dso_local void @app() #0 {
  %1 = alloca i32, align 4
  %2 = call i32 @llvm.adv.rand()
  store i32 %2, ptr %1, align 4
  %3 = load i32, ptr %1, align 4
  call void @llvm.adv.putpixel(i32 5, i32 5, i32 %3)
  call void @llvm.adv.flush()
  ret void
}

; Function Attrs: nounwind
declare i32 @llvm.adv.rand() #1

; Function Attrs: nounwind
declare void @llvm.adv.putpixel(i32, i32, i32) #1

; Function Attrs: nounwind
declare void @llvm.adv.flush() #1

attributes #0 = { noinline nounwind optnone "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" }
attributes #1 = { nounwind }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 1}
!1 = !{i32 7, !"frame-pointer", i32 2}
!2 = !{!"clang version 20.1.0 (https://github.com/ArsenySamoylov/llvm-project.git 39f84370414cc6f705407103454b1fe0bd6d591f)"}
