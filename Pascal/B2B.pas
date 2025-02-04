var a,b,c,n,i,k,j:integer;

function ktptg(a,b,c:longint):boolean;
begin
ktptg:=false;
if (sqr(a)=sqr(b)+sqr(c)) or (sqr(b)=sqr(a)+sqr(c)) or (sqr(c)=sqr(b)+sqr(a)) then
exit(true);
end;

begin
repeat
readln(a,b,c,n);
until (a>0) and (b>0) and (c>0) and  (n>0) and (a<10000) and
      (b<10000) and (c<10000) and (n<10000);
if ktptg(a,b,c) then writeln('ptg') else writeln('ko ptg');
writeln('cac bo 3 ptg la ');
for i:=1 to n-2 do
    for k:=i+1 to n-1 do
        for j:=k+1 to n do
            if ktptg(i,k,j) then writeln(i,' ',k,' ',j);
readln;
end.