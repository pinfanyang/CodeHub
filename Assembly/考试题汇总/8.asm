;-------------------------------------------------------------------
;试卷题：编程计算：当x≥0是，y=x，当x＜0时，y=|x|。
;-------------------------------------------------------------------
DATA SEGMENT
    X DB ?
    Y DB ?
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    MOV AL,X
    CMP AL,0
    JGE BIGR
    NEG AL
BIGR:
    MOV Y,AL
    MOV AH,4CH
    INT 21H
CODE ENDS
    END START
