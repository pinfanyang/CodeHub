function demo2()
%��1��n�Ľ׳˺�
sum=0;
n=input('������n��ֵ:');
for i=1:n
    sum=sum+factorial(i);
end
fprintf('1��%d�Ľ׳˺�Ϊ��%e\n',n,sum);
end