code segment
     assume cs:code
start:
mov ax,3000H
mov bx,5000H
mov sp,2000H
mov ss,ax
push ax
push bx
pop ax
pop bx
mov ax,4c00h;返回dos窗口
int 21h
code ends 
end start