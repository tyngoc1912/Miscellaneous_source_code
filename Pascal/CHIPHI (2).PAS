uses math;
const fi='CHIPHI.INP';
      fo='CHIPHI.OUT';
var a,b,c,di1,den1,di2,den2,di3,den3,tong,dem,ln,nn,i:integer; f:text;

begin
assign(f,fi); reset(f); readln(f,a,b,c);
readln(f,den1,di1); readln(f,den2,di2); readln(f,den3,di3); close(f);
assign(f,fo); rewrite(f);
ln:=max(di1,max(di2,di3));
nn:=min(den1,min(den2,den3));
tong:=0;
for i:=nn to ln do
    begin
    dem:=0;
    if i in [den1..di1-1] then inc(dem);
    if i in [den2..di2-1] then inc(dem);
    if i in [den3..di3-1] then inc(dem);
    if dem=1 then tong:=tong+a;
    if dem=2 then tong:=tong+b*2;
    if dem=3 then tong:=tong+c*3;
    end;
writeln(f,tong);
close(f);
end.