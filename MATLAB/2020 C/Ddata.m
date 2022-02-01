%对“附件1：123家有信贷记录企业的相关数据”表格我们进行了如下操作：
%1、发票状态的处理，将有效发票作为1，将作废发票作为0；
%2、通过Matlab将发票状态为作废发票的发票信息过滤筛除掉；
%3、按4个标准差将数据中的异常大小数据进行了过滤筛选。
data=xlsread('D:\DataHub\CodeHub\MATLAB\2020 C\附件1：123家有信贷记录企业的相关数据.xlsx','进项发票信息','G2：G404');%企业一2017年进货信息
% 异常数据的处理（默认按4个标准偏差）
% 去除异常数据，包括NaN，Inf，和异常大小数据
function data=trim(data,outval)
%data：列状数据，每列来自一个总体
%outval：系数因子，离均值超过outval倍标准差被判为异常大小，默认值为4
if nargin<2
    outval=4
end
outliers=(isnan(data)|abs(data)==inf);
%筛选出异常字符或者绝对值为无穷大的作为异常数据
[n,m]=size(data);
if m>1
    data(any(outliers'),:)=[];
else
    data(find(outliers'),:)=[];
end
[n,m]=size(data);
mu=mean(data);
sigma=std(data);
outliers=(abs(data-ones(n,1)*mu)>outval*ones(n,1)*sigma);
if m>1
    data(any(outliers'),:)=[];
else
    data(find(outliers'),:)=[];
end
clear
rng default；
%设定随机数种子，结果可再现
c=normrnd(10,2,1000,1);
%1000个正态分布N（10，2^2随机数）
c(1)=NaN;
c(2)=c(2)*1000;
%假设两个数出了异常差错，一个NaN，一个放大10000倍
mean(c),nanmean(c)
trimmean(c,2) %trimmean忽略上下各1%数据的均值
ct=trim(2);mean(ct),std(ct) %清除异常数据，检验均值、标准差结果是否正常
end