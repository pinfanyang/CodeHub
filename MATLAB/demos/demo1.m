function demo1()
%��д��ĸתСд��ĸ
a=input('��������:','s');
if a>=65 && a<=90
    fprintf('СдΪ:%c\n',a+32);
elseif a>=97 && a<=122
    fprintf('Сд��Ϊ����:%c\n',a);
else
    disp('data error!');
end
end
