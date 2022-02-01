;-------------------------------------------------------------------
;PPT2:利用学号查该学生的数学成绩，首先在数据段中建立一个成绩表TABLE,在表中按学号从小到大的顺序存放分数，要查的学号放在变量NUM中。
;注意：这里是没用把数据弄到DX里面的，所以不能使用9号功能输出（DS:DX），要输出要改成操作DX而不是AX
;-------------------------------------------------------------------
DATA SEGMENT
    TABLE DB 81,78,90,64,85,76,93,82,57,80
          DB 73,62,87,77,74,86,95,91,82,71
    NUM DB 8
    MATH DB ?
DATA ENDS
STACK1 SEGMENT PARA STACK
    DW 20H DUP(0)
STACK1 ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA,SS:STACK1
START:
    MOV AX,DATA
    MOV BX,OFFSET TABLE ;BX指向表首地址
    XOR AX,AX   ;异或，清空
    MOV AL,NUM
    DEC AL      ;减1
    ADD BX,AX   ;BX加上学号指向要查的成绩
    MOV AL,[BX] ;查到成绩
    MOV MATH,AL ;存结果
    MOV AH,4CH  ;返回DOS
    INT 21H
CODE ENDS
    END START