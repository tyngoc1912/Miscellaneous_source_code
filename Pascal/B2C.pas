var  n,k,i,tg:integer; t:array[1..100] of integer;  f:text;
begin
{repeat
readln(n,k);
until (n>0) and (k>0) and (n<10000) and (k<=n);
for i:=1 to n do repeat read(f,t[i]); until (t[i]>0) and (t[i]<100);}
assign(f,'B2C.inp'); reset(f); readln(f,n,k);
for i:=1 to n do read(f,t[i]); close(f);
assign(f,'B2C.out'); rewrite(f);
if (n>0) and (k>0) and (n<10000) and (k<=n) and (t[i]>0) and (t[i]<100) then
   begin
tg:=0;
for i:=1 to k-1 do tg:=tg+t[i];
writeln(f,tg);
   end
else writeln(f,'k phu hop');
close(f);
//readln;
end.