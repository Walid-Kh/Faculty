.model small 
.stack 64
.data 
.code
Main Proc FAR
    
    mov cx, 7
    mov bl, 0
    mov bh, 1
    mov ax, 1
    myloop:
        mov dh, bh 
        add bh, bl
        mov bl, dh
        add al, bh
    loop myloop
    
 hlt
    
    
    
    
    
    Main endp
end Main