var n,i,s1,s2:longint; f:text;
begin
{repeat write('n='); readln(n); until (n>1) and (n<1000000);}
assign(f,'Bai1H.inp'); reset(f); readln(f,n); close(f);
assign(f,'Bai1H.out'); rewrite(f);
if (n>1) and (n<1000000) then
   begin
s1:=0;
s2:=0;
for i:=1 to n do
    if  odd(i) then s1:=s1+i
    else s2:=s2-i;
writeln(f,s1+s2);
   end
else writeln(f,'k phu hop');
close(f);
//readln;
end.