var n,i:longint;  a:array[1..100] of integer;
begin
readln(n);
for i:=1 to n do readln(a[i]);
for i:=1 to n do
    begin
    if odd(a[i]) then writeln(a[i]) else writeln(a[i]);
    end;
readln;
end.
