var a,b,c,m,sla,slb,slc,i,j,k,dem:longint;
begin
readln(a);
readln(b);
readln(c);
readln(m);
sla:=m div a;
slb:=m div b;
slc:=m div c;
dem:=0;
for i:=0 to slc do
 for j:=0 to slb do
  for k:=0 to slc do
   if i*c+j*b+k*a=m then
    begin
    inc(dem);
    writeln(i,'*',c,'+',j,'*',b,'+',k,'*',a);
    end;
if dem=0 then write('ko co to hop');
readln;
end.
