var i,n,j,tam:integer;   a:array[1..100] of integer;

begin
{readln(n);
for i:=1 to n do readln(a[i]);
for i:=1 to n-1 do
   for j:=i+1 to n do
       if a[i]<=a[j] then
           begin
           tam:=a[i];
           a[i]:=a[j];
           a[j]:=tam;
           end;
for i:=1 to n do write(a[i],' ');
readln;}
readln(n);
for i:=1 to n do writeln(i,' '); readln;
end.
