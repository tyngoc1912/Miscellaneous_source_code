var n,i,kq,u,bcnn:integer; a:array[1..20] of integer;

function ucln(a,b:integer):integer;
{var tam,i,min:integer;}
begin
{if a<b then min:=a else min:=b;
tam:=1;
for i:=min downto 1 do
if (a mod i=0) and (b mod i=0) then
begin tam:=i; break; end;
ucln:=tam;}
while a<>b do
    if a>b then a:=a-b else b:=b-a;
ucln:=a;
end;

begin
repeat
write('n='); readln(n);
until (n>3) and (n<11);
for i:=1 to n do
    begin
    repeat
    readln(a[i]);
    until (a[i]>0) and (a[i]<100);
    end;
kq:=ucln(a[1],a[2]);
for i:=3 to n do kq:=ucln(kq,a[i]);
bcnn:=(a[1]*a[2]) div kq;
for i:=3 to n do
    begin
    u:=ucln(bcnn,a[i]);
    bcnn:=(bcnn*a[i]) div u;
    end;
writeln('BCNN=',bcnn);
writeln('UCLN=',kq);
readln;
end.






 {n,i,k,min,ucln:longint; ok:boolean; a:array[1..20] of integer;
begin
repeat
write('n='); readln(n);
until (n>3) and (n<11);
for i:=1 to n do
    begin
    repeat
    readln(a[i]);
    until (a[i]>0) and (a[i]<100);
    end;
min:=a[1];
for i:=1 to n do
   if a[i]<min then min:=a[i];
for k:=1 to min do
   begin
   ok:=true;
   for i:=1 to n do
   if a[i] mod k<>0 then ok:=false;
   if ok=true then ucln:=k;
   end;
writeln('UCLN=',ucln);
readln;
end. }
