TITLE Program2     (Program2.asm)

; Author: Cody Hannan
; Date: 4/22/17
; Email: hannanc@oregonstate.edu
; Course: CS271-400
; Assignment: 2
; Due date: 4/23/17
; Description: Asks user for name and greets them. Asks for number of fibonacci terms and it displays them to the user.

INCLUDE Irvine32.inc

.data

val1			DWORD	?
val2			DWORD	?
result			DWORD	?
startCount		DWORD	?
inStringName	BYTE	50 DUP (?)
space			BYTE	9,0
extraCredit		BYTE	"**EC: Numbers are displayed in aligned columns",0
introTitle		BYTE	"Fibonacci Numbers",0
introName		BYTE	"by Cody Hannan",0
askName			BYTE	"What's your name? ",0
greeting		BYTE	"Hello, ",0
instruct1		BYTE	"Enter the number of fibonacci terms to be displayed",0
instruct2		BYTE	"Give the number as an integer in the range [1 .. 46]",0
prompt			BYTE	"How many fibonacci terms do you want? ",0
validate		BYTE	"Out of range. Enter a number in [1 .. 46].",0
bye1			BYTE	"Results certified by Cody Hannan",0
bye2			BYTE	"Goodbye, ",0
lessThan		BYTE	"The second number must be less than the first!",0
promptLoop		BYTE	"Would you like to input new values? Enter 1 for yes or 0 for no: ",0

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

;asks user for how many terms
;checks value to make sure it's in the required range
	validate1:
	mov		edx, OFFSET prompt
	call	WriteString
	call	ReadInt
	cmp		eax,46
	jg		validate2	;if greater than 46 user is notified of error
	cmp		eax,1
	jl		validate2	;if less than 1 user is notified of error
	jmp		passed		
	
;displays error message to user
	validate2:
	mov		edx, OFFSET validate
	call	WriteString
	call	Crlf
	jmp		validate1

;once input is valid the code continues from here	
	passed:	
	call	Crlf	
	sub		eax,1	;substracts 1 from counter since first number is outside of loop
	mov		ecx,eax	;moves entered value to ecx as a counter for the loop
	mov		startCount,eax	;records starting count for later

;first two values are set to initialize fibonacci loop and second value is displayed
	mov		val1,0
	mov		val2,1
	mov		edx, OFFSET space
	mov		eax,val2
	call	WriteDec 
	call	WriteString
	call	WriteString

;if user enters 1 for number of fibonacci numbers then the loop is skipped
	cmp		ecx,0
	je		endLoop

;loop that calculates fibonacci numbers and displays them to the user
	fibonacciLoop:
	mov		eax,val1
	add		eax,val2
	mov		result,eax
	call	WriteDec
	mov		edx, OFFSET space
	call	WriteString
	
;checks for how many terms have been displayed so that columns can stay aligned at higher levels	
	mov		eax,startCount
	sub		eax,ecx
	cmp		eax,33
	jg		continue	
	call	WriteString	;this space is skipped to keep columns aligned at higher levels
	
;if space is skipped the code continues from here
	continue:
	mov		eax,val2
	mov		val1,eax
	mov		eax,result
	mov		val2,eax
	loop	fibonacciLoop	;jumps to beginning of loop and decrements counter value in ecx

	endLoop:
	call	Crlf
	call	Crlf

;displays outro message to user using the name entered earlier
	mov		edx, OFFSET bye1
	call	WriteString
	call	Crlf
	mov		edx, OFFSET bye2
	call	WriteString
	mov		edx, OFFSET inStringName
	call	WriteString
	call	Crlf
	call	Crlf

;exit to operating system
	exit	

main ENDP

END main
