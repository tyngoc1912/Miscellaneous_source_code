var tong,max,dem,i,n:integer; a:array[1..100] of integer;

function ktcp(x:integer):boolean;
begin
ktcp:=false;
if (x>=0) and (frac(sqrt(x))=0) then exit(true);
end;

begin
repeat
write('n=');readln(n);
until (n>5) and (n<20);
for i:=1 to n do
    begin
    write('a[',i,']=');readln(a[i]);
    end;
tong:=0;
max:=a[1];
dem:=0;
for i:=1 to n do
    begin
    if a[i]>0 then tong:=tong+a[i];
    if a[i]>max then max:=a[i];
    if ktcp(a[i]) then inc(dem);
    end;
writeln(tong);
writeln(max);
for i:=1 to n do
    if a[i]=max then writeln(i,' ');
writeln(dem);
readln;
end.
