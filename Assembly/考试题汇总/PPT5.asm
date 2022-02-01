;-------------------------------------------------------------------
;PPT5&试卷题：变成将存放在HEXN中的一位十六进制数转换成ASCII码，并存入ASCN中。
;-------------------------------------------------------------------
DATA SEGMENT
    HEXN DB ?
    ASCN DB ?
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    MOV AL,HEXN
    CMP AL,9
    JBE LP1 ;≤跳转
    ADD AL,7
LP1:
    ADD AL,30H
    MOV ASCN,AL
    MOV AH,4CH
    INT 21H
CODE ENDS
    END START