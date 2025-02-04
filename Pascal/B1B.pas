var n,kq,i:integer; a:array[1..100] of integer;

function ucln(a,b:integer):integer;
begin
while a<>b do if a>b then a:=a-b else b:=b-a;
ucln:=a;
end;

begin
repeat
readln(n);
until (n>3) and (n<11);
for i:=1 to n do repeat readln(a[i]); until (a[i]>0) and (a[i]<100);
kq:=ucln(a[1],a[2]);
for i:=3 to n do kq:=ucln(kq,a[i]);
writeln(kq);
readln;
end.