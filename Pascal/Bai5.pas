var n,i,dem:longint;

function ktnt(x:integer):boolean;
var  i:integer;
begin
ktnt:=false;
if x<2 then exit;
for i:=2 to trunc(sqrt(x)) do
    if x mod i=0 then exit;
ktnt:=true;
end;

begin
repeat
readln(n);
until (n>5) and (n<1000);
dem:=0;
for i:=n downto 1 do
   if (ktnt(i)=true) or (n mod i=0) then
          begin
          write(i,' ');
          inc(dem);
          end;
writeln;
writeln('Day tren co ',dem,' chu so');
readln;
end.
