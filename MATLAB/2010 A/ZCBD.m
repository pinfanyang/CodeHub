function V=ZCBD(h,r,L,R)
%罐体无变位情况罐容表标定模型
syms z
f=(R.^2-z.^2).*acos((R-1)/sqrt(R.^2-z.^2));
if h<=r
    V=(L+1-R).*(r.^2.*acos((r-h)/r)-(r-h).*sqrt(2.*h.*r-h.^2))+2.*int(f,-r,-r+h);
else
    V=pi.*r.^2.*(L+1)+pi/3+(L-R+1).*((h-r).*sqrt(2.*h.*r-h.^2)-r.^2.*acos((h-r)/r))-2.*int(f,h-r,r);
end
end


