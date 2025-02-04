var r,x,y,xA,yA,kc:real;
begin
write('ban kinh duong tron'); readln(r);
write('hoanh do tam='); readln(x);
write('tung do tam='); readln(y);
write('hoanh do diem A='); readln(xA);
write('tung do diem A='); readln(yA);
kc:=sqrt(sqr(x-xA)+sqr(y-yA));
if kc>r then writeln('Diem A nam ngoai duong tron')
else if kc<r then writeln('Diem A nam trong duong tron')
     else writeln('Diem A nam tren duong tron');
readln;
end.