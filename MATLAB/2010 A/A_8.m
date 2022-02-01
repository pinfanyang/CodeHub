%估计参数α和β
clear;clc;
detav=243.85/1000; minv=100;
h1=2485.73/1000;h2=2474.4/1000;
L=8;R=1.5;R0=1.625;H=1;l=2;
syms y
for a=linspace(0.001,4.5*pi/180,20)
    for b=linspace(0.001,4.5*pi/180,20)
        hb=h1;
        v1=-6*cos(b)*(9-9*cos(b)^2+2*cos(b)*hb)^(1/2);
        hb=h2;
        v2=-6*cos(b)*(9-9*cos(b)^2+2*cos(b)*hb)^(1/2);
        mv=v1-v2;
        if minv>abs(mv-detav)
        minv=abs(mv-detav);
        aa=a;bb=b;
        end
    end
end
%aa bb minv