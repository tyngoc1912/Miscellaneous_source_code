var d:integer;

procedure DT_TG;
var a,b,c:integer;
    p,s:real;
begin
readln(a,b,c);
if (a+b<c) and (a+c<b) and (b+c<a) then writeln('Khong la ba canh cua mot tam giac')
else begin
     p:=(a+b+c)/2;
     s:=sqrt(p*(p-a)*(p-b)*(p-c));
     writeln('DT hinh TG la:',s:0:1);
     end;
end;

procedure DT_TRON;
var r:integer;
    s:real;
const pi=3.14;
begin
readln(r);
s:=r*r*pi;
writeln('DT hinh tron la:',s:0:1);
end;

procedure DT_VUONG;
var z:integer;
    s:longint;
begin
readln(z);
s:=sqr(z);
writeln('dien tich vuong la:',s);
end;

procedure DT_CN;
var x,y:integer;
    s:longint;
begin
readln(x,y);
s:=x*y;
writeln('dien tich hcn la:',s);
end;

begin
writeln('0:Exit');
writeln('1:DT_CN');
writeln('2:DT_TRON');
writeln('3:DT_VUONG');
writeln('4:DT_TG');

readln(d);
case d of
0:exit;
1:DT_CN;
2:DT_TRON;
3:DT_VUONG;
4:DT_TG;
end;

readln;
end.