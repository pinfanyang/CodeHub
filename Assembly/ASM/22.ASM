code segment
     assume cs:code
start:
mov bx,0300H
mov si,0002H
mov  AX,BX
mov  AX,0304H
mov  AX,[0304H]
mov  AX,[BX]
mov  AX,0001[BX]
mov  AX,[BX][SI]
mov  AX,0001[BX][SI]
HLT
code ends 
end start
