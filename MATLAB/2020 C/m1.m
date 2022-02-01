%对附录1中”进项“和”销项“发票信息进行处理
% clear,clc
% 
% data=xlsread('D:\DataHub\CodeHub\MATLAB\2020 C\附件1：123家有信贷记录企业的相关数据.xlsx','进项发票信息');%读取数据
[m,~]=find(strcmp(data(:,8),'作废发票') );     %找到发票状态为作废发票的记录
data(m,:)=0;        %作废发票记录置0
result1=zeros(123,15);  %记录总值
variance1=zeros(123,10);%记录方差
for i=1:123
    [m,~]=find(data(:,1)==i); %企业数据位置
    re=data(m(1,1):max(m),:);%同一公司数据
    re=sortrows(re,[3,4]);%按照时间顺序排序
    void=find(re(:,1)==0);%作废发票记录
    void=size(void,1);%作废记录
    valid=size(m,1)-void;%有效记录
    %求每个公司每个月的方差
    date=re((void+1):size(re,1),:);
    date((size(date,1)+1),4)=0;
    k=1;    
    j=1;
    mount=zeros(48,10);
    month=date(k,4);
    while(month ~= 0)
        mount(j,:)=mount(j,:)+date(k,:);
        k=k+1;
        if month~=date(k,4)
            j=j+1;
        end
        month=date(k,4);
    end
    vari=std(mount,1);
    variance1(i,1)=i;
    variance1(i,2:10)=vari(2:10);%将值记录在variance中
    smonth(1,:)=date(1,3:4);%发票起始月份
    smonth(2,:)=date(size(date,1)-1,3:4);%发票终止月份
    length=((smonth(2,1)-2017)*12+smonth(2,2))-((smonth(1,1)-2017)*12+smonth(1,2))+1;%计算运营时长
    up=data(m(1,1):max(m),6);
    up=nume1(unique(up));%求上游企业数量
    result1(i,1)=i;%企业代号
    result1(i,11)=valid;%有效发票总量
    result1(i,12)=void;%无效发票总量
    result1(i,13)=valid/numel(m);%有效发票所占比例
    result1(i,14)=up;%上游企业数量
    result1(i,15)=length;%经营时长
    result1(i,2:10)=sum(re(:,2:10),1);
end
xlswrite('123企业结果',result1,'进项结果','A2:O124');
xlswrite('123企业月方差',variance1,'进项结果','A2:J124');