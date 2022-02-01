%求解小椭圆储油罐变位前的v-h公式
clc;clear;
syms y a b h L
v1=L*int(2*a*sqrt(1-(y-b)^2)/b^2,y,0,h);
v=simplify(v1)
pretty(v)