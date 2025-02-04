var j,n,i,d,max,dem:longint; a:array[1..100] of integer; f:text;

function s(x:longint):longint;
var i,dem:longint;
begin
dem:=0;
for i:=1 to x do if x mod i=0 then inc(dem);
s:=dem;
end;

begin
{repeat
write('n='); readln(n);
until (n>=1) and (n<=30);
for i:=1 to n do
   repeat
   write('a[',i,']='); readln(a[i]);
   until (a[i]>=1) and (a[i]<=32677);}
assign(f,'Bai4D.inp'); reset(f); readln(f,n);
for i:=1 to n do read(f,a[i]); close(f);
assign(f,'Bai4D.out'); rewrite(f);
if (n>=1) and (n<=30) and (a[i]>=1) and (a[i]<=32677) then
begin
max:=0;
dem:=0;
for i:=1 to n do
   if s(a[i])>max then max:=s(a[i]);
for i:=1 to max do
    begin
    d:=0;
    for j:=1 to n do
       if s(a[j])=i then inc(d);
    if d>0 then
       begin writeln(f,i,' ',d); inc(dem); end;
    end;
writeln(f,dem);
end
else writeln(f,'du lieu k phu hop');
//readln;
close(f);
end.
