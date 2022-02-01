;代码段声明
CODE segment
    assume CS:CODE
    START: PUSH DS         ;保存原来的PSP段地址
           MOV AX,0        ;0进AX
           PUSH AX         ;0压栈,后面可以配合着RET，结束程序返回DOS
           MOV BX,3000H     
           MOV CL,100
    LOP:   MOV BYTE PTR[BX],0   ;将0送到ES:BX的字节单元
           INC BX               ;BX+1
           LOOP LOP  
           MOV AH,4CH           ;程序结束，返回DOS
           INT 21H 
CODE ends
    end START