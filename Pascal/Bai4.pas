var n,m:longint;

function tong_uocTs(a:longint):longint;
var i,tong:longint;
begin
tong:=0;
for i:=1 to a div 2 do
    if a mod i=0 then tong:=tong+i;
tong_uocTs:=tong;
end;

begin
repeat
readln(n);
until (n>0) and (n<100);
m:=n;
while tong_uocTs(m)<=m do inc(m);
if (tong_uocTs(m)>m) and (m>n) then writeln('So du thua la ',m);
readln;
end.
