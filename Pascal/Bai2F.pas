const maxn=1000000;
type mang=array[1..maxn] of integer;

var n,i,j,k:int32; maxuoc,tam,dem:integer;  a:mang;

function demuoc(x:integer;b:mang;k:int32):integer;
var i:int32; dem:integer;
begin
dem:=0;
for i:=1 to k do if x mod b[i]=0 then inc(dem);
demuoc:=dem;
end;

begin
repeat
write('n='); readln(n);
until (n>0) and (n<maxn);
for i:=1 to n do
    begin
    write('a[',i,']='); readln(a[i]);
    end;

maxuoc:=0;
for i:=1 to n do
    begin
    dem:=0;
    for k:=1 to n do
        if a[i] mod a[k]=0 then inc(dem);
    if dem>maxuoc then maxuoc:=dem;
    end;

for i:=1 to n-1 do
   for j:=i+1 to n do
       if a[i]<a[j] then
           begin
           tam:=a[i];
           a[i]:=a[j];
           a[j]:=tam;
           end;

for i:=1 to n do if demuoc(a[i],a,n)=maxuoc then write(a[i],' ');
readln;
end.
