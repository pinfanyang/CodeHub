function SortNumber()
%ð������
a=input('����һ��һά����:');
n=length(a); %���ĸ���
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

            