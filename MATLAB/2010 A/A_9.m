%综合考虑纵向清晰和横向偏转
clear all
syms x y %区域1
L=8;R=1.5;R0=1.625;H=1;l=2;a=0.0377;b=0.0785;
vh1=2*int((y-R+R*(1-cos(b))+l*tan(a))/tan(a)*(R^2-y^2)^0.5,R-R*(1-cos(b))-l*tan(a),R);
r=(R0^2-(x-R)^2)^0.5;
vh2=int(r^2*acos((R0-H)/r)-((r^2-(R0-H)^2)^0.5)*(R0-H),x,0,R*(1-cos(b))+l*tan(a));
vh=vh1+vh2;
eval(vh)

syms x y %区域2
L=8;R=1.5;R0=1.625;H=1;l=2;a=0.0377;b=0.0785;
hb2max=((L-l)*tan(a)-R*(1-cos(b)))/cos(b);
hb=0.2224;
h=R-(R-hb)*cos(b);
vh1=2*int((y-R+h+l*tan(a))/tan(a)*(R^2-y^2)^0.5,y,R-h-l*tan(a),R);
r=(R0^2-(x-R)^2)^0.5;
vh2=int(r^2*acos((R0-H)/r)-((r^2-(R0-H)^2)^0.5)*(R0-H),x,0,h+l*tan(a));
vh=vh1+vh2;
eval(vh)

syms x y %区域3
L=8;R=1.5;R0=1.625;H=1;l=2;a=0.0377;b=0.0785;
hb=2.93;
h=R-(R-hb)*cos(b);
vh1=2*L*int((R^2-(y-R)^2)^0.5,y,0,h);
vh11=2*int((-y+h+l*tan(a))/tan(a)*(R^2-(y-R)^2)^0.5,y,h,h+l*tan(a));
vh12=2*int((L-(h-y+l*tan(a))/tan(a))*(R^2-(y-R)^2)^0.5,y,h-(L-l)*tan(a),h);
r=(R0^2-(y-R)^2)^0.5;
vh21=int(r^2*acos((R0-H)/r)-((r^2-(R0-H)^2)^0.5)*(R0-H),y,0,h+l*tan(a));
vh22=int(r^2*acos((R0-H)/r)-((r^2-(R0-H)^2)^0.5)*(R0-H),y,0,h-(L-l)*tan(a));
vh=vh1+vh11-vh12+vh21+vh22;
eval(vh)

syms x y %区域4
L=8;R=1.5;R0=1.625;H=1;l=2;a=4*pi/180;hb=3;
hb4min=(R*(1+cos(b))-l*tan(a))/cos(b);
bb4max=2*R;
h=R-(R-hb)*cos(b);
v1=L*pi*R^2;
vh1=2*int((y+R-h+(L-l)*tan(a))/tan(a)*(R^2-y^2)^0.5,y,h-R-(L-l)*tan(a),R);
r=(R0^2-(y-R)^2)^0.5;
vh21=int(r^2*acos((R0-H)/r)-((r^2-(R0-H)^2)^0.5)*(R0-H),y,0,h-(L-l)*tan(a));
vh22=pi*H^2*(R0-H/3);
vh=v1-vh1+vh21+vh22;
eval(vh)

syms x y %区域5
L=8;R=1.5;R0=1.625;H=1;l=2;a=4*pi/180;h=3;
h=R-(R-hb)*cos(b);
v1=L*pi*R^2;
vh1=2*int((y-R+(L-l)*tan(a))/tan(a)*(R^2-y^2)^0.5,y,R-(L-l)*tan(a),R);
r=(R0^2-(y-R)^2)^0.5;
vh21=int(r^2*acos((R0-H)/r)-((r^2-(R0-H)^2)^0.5)*(R0-H),y,0,2*R-(L-l)*tan(a));
vh22=pi*H^2*(R0-H/3);
vh=v1-vh1+vh21+vh22;
eval(vh)