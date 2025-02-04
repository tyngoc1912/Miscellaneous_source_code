var m,n,uoc:longint; f:text;

function ucln(a,b:longint):longint;
begin
while a<>b do if a>b then a:=a-b else b:=b-a;
ucln:=a;
end;

begin
{repeat
write('n='); readln(n);
write('m='); readln(m);
until (n>=1) and (m>=1) and (n<1000000000) and (m<1000000000);}
assign(f,'Bai3H.inp'); reset(f); read(f,n,m); close(f);
assign(f,'Bai3H.out'); rewrite(f);
if (n>=1) and (m>=1) and (n<1000000000) and (m<1000000000) then
   begin
uoc:=ucln(m,n);
writeln(f,n div uoc,' ',m div uoc);
   end
else writeln(f,'k phu hop');
close(f);
//readln;
end.
