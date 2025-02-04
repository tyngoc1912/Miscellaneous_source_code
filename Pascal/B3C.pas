var n,k:longint; f:text;
begin
{repeat
readln(n,k);
until (n>0) and (k>0) and (k<=45) and (n<=1000000000);}
assign(f,'B3C.inp'); reset(f); readln(f,n,k); close(f);
assign(f,'B3C.out'); rewrite(f);
if (n>0) and (k>0) and (k<=45) and (n<=1000000000) then writeln(f,n div k,' ',n mod k)
else writeln(f,'k phu hop');
//readln;
close(f);
end.