program _tamgiac;
uses crt;
var a,b,c:integer;
begin
clrscr;
write('Nhap ba canh a,b,c: '); readln(a,b,c);
if a+b<8 then c:=a+b
else c:=a-b;
writeln(c);
readln;
end.
