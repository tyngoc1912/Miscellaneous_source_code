var a,b:string; x,y,kq,kt:integer; f:text;
begin
{repeat
write('a='); readln(a);
write('b='); readln(b);
until (length(a)<=50) and (length(b)<=50);}
assign(f,'B1C.inp'); reset(f); readln(f,a); readln(f,b); close(f);
assign(f,'B1C.out'); rewrite(f);
if (length(a)<=50) and (length(b)<=50) then
    begin
val(a[length(a)],x,kt);
val(b[length(b)],y,kt);
kq:=(x*y) mod 10;
writeln(f,kq);
    end
else writeln(f,'k phu hop');
close(f);
//readln;
end.
