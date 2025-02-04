var n,i:longint;

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
for i:=n downto 1 do
if ktnt(i)=true then write(i,' ');
readln;
end.