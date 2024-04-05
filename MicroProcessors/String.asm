.model small
.stack 100H
.data
    msg1 db 10,13,"Hello, $"
    msg2 db "World!$"

.code
.startup

    ; Print "Hello,"
    MOV AH, 09
    MOV DX, OFFSET msg1
    INT 21H

    ; Print newline
    MOV AH, 09
    MOV DX, OFFSET msg2
    INT 21H

    ; Exit the program
    MOV AH, 4CH
    INT 21H

end
