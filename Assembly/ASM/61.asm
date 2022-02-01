;数据段声明
DATA segment
       STR DB 5 DUP(0)
           DB '$'
DATA ends

;代码段声明
CODE segment
       assume CS:CODE,DS:DATA
       START: MOV AX,DATA
              MOV DS,AX     ;数据送DS
              MOV DX,1      ;数据寄存器=1
              MOV BL,2      ;基址寄存器低八位=2
       ;循环部分，计算累计和
       LOP:   MOV AL,BL     
              INC BL        ;BL+1
              MUL BL        ;AX=AL*BL
              ADD DX,AX     ;DX做累加结果存放
              CMP AX,200    ;当前n*(n+1)结果与200做比较
              JBE LOP       ;小于跳转LOP，接着计算
              MOV AX,DX     ;最终结果给AX
              LEA DI,STR+4  ;将偏移地址给DI
       ;循环部分，利用除10取余，把最终结果转化为10进制数
       LOP2:  MOV CL,10     
              DIV CL        ;AX/10,结果在AL,余数在AH
              ADD AH,30H    ;余数转换为ASCII
              MOV [DI],AH   
              AND AX,00FFH  ;按位与，结果放AX
              DEC DI        ;DI-1
              CMP AL,0      
              JNE LOP2      ;AL不为0，循环/10取余
              LEA DX,STR    ;STR偏移地址给DX
              MOV AH,9      
              INT 21H       ;9号功能，输出字符串
              MOV AH,4CH    ;程序结束
              INT 21H
CODE ends
       end START