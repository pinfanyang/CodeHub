%用蒙特卡洛模拟法计算忽略部分燃油体积(以α=4.1°为例)
clc;clear;
syms a b h
h=0.1; a=4.1*pi/180; r=tan(a); m=0;
for x=-1.5:0.001:1.5
for y=-1:0.001:0
for z=0:0.001:3
if z>=h
if r/h*y+1/h*z-1<=0
if x^2+(y-0.625)^2+(z-1.625)^2<=1.625^2
m=m+1;
end
end
end
end
end
end
s=3^2*1*m/(3/0.001+1)^2/(1/0.001+1)