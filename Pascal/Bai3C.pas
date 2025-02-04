var n,k,keo,keothua:longint; f:text;
begin
assign(f,'Bai3C.inp'); reset(f); read(f,n,k); close(f);
assign(f,'Bai3C.out'); rewrite(f);
if (n>0) and (k>0) and (n<=1000000000) and (k<=45) then
   begin
   keo:=n div k; keothua:= n mod k;
   writeln(f,keo,' ',keothua);
   end
else writeln(f,'du lieu k phu hop');
close(f);
end.
