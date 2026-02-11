; ---------------------------------------------------------------------------
; C-LC3 Compiler, by HKN for UIUC Students                                   
; To simulate output, use https://wchargin.com/lc3web/                       
; ---------------------------------------------------------------------------
.ORIG x3000
    LD  R6, USER_STACK
    ADD R5, R6, #-1
    JSR main

swap
; callee setup:

    ADD R6, R6, #-3        ; allocate spot RV, RA, CFP
    STR R7, R6, #1         ; push R7 (return address)
    STR R5, R6, #0         ; push R5 (caller frame pointer)
    ADD R5, R6, #-1        ; set frame pointer

; function body:
    ADD R6, R6, #-1        ; allocate space for 'temp'

    LDR R0, R5, #4         ; load parameter 'first'
    LDR R0, R0, #0         ; get content of 'first'
    STR R0, R5, #0         ; assign to variable temp

    LDR R0, R5, #5         ; load parameter 'second'
    LDR R0, R0, #0         ; get content of 'second'
    LDR R1, R5, #4         ; load parameter 'first'
    STR R0, R1, #0         ; perform assignment

    LDR R0, R5, #0         ; load local variable 'temp'
    LDR R1, R5, #5         ; load parameter 'second'
    STR R0, R1, #0         ; perform assignment

swap_teardown
    ADD R6, R5, #1         ; pop local variables
    LDR R5, R6, #0         ; pop frame pointer
    ADD R6, R6, #1
    LDR R7, R6, #0         ; pop return address
    ADD R6, R6, #1
    RET
; end function.

main
    ADD R6, R6, #-2        ; allocate space for 'valueA', 'valueB'

    AND R0, R0, #0
    ADD R0, R0, #3
    STR R0, R5, #0         ; assign 3 to variable valueA

    AND R0, R0, #0
    ADD R0, R0, #4
    STR R0, R5, #-1        ; assign 4 to variable valueB

    ADD R0, R5, #-1        ; calculate address of 'valueB'
    ADD R6, R6, #-1
    STR R0, R6, #0         ; push argument to stack.

    ADD R0, R5, #0         ; calculate address of 'valueA'
    ADD R6, R6, #-1
    STR R0, R6, #0         ; push argument to stack.

    JSR swap               ; call function.

    LDR R0, R6, #0         ; load return value.
    ADD R6, R6, #1
    ADD R6, R6, #2         ; pop arguments

    AND R0, R0, #0
    STI R0, RETURN_SLOT    ; write return value from main
    HALT

; ------ Data Section ------ 
USER_STACK        .FILL xFDFF
RETURN_SLOT       .FILL xFDFF
.END
