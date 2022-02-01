function NiXuShuChu()
%将一个整型数组的元素按逆序重新存放
a=input('输入数据:')
n=length(a);
for i=1:n/2
    b=a(i);
    a(i)=a(n+1-i);
    a(n+1-i)=b;
end
fprintf('%5d',a)
fprintf('\n')
end
