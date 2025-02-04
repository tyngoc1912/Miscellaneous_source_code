var  dem,n,i,j,tam,max:integer; a:array[1..100] of integer; f:text;
begin
{repeat
write('n='); readln(n);
until (n>1) and (n<10000);
for i:=1 to n do
    repeat
    write('a[',i,']='); readln(a[i]);
    until (a[i]>0) and (a[i]<1000); }
assign(f,'Bai4H.inp'); reset(f); readln(f,n);
for i:=1 to n do read(f,a[i]); close(f);
assign(f,'Bai4H.out'); rewrite(f);
if (n>1) and (n<10000) and (a[i]>0) and (a[i]<1000) then
    begin
for i:=1 to n-1 do
   for j:=i+1 to n do
       if a[i]<a[j] then
           begin
           tam:=a[i];
           a[i]:=a[j];
           a[j]:=tam;
           end;
max:=a[1];

dem:=0;
for i:=2 to n-1 do
    if a[i]<max then begin inc(dem); if a[i]<>a[i+1] then break; end;
writeln(f,dem);
    end
else writeln(f,'k phu hop');
close(f);
//readln;
end.
