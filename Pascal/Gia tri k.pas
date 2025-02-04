var n,i,k:longint; a:array[1..100] of longint;

procedure qs(l,r:longint);
var i,j,t,x:longint;
begin
i:=l; j:=r; x:=a[(l+r) div 2];
repeat
   while a[i]<x do inc(i);{day la tang dan}{Giam dan thi doi dau a[i],a[j]}
   while a[j]>x do dec(j);
   if i<=j then
      begin
      t:=a[i];
      a[i]:=a[j];
      a[j]:=t;
      inc(i); dec(j);
      end;
until i>j;
if j>l then qs(l,j);
if i<r then qs(i,r);
end;

begin
repeat
readln(n,k);
for i:=1 to n do readln(a[i]);
until (n>1) and (k>1) and (n>k) and (k<100000) and (abs(a[i])<=1000000);
qs(1,n);
for i:=1 to n do if i=k then write(a[i]);
readln;
end.