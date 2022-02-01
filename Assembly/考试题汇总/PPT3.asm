;-------------------------------------------------------------------
;PPT3:求三个带符号字数据中的最大值，并将最大值存入MAX字单元中。设三个带符号数分别在三个字变量X,Y,Z中存储。
;-------------------------------------------------------------------
DATA SEGMENT
    X DW -0ABH
    Y DW 205
    Z DW 200
    MAX DW ?
DATA ENDS
CODE SEGMENT
    ASSUME DS:DATA,CS:CODE
START:
    MOV AX,DATA
    MOV DS,AX
    MOV AX,X
    CMP AX,Y
    JGE LP1  ;≥跳转
    MOV AX,Y
LP1:
    CMP AX,Z
    JGE EXIT ;≥跳转
    MOV AX,Z
EXIT:
    MOV MAX,AX
    MOV AH,4CH
    INT 21H
CODE ENDS
    END START