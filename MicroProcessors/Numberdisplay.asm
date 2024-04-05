.MODEL SMALL
.STACK 100H

.DATA
    msg DB 10, 13, 'Enter a single digit number: $' ; Prompt message
    output_msg DB 10, 13, 'You entered: $'          ; Message to display the entered number
    output DB ?        ; Variable to store the entered number as output

.CODE
    MOV AX, @DATA
    MOV DS, AX
    
    ; Display prompt message
    MOV AH, 09H
    LEA DX, msg
    INT 21H
    
    ; Read character input from user
    MOV AH, 01H
    INT 21H
    
    ; Convert ASCII to actual number
    SUB AL, 30h    ; Convert ASCII to numeric value
    
    ; Check if it's a valid single digit number (0-9)
    CMP AL, 0
    JL invalid_input  ; If less than 0, jump to invalid input
    CMP AL, 9
    JG invalid_input  ; If greater than 9, jump to invalid input
    
    ; Display output message
    MOV AH, 09H
    LEA DX, output_msg
    INT 21H
    
    ; Display the entered number
    ADD AL, 30h      ; Convert number to ASCII before printing
    MOV AH, 02H
    MOV DL, AL
    INT 21H
    
    ; Exit program
    MOV AH, 4CH
    INT 21H
    
invalid_input:
    ; Display error message for invalid input
    MOV AH, 09H
    MOV DX, OFFSET invalid_msg
    INT 21H
    
    ; Exit program
    MOV AH, 4CH
    INT 21H
    
.DATA
invalid_msg DB 10, 13, 'Invalid input! Please enter a single digit number.$'
END