var n,k,max,i,j,tong:longint; a:array[1..100] of integer;
begin
repeat
readln(n,k);
until (n>0) and (k>0) and (n<=1000000) and (k<=n);
for i:=1 to n do
    repeat readln(a[i]); until abs(a[i])<=1000;
j:=0;
for i:=n+1 to n+k-1 do
    begin
    j:=j+1; a[i]:=a[j];
    end;
tong:=0;
for i:=1 to k do max:=max+a[i];
for i:=2 to n do
    begin
    for j:=i to i+k-1 do tong:=tong+a[j];
    if tong>max then max:=tong;
    tong:=0;
    end;
writeln(max);
readln;
end.