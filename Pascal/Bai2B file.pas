var a,b,c,i,j,k,n:longint;  f:text;

function kt_ptg(x,y,z:longint):boolean;
begin
kt_ptg:=false;
if (sqr(x)=sqr(y)+sqr(z)) or (sqr(y)=sqr(x)+sqr(z)) or (sqr(z)=sqr(x)+sqr(y))
then kt_ptg:=true;
end;

begin
assign(f,'Bai2B.inp'); reset(f); readln(f,a,b,c,n); close(f);
assign(f,'Bai2B.out'); rewrite(f);
{repeat
write('a='); readln(a);
write('b='); readln(b);
write('c='); readln(c);
write('n='); readln(n);
until (a>0) and (b>0) and (c>0) and (n>0)
   and (a<=10000) and (b<=10000) and (c<=10000) and (n<=10000);}
if (a>0) and (b>0) and (c>0) and (n>0)
   and (a<=10000) and (b<=10000) and (c<=10000) and (n<=10000)
then begin
if kt_ptg(a,b,c)=true then writeln(f,'bo 3 ptg') else writeln(f,'ko bo 3 ptg');
writeln(f,'cac bo 3 ptg <= ',n,' la');
for i:=1 to n-2 do
for j:=i+1 to n-1 do
for k:=j+1 to n do
   if kt_ptg(i,j,k)=true then writeln(f,i,' ',j,' ',k);
     end
else writeln(f,'du lieu k phu hop');
close(f);
//readln;
end.
