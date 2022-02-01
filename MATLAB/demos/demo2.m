function demo2()
%求1到n的阶乘和
sum=0;
n=input('请输入n的值:');
for i=1:n
    sum=sum+factorial(i);
end
fprintf('1到%d的阶乘和为：%e\n',n,sum);
end