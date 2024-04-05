.MODEL SMALL
.STACK 100H

.DATA
    msg DB 'Hello, World!$'  ; String to be printed
    newline DB 0DH, 0AH, '$' ; Newline characters

.CODE
    MOV AX, @DATA
    MOV DS, AX
    
    MOV SI, 0               ; Initialize string index to 0

print_loop:
    MOV AH, 02H             ; Function to print character
    MOV DL, [msg + SI]      ; Load character to be printed
    INT 21H                 ; Print character
    
    MOV AH, 09H             ; Function to print newline characters
    LEA DX, newline         ; Load address of newline characters
    INT 21H                 ; Print newline
    
    INC SI                  ; Move to next character in string
    CMP BYTE PTR [msg + SI], '$' ; Check for end of string
    JNE print_loop          ; If not end of string, continue printing
    
    MOV AH, 4CH             ; Exit program
    INT 21H
          
END