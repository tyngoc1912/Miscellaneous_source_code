var a,b,c:longint;

function ucln(a,b:longint):longint;
begin
while a<>b do if a>b then a:=a-b else b:=b-a;
ucln:=a;
end;

begin
repeat
readln(a,b,c);
until (a>0) and (b>a) and (c>b);
if (ucln(a,b)=1) or (ucln(a,c)=1) or (ucln(a,b)=1)
then writeln(a,',',b,',',c,' sanh doi');
readln;
end.













