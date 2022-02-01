;-------------------------------------------------------------------
;PPT1：编写程序计算：Z=(3X+Y-5)/2
;-------------------------------------------------------------------
DATA SEGMENT
    VARX DW 15
    VARY DW 19
    VARZ DW ?
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
COMP PROC FAR
START:
    PUSH DS     ;保护返回DOS地址
    MOV AX,0
    PUSH AX
    MOV AX,DATA
    MOV DS,AX   ;初始化DS
    MOV AX,VARX ;AX←X
    SHL AX,1    ;AX←2X,左移一位
    ADD AX,VARX ;AX←3X
    ADD AX,VARY ;AX←3X+Y
    SUB AX,5    ;AX←3X+Y-5
    SAR AX,1    ;AX←（3X+Y-5）/2
    MOV VARZ,AX ;存放结果
    RET         ;返回DOS
COMP ENDP
CODE ENDS
    END START
    