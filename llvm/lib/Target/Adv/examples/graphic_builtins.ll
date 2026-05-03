define dso_local void @app() {
entry:
    %2 = call i32  @llvm.adv.rand()
    call void @llvm.adv.putpixel(i32 %2, i32 5, i32 -1)
    call void @llvm.adv.flush()
    ret void
}

declare i32  @llvm.sim.rand()
declare void @llvm.sim.putpixel(i32, i32, i32)
declare void @llvm.sim.flush()