uses crt;
var x,y:integer;
begin
clrscr;
readln(x,y);
x:=x+y;
y:=x-y;
x:=x-y;
writeln('x = ',x);
writeln('y = ',y);
readln;
end.