.model small 
.stack 64
.data
inputstring DB 'ThIS iS A TEst CaSe','$'
len  equ  $ - inputstring - 1
outputstring DB 20 DUP('$')
.code
Main Proc FAR
    
    mov ax, @DATA
    mov DS, ax
    ; cl is the counter for the loop 
    mov cx, len
    ; dec bec of 
    mov di, offset inputstring
    mov bx, offset outputstring  
    
    fibloop: 
        mov dl, [di]
        cmp dl, 'a'
        jl tolower
        jmp lower
        tolower: 
        cmp dl, ' '
        je lower  
        cmp dl, '$' 
        je lower
        add dl, 32
       
        lower:
        mov [outputstring][di], dl
        inc di 
        
    
    loop fibloop

    
    
    mov dx, offset outputstring
    mov ah, 9
    int 21h
    hlt
   
    
    
    
    
    
    Main endp
end Main
