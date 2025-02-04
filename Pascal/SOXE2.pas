var  n,i,tam,kt,tong,nut:longint; f1,f2:text; dg,st:string;
begin
assign(f1,'SOXE2.inp'); reset(f1);
assign(f2,'SOXE2.out'); rewrite(f2);
readln(f1,n);
str(n,st);
for i:=1 to length(st) do
    begin
    val(st[i],tam,kt);
    tong:=tong+tam;
    end;
nut:=tong mod 10;
{tam:=n;
tong:=0;
while tam>0 do
    begin
    tong:=tong+tam mod 10;
    tam:=tam div 10;
    end;
nut:=tong mod 10; }
case nut of
7,9:dg:='dep';
0,1:dg:='xau';
else dg:='bth';
end;
writeln(f2,nut); writeln(f2,dg);
close(f1);  close(f2);
end.