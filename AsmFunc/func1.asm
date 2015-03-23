*******************************************************
* TMS320C24xx ANSI C Codegen Version 7.04       
*******************************************************
;	dspac -q -d_DEBUG -v2xx -iC:/CCStudio_v3.1/c2400/cgtools/include func1.c C:\DOCUME~1\George\LOCALS~1\Temp\func1.if 
;	dspopt NOT RUN
;	dspcg -o -q -v2xx -o C:\DOCUME~1\George\LOCALS~1\Temp\func1.if C:\DOCUME~1\George\LOCALS~1\Temp\func1.asm C:\DOCUME~1\George\LOCALS~1\Temp\func1.tmp 
	.port
	.file	"func1.c"
	.text

	.sym	_convolve,_convolve,32,2,0
	.globl	_convolve

	.func	3
******************************************************
* FUNCTION DEF : _convolve
******************************************************
_convolve:

LF1	.set	0

	POPD	*+
	SAR	AR0,*+
	SAR	AR1,*
	LARK	AR0,2
	LAR	AR0,*0+,AR2

	.sym	_h,-3+LF1,20,9,16
	.sym	_x,-4+LF1,20,9,16
	.sym	_N,-5+LF1,4,9,16
	.sym	_input,-6+LF1,4,9,16
	.sym	_acl,-7+LF1,20,9,16
	.sym	_ach,-8+LF1,20,9,16
	.sym	_result,1,14,1,16
	.line	1
;>>>> 	void convolve(int *h, int *x, int N,int input,  int *acl, int* ach) {
;>>>> 	   unsigned int result;
	.line	4
;>>>> 	   N=9;
	LACK	9
	LARK	AR2,-5+LF1
	MAR	*0+
	SACL	*+
	.line	6
;>>>> 	   result = *h + *x;
	LAR	AR3,*+
	LAR	AR4,* ,AR3
	SSXM
	LAC	* ,AR4
	ADD	* ,AR2
	ADRK	4-LF1
	SACL	* 
	.line	8
;>>>> 	   input=2;
	LACK	2
	SBRK	7-LF1
	SACL	*-
	.line	10
;>>>> 	   *acl = 5;
	LAR	AR5,*-,AR5
	LACK	5
	SACL	* ,AR2
	.line	11
;>>>> 	   *ach = 7;
	LAR	AR5,* ,AR5
	LACK	7
	SACL	* ,AR2
	.line	13
;>>>> 	   input = 1;
	LACK	1
	ADRK	2
	SACL	* ,AR1
EPI0_1:
	.line	14
	SBRK	3
	LAR	AR0,*-
	PSHD	*
	RET

	.endfunc	16,000000000H,2
	.end
