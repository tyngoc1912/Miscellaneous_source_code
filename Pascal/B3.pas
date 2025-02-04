var  n,i,max,dem:integer; a:array[1..100]of integer;

function ktnt(x:integer):boolean;
var  i:integer;
begin
ktnt:=false;
if x<2 then exit;
for i:=2 to x div 2 do if x mod i=0 then exit;
exit(true);
end;

begin
repeat
write('n=');readln(n);
until (n>2) and (n<20);
for i:=1 to n do
    begin
    write('a[',i,']=');readln(a[i]);
    end;

dem:=0;
max:=a[1];
for i:=1 to n do
   if a[i]>max then max:=a[i];
writeln('max=',max);
for i:=1 to n do
   if ktnt(a[i])=true then
      begin
      write(a[i],' ');  inc(dem);
      end;
writeln;
writeln('co ',dem,' so nguyen to');
readln;
end.
