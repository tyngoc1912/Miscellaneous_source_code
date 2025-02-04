var a,b,c,i,j,k,n:longint;

function kt_ptg(x,y,z:longint):boolean;
begin
kt_ptg:=false;
if (sqr(x)=sqr(y)+sqr(z)) or (sqr(y)=sqr(x)+sqr(z)) or (sqr(z)=sqr(x)+sqr(y))
then kt_ptg:=true;
end;

begin
repeat
write('a='); readln(a);
write('b='); readln(b);
write('c='); readln(c);
write('n='); readln(n);
until (a>0) and (b>0) and (c>0) and (n>0)
   and (a<=10000) and (b<=10000) and (c<=10000) and (n<=10000);
if kt_ptg(a,b,c)=true then writeln('bo 3 ptg') else writeln('ko bo 3 ptg');
writeln('cac bo 3 ptg <= ',n,' la');
for i:=1 to n-2 do
for j:=i+1 to n-1 do
for k:=j+1 to n do
   if kt_ptg(i,j,k)=true then writeln(i,' ',j,' ',k);
readln;
end.





{var
begin
repeat
readln(c);
until (c>0) and (c<10000);
if (sqr(a)=sqr(b)+sqr(c)) or (sqr(b)=sqr(a)+sqr(c)) or (sqr(c)=sqr(b)+sqr(a))
then writeln('bo 3 pytago') else writeln('ko bo 3 pytago');

end.}
