;-------------------------------------------------------------------
;试卷题：设内存缓冲区BUF中存有100个字符，写一个子程序，统计BUF中大写字母、小写字符的个数，将结果分别存放在N_CHAR1、N_CHAR2单元。
;-------------------------------------------------------------------
P1 PROC FAR
    PUSH CX
    PUSH SI
    PUSH AX
    MOV CX,100  ;保存字符串长度
    LEA SI,BUF;
COUNTCHAR:
    MOV AL,[SI]
    CMP AL,'A'
    JB COUNTINUE
    CMP AL,'Z'
    JA N_CHAR
    INC BYTE PTR [N_CHAR1]
    JMP COUNTINUE
N_CHAR:
    CMP AL,'A'
    JB COUNTINUE
    CMP AL,'Z'
    JA COUNTINUE
    INC BYTE PTR [N_CHAR2]
COUNTINUE:
    INC SI
    LOOP COUNTCHAR
    POP AX
    POP SI
    POP CX
    RET
P1 ENDS
