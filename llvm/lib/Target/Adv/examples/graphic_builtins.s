	.file	"graphic_builtins.ll"
	.text
	.globl	app                             ; -- Begin function app
	.type	app,@function
app:                                    ; @app
; %bb.0:                                ; %entry
	RAND r2
	MOVli r4 -1
	MOVli r9 5
	PUTPIXEL r2 r9 r4
	FLUSH
	BR r0
.Lfunc_end0:
	.size	app, .Lfunc_end0-app
                                        ; -- End function
	.section	".note.GNU-stack","",@progbits
