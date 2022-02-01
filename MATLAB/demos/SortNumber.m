function SortNumber()
%冒泡排序
a=input('输入一个一维数组:');
n=length(a); %数的个数
for i=1:n
    for j=2:n
        if a(j-1)>a(j)
            b=a(j-1);
            a(j-1)=a(j);
            a(j)=b;
        end
    end
end
fprintf('%5d',a);
fprintf('\n');
%end

            