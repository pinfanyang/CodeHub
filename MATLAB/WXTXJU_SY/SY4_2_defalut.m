%实验4.2 : 静止无噪声情况下有限条路径的多径传播_默认文件
clc;clear

%定义常量
sine_frequency = 2.4e9;  % 正弦波频率，单位Hz
sine_initial_phase = 0;  % 正弦波初始相位
sine_amplitude = 1;      % 正弦波幅度
sampling_rate = 100e9;   % 采样率，单位Hz
plot_duration = 5e-9;    % 画图时长，单位秒
simulation_duration = 320e-9; % 仿真时长，单位秒
path_delay = [0, 50e-9, 110e-9, 170e-9, 290e-9, 310e-9];   % 各路径的传播时延，单位秒
path_loss = [0, 3, 10, 18, 26, 32]; %各路径的路径损耗，单位dB

%定义并初始化后续变量
sampling_interval = 1 / sampling_rate;  % 采样间隔，单位秒
number_of_simulation_samples = simulation_duration * sampling_rate; % 仿真采样总量
number_of_path = length(path_delay);  % 路径个数
sine_signals = zeros(1,number_of_simulation_samples); % 初始化基准正弦波
path_signals = zeros(number_of_path, number_of_simulation_samples); % 初始化经各路径到达的正弦波
sum_of_path_signals = zeros(1, number_of_simulation_samples); % 初始化经各路径到达的正弦波的叠加

%生成基准正弦波的采样值，以此计算出经各路径到达接收端的正弦波，并叠加
t = sampling_interval : sampling_interval : simulation_duration;    % 采样时间
sine_signals(1, 1 : end) = sine_amplitude * sin(2 * pi * sine_frequency * t + sine_initial_phase);  % 生成基准正弦波

for i = 1 : number_of_path  % 对各条路径依次执行
  path_attenuation = sine_amplitude * 10 ^ (-path_loss(1, i) / 20);  % 计算当前经当前路径到达的正弦波的振幅
  number_of_delayed_samples = round(path_delay(1, i) * sampling_rate); % 当前路径的传播时延（采样个数）
  path_signals(i, 1 + number_of_delayed_samples : end) = path_attenuation * sine_signals(1, 1 : number_of_simulation_samples - number_of_delayed_samples); % 经当前路径到达的正弦波
  sum_of_path_signals(1, :) = sum_of_path_signals(1, :) + path_signals(i, :); % 将经当前路径到达的正弦波与之前到达的相叠加
end


%绘制出图形
figure; % 创建一个图形窗口
starting_sample_index = (simulation_duration - plot_duration) * sampling_rate + 1; % 画图时起始采样值的序号
plot(t(1, starting_sample_index : end) * 1e9, sum_of_path_signals(1, starting_sample_index : end)); % 画出叠加后的波形
xlabel('Time (ns)');  % 创建横轴标注
ylabel('Amplitude of received signals');  % 创建纵轴标注
