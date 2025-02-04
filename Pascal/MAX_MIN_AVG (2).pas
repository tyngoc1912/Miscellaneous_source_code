var n,i,max,min:longint; avg:real; a:array[1..100] of integer;

begin
readln(n);
for i:=1 to n do readln(a[i]);
max:=a[1];
min:=a[1];
avg:=0;
for i:=1 to n do
    begin
    if a[i]>max then max:=a[i];
    if a[i]<min then min:=a[i];
    avg:=avg+a[i];
    end;
writeln('max=',max); writeln('min=',min); writeln('avg=',avg/n:0:1);
readln;
end.