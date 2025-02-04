var y,x,dem,m,n,k,i:integer;f:text;a:array[-10..100,-10..100]of integer;
begin
assign(f,'gomin.inp');reset(f);
readln(f,n,m,k);
for i:=1 to k do
 begin
  readln(f,y,x);
  a[y,x]:=200;
 end;
assign(f,'gomin.out');rewrite(f);
for y:=1 to n do
begin
for x:=1 to m do
  begin
  dem:=0;
  if a[y-1,x-1]>0 then inc(dem);
  if a[y-1,x]>0 then inc(dem);
  if a[y-1,x+1]>0 then inc(dem);
  if a[y+1,x-1]>0 then inc(dem);
  if a[y+1,x]>0 then inc(dem);
  if a[y+1,x+1]>0 then inc(dem);
  if a[y,x-1]>0 then inc(dem);
  if a[y,x+1]>0 then inc(dem);
  if a[y,x]=200 then write(f,'*') else write(f,dem);
  end;
writeln(f);
end;
close(f);
end.
