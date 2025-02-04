var a,b,y:real; x:char;
begin
repeat
readln(a,b);
until b<>0;
readln(x);
case x of
'+':y:=a+b;
'-':y:=a-b;
'*':y:=a*b;
'/':y:=a/b;
else writeln('nhap sai phep toan');
end;
writeln(a:0:0,x,b:0:0,'=',y:0:1);
readln;
end.