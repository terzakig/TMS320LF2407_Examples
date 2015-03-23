*******************************************************
* TMS320C24xx ANSI C Codegen Version 7.04       
*******************************************************
;	dspac -q -d_DEBUG -v2xx -iC:/CCStudio_v3.1/c2400/cgtools/include afmain.c C:\DOCUME~1\George\LOCALS~1\Temp\afmain.if 
;	dspopt NOT RUN
;	dspcg -o -q -v2xx -o C:\DOCUME~1\George\LOCALS~1\Temp\afmain.if C:\DOCUME~1\George\LOCALS~1\Temp\afmain.asm C:\DOCUME~1\George\LOCALS~1\Temp\afmain.tmp 
	.port
	.file	"afmain.c"
	.globl	_convolve
	.text

	.sym	_main,_main,32,2,0
	.globl	_main

	.func	6
;>>>> 	void main(void) {
******************************************************
* FUNCTION DEF : _main
******************************************************
_main:
	POPD	*+
	SAR	AR0,*+
	SAR	AR1,*
	LARK	AR0,9
	LAR	AR0,*0+,AR3


	.sect	".const"
	.sblock	".const"
.init0$1$$1:
	.word	1
	.word	1
	.word	1
	.text

	.sect	".const"
.init1$2$$2:
	.word	4
	.word	3
	.word	2
	.text
	.sym	_h,1,52,1,48,,3
	.sym	_x,4,52,1,48,,3
	.sym	_ach,7,4,1,16
	.sym	_acl,8,4,1,16
	.line	3
;>>>> 	int h[] = {1, 1, 1};
	LARK	AR3,1
	MAR	*0+
	RPTK	2
	BLKD	.init0$1$$1+0,*+
	.line	4
;>>>> 	int x[] = {4, 3, 2};
;>>>> 	int ach, acl;
	LARK	AR3,4
	MAR	*0+
	RPTK	2
	BLKD	.init1$2$$2+0,*+
	.line	11
;>>>> 	convolve(&h[2], &x[2], 2, 5, &acl, &ach);
;>>>> 	while (1) {
	LARK	AR3,7
	MAR	*0+,AR1
	SAR	AR3,*+,AR4
	LARK	AR4,8
	MAR	*0+,AR1
	SAR	AR4,*+
	LACK	5
	SACL	*+
	LACK	2
	SACL	*+,AR5
	LARK	AR5,6
	MAR	*0+,AR1
	SAR	AR5,*+,AR5
	LARK	AR5,3
	MAR	*0+,AR1
	SAR	AR5,*+
	CALL	_convolve
	SBRK	6
L1:
	.line	15
	B	L1
	.endfunc	22,000000000H,9
	.end
