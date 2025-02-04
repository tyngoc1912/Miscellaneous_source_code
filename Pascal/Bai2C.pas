var n,k,tg,i:integer; f:text; t:array[1..100] of integer;
begin
assign(f,'Bai2C.inp'); reset(f); readln(f,n,k);
for i:=1 to n do read(f,t[i]);
close(f);
assign(f,'Bai2C.out'); rewrite(f);
if (n>0) and (n<10000) and (k<=n) and (t[i]>0) and (t[i]<100) then
    begin
    for i:=1 to k-1 do tg:=tg+t[i];
    end
else writeln(f,'du lieu k phu hop');
writeln(f,tg);
close(f);
end.