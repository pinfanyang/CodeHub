;-------------------------------------------------------------------
;试卷题：编写一完整程序，将存放在首地址为STR1的50个字符串加密后放入STR2开始的存储单元中，加密规则：取反+20H。
;-------------------------------------------------------------------
DATA SEGMENT
    STR1 DB 'WO YAO KAO MAN FENG!...'
    STR2 DB 50 DUP(?)
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    LEA SI,STR1
    LEA DI,STR2
    MOV CX,50
AGAIN:
    MOV AL,[50]
    NOT AL
    ADD AL,20H
    MOV [DI],AL
    INC SI
    INC DI
    LOOP AGAIN
    MOV AH,4CH
    INT 21H
CODE ENDS
    END START