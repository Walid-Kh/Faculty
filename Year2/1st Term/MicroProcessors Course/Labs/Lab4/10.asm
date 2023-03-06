.model small 
.stack 64
.data
arr db 81, 65, 77, 82, 73, 55, 88, 86, 76  
len equ $ - arr
outputarr db len dup(00)
max db 000h
.code
Main Proc FAR
    
    mov ax, @DATA
    mov DS, ax
    mov cx, len
    mov di, 0
    getLargest: 
        mov al, [arr][di]
        cmp al, [max]
        jg larger
        jmp smaller
        larger: 
        mov [max], al
        smaller:  
        inc di
    loop getLargest
    mov cx, len
    mov al, 99
    sub al, [max]
    mov di, 0
    changegrades: 
    mov ah, [arr][di]
    add ah, al
    mov [outputarr][di], ah
    inc di
    
    
    
    
    
    loop changegrades
    

    
    
    mov di, offset outputarr
    mov cx, len
    printloop:
    mov dl, [di]
    inc di
    mov ah, 02h
    int 21h
    loop printloop
    
    
    hlt
   
    
    
    
    
    
    Main endp
end Main