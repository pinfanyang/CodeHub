%求解球缺部分的总体积
clear,clc
format long
syms h x hb b l a
R=1.5; b=0;a=0; l=2; h=3;
s=int((1.625^2-(1.5-x)^2)*acos((1.625-1)/sqrt(1.625^2-(1.5-x)^2))-sqrt(1.625^2-(1.625-1)^2-(1.5-x)^2)*(1.625-1),x,0,h);
h=R-(R-hb)*cos(b)+l*tan(a);
eval(s)