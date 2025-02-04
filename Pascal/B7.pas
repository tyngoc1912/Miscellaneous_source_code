var min,max,n,i,j,tam:integer; a:array[1..100] of integer;
begin
repeat
write('n=');readln(n);
until (n>5) and (n<20);
for i:=1 to n do
    begin
    write('a[',i,']=');readln(a[i]);
    end;
min:=a[1]; max:=a[1];
for i:=2 to n do
    begin
    if a[i]>max then max:=a[i];
    if a[i]<min then min:=a[i];
    end;
writeln(max,' ',min);
for i:=1 to n do
    begin
    if a[i]=max then writeln('cac vt la ',i);
    if a[i]=min then writeln('cac vt la ',i);
    end;
for i:=1 to n-1 do
     for j:=2 to n do
         if a[i]<a[j] then
            begin
            tam:=a[i];
            a[i]:=a[j];
            a[j]:=tam;
            end;
for i:=1 to n do writeln(a[i]);
readln;
end.
