var  i,n,dem,j,k:integer; f:text;
begin
assign(f,'Bai1G.inp');reset(f);readln(f,n);close(f);
assign(f,'Bai1G.out');rewrite(f);
{dem:=0;
for i:=1 to n do
   for j:=1 to i do
       begin
       inc(dem);
       if dem=n then begin write(f,i); break; end;
       end; }
dem:=0; k:=0;
while dem<n do
     begin
     inc(k);
     for i:=1 to k do if dem<n then inc(dem);
     end;
write(f,k);
close(f);
end.
