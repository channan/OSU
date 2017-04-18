TITLE Program1     (Program1.asm)

; Author: Cody Hannan
; Date: 4/16/17
; Email: hannanc@oregonstate.edu
; Course: CS271-400
; Assignment: 1
; Due date: 4/16/17
; Description: Asks user for two values and calculates the sum, difference, product, and quotient, as well as displays the remainder

INCLUDE Irvine32.inc

.data

val1		DWORD	?
val2		DWORD	?
sum			DWORD	?
subtract	DWORD	?
multi		DWORD	?
division	DWORD	?
remain		DWORD	?
intro		BYTE	"Elementary Arithmetic	by Cody Hannan",0
extraC1		BYTE	"**EC1: Repeats program until user chooses to quit",0
extraC2		BYTE	"**EC2: Validates the second number to be less than the first",0
instruct1	BYTE	"Enter 2 numbers and I'll show you the sum, difference,",0
instruct2	BYTE	"product, quotient, and remainder.",0
prompt1		BYTE	"First number: ",0
prompt2		BYTE	"Second number: ",0
out1		BYTE	" = ",0
out2		BYTE	" + ",0
out3		BYTE	" - ",0
out4		BYTE	" * ",0
out5		BYTE	" / ",0
out6		BYTE	" remainder ",0
bye			BYTE	"That's it! Goodbye!",0
lessThan	BYTE	"The second number must be less than the first!",0
promptLoop	BYTE	"Would you like to input new values? Enter 1 for yes or 0 for no: ",0

.code
main PROC

;author introduction to user
	mov		edx,OFFSET intro		
	call	WriteString
	call	Crlf
	mov		edx,OFFSET extraC1		
	call	WriteString
	call	Crlf
	mov		edx,OFFSET extraC2		
	call	WriteString
	call	Crlf
	call	Crlf

;so that loop conditions are met
	mov		eax,1 

loopProg:
;loop continues if user enters 1
	cmp		eax, 0
	je		endLoop

;asks user for two values in order to show sum, difference, quotient,and remainder
	mov		edx,OFFSET instruct1		
	call	WriteString
	call	Crlf
	mov		edx,OFFSET instruct2		
	call	WriteString
	call	Crlf
	call	Crlf

;prompts user for first value
	mov		edx,OFFSET prompt1
	call	WriteString
	call	ReadInt
	mov		val1,eax

;prompts user for second value
	mov		edx,OFFSET prompt2
	call	WriteString
	call	ReadInt
	mov		val2,eax

;checks if val1 is less than val2, if so program jumps to fBlock
	mov		eax,val1
	cmp		eax,val2
	jl		fBlock
	
;sums the two values and moves value to sum label
	mov		eax,val1
	add		eax,val2
	mov		sum,eax

;subtracts the two values and moves value to subtract label
	mov		eax,val1
	sub		eax,val2
	mov		subtract,eax

;multiplies the two values and moves value to multi label
	mov		eax,val1
	mul		val2
	mov		multi,eax

;divides the two values and moves the value to division label and the remainder from edx to the remain label
	mov		eax,val1
	xor		edx,edx
	div		val2
	mov		division,eax
	mov		remain,edx

;shows user val1 + val2 = result
	call	Crlf
	mov		eax,val1
	call	WriteDec		
	mov		edx,OFFSET out2
	call	WriteString	
	mov		eax,val2
	call	WriteDec	
	mov		edx,OFFSET out1
	call	WriteString
	mov		eax,sum
	call	WriteDec
	call	Crlf	

;shows user val1 - val2 = result
	mov		eax,val1
	call	WriteDec		
	mov		edx,OFFSET out3
	call	WriteString	
	mov		eax,val2
	call	WriteDec	
	mov		edx,OFFSET out1
	call	WriteString
	mov		eax,subtract
	call	WriteDec
	call	Crlf
	
;shows user val1 * val2 = result
	mov		eax,val1
	call	WriteDec		
	mov		edx,OFFSET out4
	call	WriteString	
	mov		eax,val2
	call	WriteDec	
	mov		edx,OFFSET out1
	call	WriteString
	mov		eax,multi
	call	WriteDec
	call	Crlf	
	
;shows user val1 / val2 = result remainder result
	mov		eax,val1
	call	WriteDec		
	mov		edx,OFFSET out5
	call	WriteString	
	mov		eax,val2
	call	WriteDec	
	mov		edx,OFFSET out1
	call	WriteString
	mov		eax,division
	call	WriteDec	
	mov		edx,OFFSET out6
	call	WriteString
	mov		eax,remain
	call	WriteDec
	call	Crlf
	call	Crlf

;asks user if they'd like to repeat the program
	mov		edx,OFFSET promptLoop
	call	WriteString
	call	ReadInt
	call	Crlf
	jmp		loopProg

fBlock:
;informs user that the second number must be smaller than the first
	call	Crlf
	mov		edx,OFFSET lessThan
	call	WriteString
	call	Crlf
	call	Crlf	

;asks user if they would like to repeat the program
	mov		edx,OFFSET promptLoop
	call	WriteString
	call	ReadInt
	call	Crlf
	jmp		loopProg
	
endLoop:
;displays outro to user
	mov		edx,OFFSET bye
	call	WriteString
	call	Crlf	
	
;exit to operating system
	exit	

main ENDP

END main
