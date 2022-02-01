datarea segment ;数据段定义
    stringl    db    'Move the cursor backward.'
    string2    db    'Move the cursor backward.'
    ;结果显示定义
    mess1    db    'Match.',13,10,'$'
    mess2    db    'No match!',13,10,'$'
datarea ends
;----------------------------------------------------------------
prognam segment ;程序段定义
    main    proc far
    assume cs:prognam,ds:datarea,es:datarea    ;寄存器分别对应：代码段寄存器、数据段寄存器、附加段寄存器
    start:;开始执行地址
    ;为返回设置堆栈处理
    push    ds    ;保存旧的数据段
    sub     ax,ax ;AX寄存器归零处理
    push    ax    ;保存到栈中
    ;将DS寄存器设置为当前数据段
    mov     ax,datarea ;数据段地址
    mov     ds,ax      ;放到DS数据段寄存器中
    mov     es,ax      ;放到ES数据段寄存器中
    ;主程序
    lea     si,stringl ;将String1的地址送到SI源变址寄存器中
    lea     di,string2 ;将String2的地址送到DI目标变址寄存器中
    cld                ;设置方向标志，DF置0,串操作的存储器地址自动增加；
    mov     cx,25      ;计数寄存器加25，其为字符串总个数
    repz    cmpsb      ;如果ds:si和es:di所指向的两个字节相等，则继续比较。所以如果不相等的话，就停止循环。但是这时候si和di已经自动加1了，如果要找不相等的那两个数，就要把si和di减1。
    jz      match      ;为0跳转match
    ;jnz match
    lea     dx,mess2   ;不为0，说明2个字符串不相等，将mess2的地址传送到DX数据寄存器中，准备后续输出
    jmp     short disp ;段内跳转disp
    match:
    lea     dx,mess1   ;为0，说明2个字符串相等，将mess1的地址传送到DX数据寄存器中，准备后续输出
    disp:              ;输出字符串功能，注意必须先把字符串地址送到DX中去
            mov ah,09  
            int    21h
    ret    ;子程序返回
    main    endp    ;主程序结束
    prognam ends    ;代码段结束
    end    start    ;程序结束
