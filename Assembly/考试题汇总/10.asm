;-------------------------------------------------------------------
;试卷题：统计30个学生成绩，分类统计各个层次的学生个数。
;-------------------------------------------------------------------
DATA SEGMENT
    GRADE DW 54H,68H,...;30个学生的成绩
    LOWNUM DW ? ;低于60分人数
    MIDDLENUM DW ? ;60-89分之间的人数
    HIGHNUM DW ?   ;90分以上的人数
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    LEA DI,GRADE
    MOV CX,30
LOOP1:
    MOV AX,WORD PTR [DI]
    CMP AX,60
    JAE DOMIDDLE    ;≥跳转
    INC LOWNUM
DOMIDDLE:
    CMP AX,90
    JAE DOHIGH
    INC MIDDLENUM
    JMP COUNTINUE
DOHIGH:
    INC HIGHNUM
COUNTTINUE:
    ADD DI,2
    LOOP LOOP1
    MOV AH,4CH
    INT 21H
CODE ENDS
    END START


;-------------------------------------------------------------------
;试卷题：编程将数据区以BUFFER为首地址，连续100个字节的存储单元清零。
;-------------------------------------------------------------------
DATA SEGMENT
    BUFFER DB 100 DUP(?)
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    MOV AL,0
    MOV CX,100
    LEA BX,BUFFER
LOOP1:
    MOV [BX],AL
    INC BX
    LOOP LOOP1
    MOV AH,4CH
    INT 21H
CODE ENDS
    END START

;-------------------------------------------------------------------
;试卷题：编程从键盘接收一个一位数N,然后响铃N次，响铃的ASCII为07。
;-------------------------------------------------------------------
CODE SEGMENT
    ASSUME CS:CODE
START:
    MOV AH,1
    INT 21H
    AND AL,0FH
    CBW
    MOV CX,AX
    JCXZ EXIT
BELL:
    MOV DL,7
    MOV AH,2
    INT 21H
    LOOP BELL
EXIT:
    MOV AH,4CH
    INT 21H
CODE ENDS
    END START
    


;-------------------------------------------------------------------
;试卷题:采用子程序结构，完成10以内的奇数和，存放在SUM中。
;-------------------------------------------------------------------
DATA SEGMENT
    SUM DB ?
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    CALL SUB1
    MOV SUM,AL
    MOV AH,4CH
    INT 21H
SHB1 PROC NEAR
    XOR AX,AX
    MOV BL,1
AGAIN:
    ADD AL,BL
    ADD BL,2
    CMP BL,10
    JL AGAIN   
    RET
SUB ENDP
CODE ENDS
    END START