var n:string; f:text;

function schuso(x:string):longint;
var tong,i,tam,kt:longint;
begin
tong:=0;
for i:=1 to length(x) do
    begin
    val(x[i],tam,kt);
    tong:=tong+tam;
    end;
schuso:=tong;
end;

begin
{repeat
write('n='); readln(n);
until length(n)<=225;}
assign(f,'Bai2E.inp'); reset(f); readln(f,n); close(f);
assign(f,'Bai2E.out'); rewrite(f);
if length(n)<=225 then
writeln(f,schuso(n)) else writeln(f,'k phu hop');
close(f);
//readln;
end.
