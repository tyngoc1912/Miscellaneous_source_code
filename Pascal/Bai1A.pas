var n,i:longint; s:real;
begin
repeat
write('n='); readln(n);
until (n>0) and (n<=10000);
s:=0;
for i:=1 to n do s:=s+(i*(i+1))/((i+2)*(i+3));
writeln('S=',s:0:3);
readln;
end.