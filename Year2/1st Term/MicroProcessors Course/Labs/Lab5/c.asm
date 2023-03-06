.model small 
.stack 64
.data 
.code
Main Proc FAR
    
   mov ax, 2545h
   mov bx, 6512h          
   mov al, ah
   mov cl, bl
       walid: 
       dec ah
       dec cl
       jnz walid
   mov al, ah
 hlt
    
    
    
    
    
    Main endp
end Main