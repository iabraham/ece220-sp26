.ORIG x3000

;RTS Example: answer = Running(number)
;
;Originally by ywchen; modified by itabrah2 to do tear down 
;and build up as per provided README
;
;main code
;Main's activation record starting at x4000
;Assume it only has local variables
;answer (x3FFF) <-R6
;n (x4000) <-R5

MAIN
        LD R5, RSTACK   ;set R5 to point to addr x4000
        LD R6, RSTACK   ;set R6 to point to addr x4000
        LD R0, NUMBER   ;set R0 to x0005 
        STR R0, R6, #0  ;push number to stack (at addr x4000)
        ADD R6, R6, #-1 ;push answer to stack (at addr x3FFF)

; Step 1 in README
; Caller stack Build-up - push RUNNING's arg to the stack
        LDR R0, R5, #0
        ADD R6, R6, #-1
        STR R0, R6, #0

; Step 2 in README
; Pass control to callee - invoke RUNNING subroutine
        JSR RUNNING

; Step 13 & 14 in README
; Caller stack Tear-down for RUNNING
        LDR R0, R6, #0  ;copy return value to R0
        ADD R6, R6, #2  ;pop return value + argument from stack

; Step 15 in README 
        STR R0, R5, #-1 ;save return value to answer

ATHALT  HALT
NUMBER  .FILL   x0005
RSTACK  .FILL   x4000


;;RUNNING Subroutine
RUNNING
;callee set-up of Running Sum’s activation record

;Step 3 in README
ADD R6, R6, #-3 		; Make space for bookkeeping

;Step 4 in README
STR R7, R6, #1          ; Save RA

;Step 5 in README
STR R5, R6, #0          ; Save CFP 

;Step 6 in README
ADD R5, R6, #-1          ; Set new frame pointer 

;Step 7 in README
ADD R6, R6, #-1 

;Step 8 in README (start)
;function logic
;base case (n==1)
LDR R1, R5, #4
ADD R2, R1, #-1
BRz BASE_CASE

;recursive case
;caller setup for Running(n-1)
;push argument n-1 onto RST
ADD R6, R6, #-1
STR R2, R6, #0
;call Running(n-1)
JSR RUNNING

;caller tear-down for Running(n-1)
;pop Running(n-1)’s return value to R0
LDR R0, R6, #0

;pop return value & Running(n-1)’s argument
ADD R6, R6, #2

;calculate n + Running(n-1)
LDR R1, R5, #4
ADD R0, R1, R0
;store result in fn
STR R0, R5, #0

;ready to return
BRnzp RETURN

BASE_CASE
;set fn = 1
AND R2, R2, #0
ADD R2, R2, #1
STR R2, R5, #0

RETURN
;set return value
LDR R0, R5, #0

; Step 8 in README (end)
STR R0, R5, #3

;callee tear-down of Factorial(n)’s activation record
;pop local variables

;Step 9 in README 
ADD R6, R5, #3   ; Pop locals & set R6 to RV 

;Step 10 in README
LDR R5, R6, #-2  ; Restore CFP 

;Step 11 in README 
LDR R7, R6, #-1  ; Restore return address

;Step 12 in README
RET              ;return to caller

.END
