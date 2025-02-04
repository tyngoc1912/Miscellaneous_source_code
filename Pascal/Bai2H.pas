var n:integer; f:text;

function s(x:integer):integer;
var i,dem:integer;
begin
dem:=0;
for i:=1 to x do if x mod i=0 then inc(dem);
s:=dem;
end;

begin
{repeat
write('n='); readln(n);
until (n>0) and (n<30000);}
assign(f,'Bai2H.inp'); reset(f); readln(f,n); close(f);
assign(f,'Bai2H.out'); rewrite(f);
if (n>0) and (n<30000) then begin
if n mod s(n)=0 then writeln(f,'co') else writeln(f,'ko'); end
else writeln(f,'k phu hop');
//readln;
close(f);
end.