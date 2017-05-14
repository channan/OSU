TITLE Program3      (Program3.asm)

; Author: Cody Hannan
; Date: 5/6/17
; Email: hannanc@oregonstate.edu
; Course: CS271-400
; Assignment: 3
; Due date: 5/6/17
; Description: Asks user for name and greets them. Asks user to enter numbers then enter a non integer to end the loop. 
; Calculates sum and rounded average.

INCLUDE Irvine32.inc

MAX=-1
MIN=-100

.data
remainder		SDWORD	?
count			SDWORD	?
sum				SDWORD	?
roundedAvg		SDWORD	?
average			REAL4	?
inStringName	BYTE	50 DUP (?)
dotString		BYTE	". ",0
extraCredit		BYTE	"**EC: Lines are numbered during user input",0
introTitle		BYTE	"Integer Accumulator",0
introName		BYTE	"by Cody Hannan",0
askName			BYTE	"What's your name? ",0
greeting		BYTE	"Hello, ",0
instruct1		BYTE	"Please enter numbers between [-100, -1].",0
instruct2		BYTE	"Enter a non-negative number when you are finished to see results.",0
prompt			BYTE	"Enter number: ",0
validate		BYTE	"Out of range. Enter a number in [-100 .. -1].",0
bye1			BYTE	"Thank you for playing Integer Accumulator!",0
bye2			BYTE	"It's been a pleasure to meet you, ",0
countString		BYTE	"The number of valid entries was ",0
sumString		BYTE	"The sum of your valid numbers is ",0
avgString		BYTE	"The rounded average is ",0
zeroEntered		BYTE	"No valid numbers were entered",0

.code
main PROC

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


;asks user for their name displays a greeting using the name
	mov		edx, OFFSET askName
	call	WriteString
	mov		edx, OFFSET inStringName
	mov		ecx, 50            
	call	ReadString
	call	Crlf
	mov		edx, OFFSET greeting
	call	WriteString
	mov		edx, OFFSET inStringName
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

	mov		sum,0
	mov		count,0

;starts up integer entering loop
	integerLoop:
	
;validates entered value to check if its in range	
	validate1:
	
;numbers the entries	
	mov		eax,count
	add		eax,1
	call	WriteDec
	mov		edx, OFFSET dotString
	call	WriteString
	
;prompts user for number	
	mov		edx, OFFSET prompt
	call	WriteString
	call	ReadInt
	cmp		eax,MIN
	jl		validate2	;if less than -100 user is notified of error
	cmp		eax,0
	jns		endIntegerLoop	;if entered value is not signed then the loop ends
	jmp		passed		
	
;displays error message to user
	validate2:
	mov		edx, OFFSET validate
	call	WriteString
	call	Crlf
	call	Crlf
	jmp		validate1

;once input is valid the code continues from here	
	passed:	
	call	Crlf	
	add		sum,eax		;adds value to sum
	add		count,1		;increases count
	jmp		integerLoop	;jump to start of loop

	endIntegerLoop:
	
;checks if no valid numbers were entered
	mov		eax,count
	cmp		eax,0
	jne		continue1
	mov		edx,OFFSET zeroEntered
	call	WriteString
	call	Crlf
	call	Crlf
	jmp		goodbye

;calculates average and remainder	
	continue1:
	call	Crlf
	mov		eax,sum
	cdq
	idiv	count
	mov		roundedAvg,eax
	mov		remainder,edx

;sets up comparison for rounding	
	mov		eax,count
	mov		ebx,2
	cdq
	idiv	ebx
	mov		ebx,-1
	imul	ebx

;determines if average needs to be rounded up	
	cmp		eax,remainder
	jle		continue2			
	sub		roundedAvg,1

	continue2:

;displays number of values entered
	mov		edx,OFFSET countString
	call	WriteString
	mov		eax,count
	call	WriteDec
	call	Crlf
		
;displays sum of values entered
	mov		edx,OFFSET sumString
	call	WriteString	
	mov		eax,sum
	call	WriteInt
	call	Crlf

;displays rounded average of values entered
	mov		edx,OFFSET avgString
	call	WriteString
	mov		eax,roundedAvg
	call	WriteInt
	call	Crlf
	call	Crlf

;goodbye message to user
	goodbye:
	mov		edx,OFFSET bye1
	call	WriteString
	call	Crlf
	mov		edx,OFFSET bye2
	call	WriteString
	mov		edx,OFFSET inStringName
	call	WriteString
	call	Crlf
	call	Crlf

	exit	; exit to operating system

main ENDP

END main
