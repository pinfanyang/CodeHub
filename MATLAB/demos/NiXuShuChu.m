function NiXuShuChu()
%��һ�����������Ԫ�ذ��������´��
a=input('��������:')
n=length(a);
for i=1:n/2
    b=a(i);
    a(i)=a(n+1-i);
    a(n+1-i)=b;
end
fprintf('%5d',a)
fprintf('\n')
end
