
	.port
	.file	"convasm.asm"
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
	LARK	AR2,-5+LF1
	MAR	*0+
	LAR AR7,*+, AR7   ; AR7 = N. Select AR7
	MAR *-, AR2       ; AR7 = AR7 -1. Select AR2
	.line	6
;>>>> 	   result = *h + *x;
	LAR	AR3,*+
	LAR	AR4,* ,AR3
	; [AR4] = last coefficient and [AR3] = oldest input in rolling buffer 
		; ******************* Preparing Sum *****************************
	   MPYK 0  ; ZERO the Product register
	   ZAC     ; ZERO the accumulator
	   SPM 0   ; PM = 0 (No product shifting)
	    
LOOP:  MAR *, AR3   ; Select AR3
	   MAR *-       ; AR3 = AR3 - 1
	   LT *, AR4     ; TREG = [AR3]. Select AR4
       MPYA *-, AR3  ; ACC = ACC + PREG. PREG = TREG*[AR4]. AR4 = AR4 - 1. Select AR3 
       DMOV *, AR7   ; [AR3+1] = [AR3]. Select AR7
       
       
       BANZ LOOP,*-  ; if AR7>0, goto LOOP. AR7 = AR7 - 1
	
	   MAR *, AR2 ; Select AR2
	
	   ;**********************************************************************
	
	ADRK	4-LF1
	.line	8
;>>>> 	   input=2;
	SBRK	7-LF1
	LT	*-, AR4  ; TREG = [AR2]. Select AR4
	MPYA *      ; ACC = ACC + PREG. PREG = [AR4]*TREG.
	MPYA *, AR2 ; ACC = ACC + PREG. New PREG is "don't care". Select AR2
	.line	10
;>>>> 	   *acl = 5;
	LAR	AR5,*-,AR5
	SACL	* ,AR2  ; [AR5] = Low Word(ACC). Select AR2
	.line	11
;>>>> 	   *ach = 7;
	LAR	AR5,* ,AR5
	SACH	* ,AR2  ; [AR5] = High Word(ACC). Select AR2
	.line	13
;>>>> 	   input = 1;
	ADRK	2   ; C-compiler adding 2 to AR2
	LACL *, AR3 ; ACC = [AR2]. Select AR3
	SACL *, AR1 ; [AR3] = ACC. Select AR1
	; accumulator stored. go about usual business
EPI0_1:
	.line	14
	SBRK	3
	LAR	AR0,*-
	PSHD	*
	RET

	.endfunc	16,000000000H,2
	.end
