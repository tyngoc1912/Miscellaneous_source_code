var i,a,b,dem:longint;  st:string;

function ktdx(x:string):boolean;
var i:integer;
begin
ktdx:=false;
for i:=1 to length(x) div 2 do
    if x[i]<>x[length(x)-i+1] then exit;
ktdx:=true;
end;

function chuyennhiphan(n:longint):string;
var du:longint; st,kq:string;
begin
kq:='';
while n>0 do
     begin
     du:=n mod 2;
     str(du,st);
     kq:=st+kq;
     n:=n div 2;
     end;
chuyennhiphan:=kq;
end;

begin
repeat
readln(a,b);
until (a>0) and (a<=b) and (b<=20000000);
dem:=0;
for i:=a to b do
    begin
    str(i,st);
    if (ktdx(st)) and (ktdx(chuyennhiphan(i))) then
    begin
    writeln(st:10,'-',chuyennhiphan(i)); inc(dem);
    end;
    end;
writeln(dem:10,' so');
readln;
end.
