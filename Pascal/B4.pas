var n,i,dem,tong:integer; a:array[1..100] of integer;

function kthh(x:integer):boolean;
var i,tong:integer;
begin
kthh:=false;
tong:=0;
for i:=1 to x div 2 do
    if x mod i=0 then tong:=tong+i;
if tong=x then exit(true);
end;

begin
repeat
write('n=');readln(n);
until (n>2) and (n<20);
for i:=1 to n do
    begin
    write('a[',i,']=');readln(a[i]);
    end;
tong:=0;
dem:=0;
for i:=1 to n do
    begin
    if a[i] mod 3=0 then tong:=tong+a[i];
    if kthh(a[i]) then inc(dem);
    end;
writeln(tong,' ',dem);
readln;
end.