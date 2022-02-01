;数据段声明
data segment
num1 db 41h ;字符A
num2 db ?
data ends   
;代码段
Code segment
assume cs:code, ds:data
start:
mov ax, data
mov ds, ax
mov ah, num1
cmp ah, 39h
Jbe next
sub ah, 7
next: sub ah, 30h
mov num2, ah
mov ah, 4ch
int 21h
code ends
end start









