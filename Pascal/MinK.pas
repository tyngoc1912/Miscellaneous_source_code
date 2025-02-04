var n,k,i:longint; a:array[1..100000] of longint;

procedure quicksort(l,r:longint);
var i,j,x,tam:longint;
begin
i:=l; j:=r; x:=a[(l+r) div 2];
repeat
     while a[i]<x do inc(i);
     while a[j]>x do dec(j);
     if i<=j then
        begin
        tam:=a[i]; a[i]:=a[j]; a[j]:=tam;
        inc(i); dec(j);
        end;
until i>j;
if j>l then quicksort(l,j);
if r>i then quicksort(i,r);
end;

begin
repeat
readln(n,k);
until (n>=1) and (k>=1) and (n>=k) and (n<=100000);
quicksort(1,n);
for i:=1 to n do if a[i]=k then write(i,' ');
readln;
end.