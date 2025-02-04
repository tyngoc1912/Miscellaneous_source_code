const fi='SOCO.INP';
      fo='SOCO.OUT';
var n:longint; st:string; f:text;

function tongcs(x:string):string;
var tong,i,so,kt:longint; st:string;
begin
tong:=0;
st:='';
for i:=1 to length(x) do
    begin
    val(x[i],so,kt);
    tong:=tong+so;
    end;
str(tong,st);
tongcs:=st;
end;

begin
{repeat
readln(n);
until (n>0) and (n<=1000000000);
str(n,st);}
assign(f,fi); reset(f); readln(f,n); close(f);
assign(f,fo); rewrite(f);
if (n>0) and (n<=1000000000) then
   begin
str(n,st);
while length(st)>1 do st:=tongcs(st);
writeln(f,st);
   end
else writeln(f,'du lieu k phu hop');
//readln;
close(f);
end.
