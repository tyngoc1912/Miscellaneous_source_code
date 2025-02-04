const fi='Bai2I.inp';
      fo='Bai2I.out';
var n,i:integer; f:text;

function ktnt(x:integer):boolean;
var i:integer;
begin
ktnt:=false;
if x<2 then exit;
for i:=2 to trunc(sqrt(x)) do if x mod i=0 then exit;
exit(true);
end;

begin
{repeat readln(n); until (n>=4) and (n<=998);}
assign(f,fi); reset(f); read(f,n); close(f);
assign(f,fo); rewrite(f);
if (n>2) and not(odd(n)) then
begin
for i:=2 to n div 2 do
    if (ktnt(i)) and (ktnt(n-i)) then begin writeln(f,i,' ',n-i); break; end;
end
else writeln(f,'k phu hop');
//readln;
close(f);
end.