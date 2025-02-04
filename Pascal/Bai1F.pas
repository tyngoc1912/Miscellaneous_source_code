var max,i,tam,kt:integer; st:string; n:int32; f:text;
begin
{repeat
write('n='); readln(n);
until (n>1000) and (n<1000000000000);}
assign(f,'Bai1F.inp'); reset(f); readln(f,n); close(f);
assign(f,'Bai1F.out'); rewrite(f);
if (n>1000) and (n<1000000000000) then
begin
str(n,st);
val(st[1],max,kt);
for i:=2 to length(st) do
    begin
    val(st[i],tam,kt);
    if tam>max then max:=tam;
    end;
writeln(f,max);
end
else writeln(f,'k phu hop');
close(f);
//readln;
end.
