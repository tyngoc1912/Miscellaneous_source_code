var  f:text; a,b:string; x,y:char; kq,x1,y1,kt:integer;
begin
assign(f,'Bai1C.inp'); reset(f); readln(f,a); readln(f,b); close(f);
assign(f,'Bai1C.out'); rewrite(f);
//readln(a); readln(b);
if (length(a)<=50) and (length(b)<=50) then
begin
x:=a[length(a)];
y:=b[length(b)];
val(x,x1,kt);
val(y,y1,kt);
kq:=(x1*y1) mod 10;
writeln(f,'chu so cuoi la ',kq);
end
else writeln(f,'k phu hop du lieu');
close(f);
//readln;
end.
