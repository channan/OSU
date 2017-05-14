TITLE Program4      (Program4.asm)

; Author: Cody Hannan
; Date: 5/12/17
; Email: hannanc@oregonstate.edu
; Course: CS271-400
; Assignment: 4
; Due date: 5/14/17
; Description: Greet the user and asks for how many composites are to be displayed. The composites are then displayed
; to the user ten per line.

INCLUDE Irvine32.inc

MAX=400
MIN=1

.data
num				DWORD	?
divisors		DWORD	?
count			DWORD	?
spaceString		BYTE	"   ",0
extraCredit		BYTE	"**EC: Output columns are aligned.",0
introTitle		BYTE	"Composite Numbers",0
introName		BYTE	"by Cody Hannan",0
instruct1		BYTE	"Enter the number of composite numbers you would like to see.",0
instruct2		BYTE	"I'll accept orders for up to 400 composites.",0
prompt			BYTE	"Enter the number of composites to display [1 .. 400]: ",0
errorMessage	BYTE	"Out of range. Try again.",0
bye1			BYTE	"Thank you for playing Composite Numbers!",0
bye2			BYTE	"Results certified by Cody Hannan. Goodbye.",0

.code
intro PROC
;author introduction to user
	mov		edx,OFFSET introTitle		
	call	WriteString
	call	Crlf
	mov		edx,OFFSET introName
	call	WriteString
	call	Crlf
	mov		edx,OFFSET extraCredit
	call	WriteString
	call	Crlf
	call	Crlf

;displays instructions to user
	mov		edx, OFFSET instruct1
	call	WriteString
	call	Crlf
	mov		edx, OFFSET	instruct2
	call	WriteString
	call	Crlf
	call	Crlf

	ret
intro ENDP



validate PROC
	mov		ebx,0
	cmp		eax,MIN
	jl		error	;if less than 1 user is notified of error
	cmp		eax,MAX
	jg		error	;if more than 400 user is notified of error
	jmp		passed	
	
;displays error message to user
	error:
	mov		edx, OFFSET errorMessage
	call	WriteString
	call	Crlf
	call	Crlf
	mov		ebx,1

	passed:
	ret
validate ENDP



getUserData PROC
;prompts user for number and validates the input	
	validateLoop:
	mov		edx, OFFSET prompt
	call	WriteString
	call	ReadInt
	call	validate
	cmp		ebx,1
	je		validateLoop

	ret
getUserData ENDP



;checks if number is composite
getComposites PROC
	num2Loop:
	mov		eax,num
	mov		divisors,2
	mov		ebx,divisors

	factorLoop:
	mov		edx,0
	div		ebx 
	mov		eax,num
	inc		ebx
	cmp		ebx,num
	jne		continue ;if ebx is equal to the current number being checked then we move on to the next number, otherwise...
	inc		num
	jmp		num2Loop

	continue:
	cmp		edx,0 ;the remainder is checked, if it equals 0 then we found a composite number otherwise we check another factor
	jne		factorLoop

	ret
getComposites ENDP



;displays the composite numbers
showComposites PROC
;initializes loops, counters, and first number to be checked
	mov		count,0
	mov		ecx,eax
	mov		num,4

	num1Loop:
	call	getComposites ;checks if number is composite
	call	WriteDec
	mov		al,9 ;ascii character for tab, used to display numbers in aligned columns
	call	WriteChar
	
;checks how many numbers have been displayed, after ten we move down a line
	inc		count
	mov		eax,count
	mov		ebx,10
	mov		edx,0
	div		ebx
	cmp		edx,0
	jne		continue
	call	Crlf
	
;after displaying the composite we move to the next number restart the composite check
	continue:
	inc		num
	loop	num1Loop

	ret
showComposites ENDP



;goodbye message to user
goodbye PROC
	mov		edx,OFFSET bye1
	call	WriteString
	call	Crlf
	mov		edx,OFFSET bye2
	call	WriteString
	call	Crlf
	call	Crlf

	ret
goodbye ENDP



;main procedure, calls other procedures to run program
main PROC
	call	intro
	call	getUserData
	call	showComposites
	call	Crlf
	call	goodbye

	exit	
main ENDP

END main
