%实验4.1 : 自由空间中视线传播距离与接收功率,控制变量；载波频率

%定义常量
power_tx = 1;          % 发射功率为1mW
frequency_2_4= 2.4e9:1e9:11.4e9;          % 载波频率为2.4 GHz-11.4Ghz
antenna_gain_tx = 1;        % 发射天线增益为1
antenna_gain_rx = 1;        % 接收天线增益为1
c = 299792458;              % 真空中光速 m/s
max_distance = 1200;        % 最大传播距离 m

%初始化变量数组，保存不同传播距离对应的路径损耗与接收功率
distance = 1 : max_distance;           % 传播距离从1m到1200m，间隔1m
path_loss = zeros(size(distance));     % 初始化各传播距离上的路径损耗
power_rx_dbm = zeros(length(frequency_2_4),length(distance));    %初始化各传播距离上的接收功率 dBm

%用循环为每个传播距离计算对应的路径损耗与接收
for i = 1 : length(frequency_2_4)
    for d = 1 : max_distance  % 传播距离d从1m到1200m
        path_loss(i,d) = (4 * pi * distance(d) * frequency_2_4(i)) ^ 2 ... 
            / (antenna_gain_tx * antenna_gain_rx * c ^ 2);  % 计算传播距离为d的路径损耗
        power_rx_dbm(i,d) = 10 * log10(power_tx / path_loss(i,d));  % 计算传播距离为d的接收功率 dBm
    end
end

 
%绘制接收功率与传播距离的关系曲线
%figure;  % 创建一个图形窗口
%Linesystle = ['.','o','x','+','*','.','o','x','+','*','*','s','p','d','h','v'];
for i = 1: length(frequency_2_4)
    plot(distance, power_rx_dbm(i,:),'LineWidth', 1.5);  % 画接收功率随距离变化的曲线
    hold on
end
grid on;  % 打开网格线
xlabel('Distance (m)');  % 创建横轴标注
ylabel('Received power (dBm)');  % 创建纵轴标注
lgd = legend('2.4 GHz','3.4 GHz','4.4 GHz','5.4 GHz','6.4 GHz','7.4 GHz','8.4 GHz','9.4 GHz','10.4 GHz','11.4 GHz');
title(lgd,'Control variable: Carrier frequency');











