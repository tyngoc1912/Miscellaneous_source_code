var n,i:integer; kt:boolean; a:array[1..100] of integer; f:text;

begin
{repeat
write('n='); readln(n);
until (n>1) and (n<=1000);
for i:=1 to n do
    repeat
    write('a[',i,']='); readln(a[i]);
    until (a[i]>-1000) and (a[i]<1000);}
assign(f,'Bai3G.inp'); reset(f); readln(f,n);
for i:=1 to n do read(f,a[i]); close(f);
assign(f,'Bai3G.out'); rewrite(f);
if (n>1) and (n<=1000) and (a[i]>-1000) and (a[i]<1000) then
   begin
kt:=true;
for i:=1 to n-1 do
    if a[i]>a[i+1] then begin kt:=false; write(f,i+1); break; end;
if kt=true then write(f,0);
   end
else writeln(f,'k phu hop');
//readln;
close(f);
end.
