.model small
.stack 100h
.data
pattern db '@', 13, 10, '@ @', 13, 10, '@ @ @', 13, 10, '$' ; Pattern to be printed, with carriage return and line feed characters and '$' to mark the end of the string

.code
.startup
mov ax, @data     ; Load data segment address
mov ds, ax

mov ah, 09        ; Function to print string
mov dx, offset pattern ; Load offset of pattern string
int 21h           ; DOS interrupt to print string

mov ah, 4Ch       ; DOS function to terminate program
int 21h           ; DOS interrupt to terminate

.code           ; Mark the end of the code segment
end             ; End of the program