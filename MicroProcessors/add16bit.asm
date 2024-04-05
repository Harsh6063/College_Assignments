.model small
.386
.data
    DATA1 dw 0000H
    msg db 10,13,"Enter the first no. (hex) :: $"
    msg1 db 10,13,"Enter the second no. (hex) :: $"
    msg2 db 10,13,"The Resultant sum is :: $"

.code
.startup
    MOV AH, 09
    MOV DX, OFFSET msg
    INT 21H

    MOV EBX, 0
    MOV CX, 4

AGAIN:
    MOV AH, 01 ; 1ST NO. ENTERED
    INT 21H

    CMP AL, 'A'
    JGE L5
    SUB AL, 30H
    JMP L6

L5:
    SUB AL, 37H
L6:
    SHL BX, 4
    ADD BL, AL
    DEC CX
    JNZ AGAIN

    MOV DATA1, BX

    MOV AH, 09
    MOV DX, OFFSET msg1
    INT 21H

    MOV BX, 0
    MOV CX, 4

AGAIN1:
    MOV AH, 01 ; 2nd NO. ENTERED
    INT 21H

    CMP AL, 'A'
    JGE L7
    SUB AL, 30H
    JMP L8

L7:
    SUB AL, 37H
L8:
    SHL BX, 4
    ADD BL, AL
    DEC CX
    JNZ AGAIN1

    ADD BX, DATA1 ; ADDITION

    MOV AH, 09
    MOV DX, OFFSET msg2
    INT 21H

    MOV CX, 4

AGAIN2:
    ROL BX, 4
    MOV DL, BL
    AND DL, 0FH
    CMP DL, 9
    JG L1 ; to o/p given no.
    ADD DL, 30H
    JMP PRINT
L1:
    ADD DL, 37H
PRINT:
    MOV AH, 02
    INT 21H
    DEC CX
    JNZ AGAIN2

    ; Optionally, add a loop to keep the program running
    MOV AH, 4CH
    XOR AL, AL
    INT 21H
END