;-------------------------------------------------------------------
;PPT4:已知有几个元素存放在以BUF为首地址的字节存储区中，试统计其中正数的个数，并存放在随后的NUM字节单元中。
;此处用了字程序设计
;-------------------------------------------------------------------
DATA SEGMENT
    BUF DB 23,56,-6,89,52,-89,-63,5,-12,52,0,89,-8
    NUM DB 0
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
MAIN PROC FAR
START:
    MOV AX,DATA
    MOV DS,AX
    MOV CX,NUM-BUF  ;计算重复的次数
    MOV AX,0
    LEA BX,BUF  ;把BUF的地址给BX存放
AGAIN:
    CMP BYTE PTR [BX],0
    JLE LAB1    ;≤跳转
    INC AX
LAB1:
    INC BX
    LOOP AGAIN
    MOV NUM,AL
    RET
MAIN ENDP
CODE ENDS
    END START