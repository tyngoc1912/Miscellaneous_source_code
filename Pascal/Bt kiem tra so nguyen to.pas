var n,i,dem:integer;
begin
readln(n);
dem:=0;
for i:=1 to n do if n mod i=0 then dem:=dem+1;
if dem=2 then writeln(n,' la so ngto') else writeln(n,' ko phai la so ngto');
readln;
end.
