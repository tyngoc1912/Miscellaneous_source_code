var  n,i:longint;   gt:int64;
begin
readln(n);
gt:=1;
for i:=1 to n do gt:=gt*i;
writeln(n,'!=',gt);
readln;
end.