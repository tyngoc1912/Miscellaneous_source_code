const fi='Bsearch.INP';
      fo='Bsearch.OUT';
var i,n,x:longint; a:array[1..10000000] of longint; f:text;

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
if l<j then quicksort(j,l);
if r>i then quicksort(i,r);
end;

function Bsearch(l,r:longint):longint;
var m:longint;
begin
if l>r then exit(0);
m:=(l+r) div 2;
if a[m]=x then exit(m)
else if a[m]>x then exit(Bsearch(l,m-1))
     else exit(Bsearch(m+1,r));
end;

begin
assign(f,fi); reset(f); read(f,n,x);
for i:=1 to n do read(f,a[i]); close(f);
assign(f,fo); rewrite(f);
quicksort(1,n);
writeln(f,Bsearch(1,n));
close(f);
end.