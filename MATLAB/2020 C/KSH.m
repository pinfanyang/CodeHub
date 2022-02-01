%将数据可视化处理
data=xlsread('D:\DataHub\CodeHub\MATLAB\2020 C\附件1：123家有信贷记录企业的相关数据.xlsx','进项发票信息','A2:F210948');
boxplot(data(:,3:5),1:3);%调用箱型图命令
title('箱型图')
xlabel('样本属性名称')
ylabel('样本数值大小')
set(xlabel('样本属性名称'),FontSize',22)
set(ylabel('样本数值大小'),FontSize',22)
set(title('箱型图'),FontSize',22)%设置横纵轴、标题文本字体大小