.model small 
.stack 64
.data 
.code
Main Proc FAR
    
   mov ax, 10
   mov cx, ax
   mov bx, 0
   mloop:
       add bx, ax
       dec ax
   loop mloop
    
    
    
    
    
    Main endp
end Main