;数据段声明
DATA segment
    DATA_NUMBERS DB 05H,0FCH,00H,03H,64H,0CDH    ;定义数据格式为补码存储
    Y1 DB 'Y=1',0DH,0AH,'$'                   ;0DH 换行，0AH 回车
    Y2 DB 'Y=0',0DH,0AH,'$'
    Y3 DB 'Y=-1',0DH,0AH,'$'
DATA ends
;堆栈段声明
STACK segment STACK
    DB 10 DUP(0)
STACK ends
;代码段声明
CODE segment
    assume DS:DATA,SS:STACK,CS:CODE
    START: MOV AX,DATA
           MOV DS,AX               ;把数据段送入数据寄存器中
           LEA SI,DATA_NUMBERS     ;将数字的偏移地址送到源变址寄存器中
           MOV AX,0                
           MOV CX,6                ;记录数字个数
    LOOP1: MOV AL,[SI]             ;循环结构，依次取数字与0做比较，
           CMP AL,0
           JG BIGER                ;大于跳转
           JE EQUAL                ;相等跳转
           MOV DX,OFFSET Y3        ;小于
           MOV AH,09H              ;9号功能，输出字符串Y=-1
           INT 21H                 
           JMP OUTPUT              ;无条件跳转到OUTPUT段
    BIGER: MOV DX,OFFSET Y1               
           MOV AH,09H              ;9号功能，输出字符串Y=1
           INT 21H
           JMP OUTPUT
    EQUAL: MOV DX,OFFSET Y2
           MOV AH,09H              ;9号功能，输出字符串Y=0
           INT 21H
    OUTPUT:INC SI                  ;SI加1，下一个数字进行比较
           LOOP LOOP1              
           MOV AH,4CH              ;结束程序
           INT 21H                 ;DOS系统功能调用
CODE ends
    end START