;-------------------------------------------------------------------
;PPT6:从键盘输入一组字符，直到“0”为止。编写一程序，完成当输入字符是小写字母时，修改为大写字母，输入字符存放在string为首地址的存储单元中。
;该程序用了子程序
;-------------------------------------------------------------------
DATA SEGMENT
    STRING DB 100 DUP(?)
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    MOV DI,OFFSET STRING
AGAIN:
    MOV AH,1    ;调用1号功能，键盘输入字符
    INT 21H
    CMP AL,'0'
    JE EXIT ;=跳转
    CALL STOB
    MOV [DI],AL
    INC DI
    JMP AGAIN
EXIT:  
    MOV AH,4CH
    INT 21H
STOB PROC NEAR
    CMP AL,61H
    JB NEXT ;＜跳转
    CMP AL,7AH
    JA NEXT ;＞跳转
    SUB AL,20H 
NEXT:
    RET
STOB ENDP
CODE ENDS
    END START

    