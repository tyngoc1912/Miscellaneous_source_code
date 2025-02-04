var n,i:longint;  f:text;

function ktnt(x:longint):boolean;
var i:longint;
begin
ktnt:=false;
if x<2 then exit;
for i:=2 to trunc(sqrt(x)) do
    if x mod i=0 then exit;
exit(true);
end;

begin
{repeat
readln(n);
until (n>0) and (n<10000000);}
assign(f,'B4C.inp'); reset(f); readln(f,n); close(f);
assign(f,'B4C.out'); rewrite(f);
if (n>0) and (n<10000000) then
    begin
if (n>2) and (not(odd(n))) then
  begin
  for i:=2 to n div 2 do
      if (ktnt(i)) and (ktnt(n-i)) then writeln(f,i,' ',n-i);
  end;
    end
else writeln(f,'k phu hop');
//readln;
close(f);
end.
