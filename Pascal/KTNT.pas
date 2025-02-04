var n:longint;

function ktnt(x:longint):boolean;
var i:longint;
begin
ktnt:=false;
if x<2 then exit;
for i:=2 to trunc(sqrt(x)) do
   if x mod i=0 then exit;
ktnt:=true;
end;

begin
readln(n);
if ktnt(n)=true then writeln('ngto')
else writeln('ko ngto');
readln;
end.