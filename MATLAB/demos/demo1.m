function demo1()
%大写字母转小写字母
a=input('输入数据:','s');
if a>=65 && a<=90
    fprintf('小写为:%c\n',a+32);
elseif a>=97 && a<=122
    fprintf('小写即为本身:%c\n',a);
else
    disp('data error!');
end
end
