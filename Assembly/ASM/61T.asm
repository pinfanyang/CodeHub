;输出16进制版本
;数据段声明
DATA segment
    RESULT DW ?
DATA ends
;栈段声明
STACK segment STACK 
    DB 10 DUP(0)
STACK ends
;代码段声明
CODE segment
    assume CS:CODE,DS:DATA,SS:STACK
    START: MOV DX,1
           MOV BL,2
    LP:    MOV AL,BL
           ADD BL,1
           MUL BL
           ADD DX,AX ;DX存放累加和
           CMP AX,200
           JG OUTPUT
           LOOP LP
    OUTPUT:MOV BX,DX
           MOV CX,4
    LP2:   ROL BX,1 ;BL存放累加和，通过移位从高到低一位一位显示
           ROL BX,1
           ROL BX,1
           ROL BX,1
           MOV AX,BX
           AND AX,000FH ;取BL的低四位
           XOR DX,DX
           ADD AL,30H ;16进制→ASCII码转换，加30H
           CMP AL,3AH ;0-9与A-F的ASCII码分开
           JB PIT
           ADD AL,07H ;若比A(10)大，再加07H
    PIT:   MOV DL,AL
           MOV AH,02H
           INT 21H
           LOOP LP2
           MOV AH,4CH
           INT 21H
CODE ends
    end START