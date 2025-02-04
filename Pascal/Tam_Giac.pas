var  a,b,c:integer; cv:longint; s,p:real;
begin
readln(a,b,c);
if (a+b<c) and (a+c<b) and (b+c<a) then writeln('Khong la ba canh cua mot tam giac')
else begin
     cv:=a+b+c;
     p:=(a+b+c)/2;
     s:=sqrt(p*(p-a)*(p-b)*(p-c));
     writeln('CV hinh TG la:',cv);
     writeln('DT hinh TG la:',s:0:1);
     end;
readln;
end.