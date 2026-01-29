; ADD subroutine – pop two numbers from stack, 
; perform ‘+’ operation and then push result back to the stack

ADD_OP
; save registers




  
; initialize R5


; first pop


; check return value of first pop, go to EXIT if it failed (R5 = 1)



;save value in R1 before second pop


; second pop


; check result of second pop, go to RESTORE_1 if it failed



; add two numbers: R0 <- R0 + R1



; check range of sum, go to RESTORE_2 if it failed
  ; Do JSR
  ; Check R5
  ; Branch 



; everything is good, push sum (already in R0) to stack & exit
;


RESTORE_1     ; put back first number
    ; Load STACK_TOP
    ; Put back item 
    ; Update STACK_TOP
    ; Go to exit



RESTORE_2     ; put back both numbers
    ; Load STACK_TOP
    ; Put back item(s)
    ; Update STACK_TOP
;
EXIT

; restore registers

LD R7, ADD_SAVER7
LD R0, ADD_SAVER0
LD R6, ADD_SAVER6
LD R1, ADD_SAVER1

RET
