var x,y,i:byte; dem1,dem2:longint;

function ktcp(n:longint):boolean;
begin
ktcp:=false;
if (n>=0) and (frac(sqrt(n))=0) then exit(true);
end;

begin
repeat
readln(x);
until (x>=0) and (x<100);
repeat
readln(y);
until (y>=100) and (y<200);
dem1:=0; dem2:=0;
for i:=x to y do
   if (not(odd(i))) and (i mod 3=0) then
       begin
       write(i,' ');
       inc(dem1);
       end;
writeln;
writeln(dem1);
for i:=x to y do
   if (ktcp(i)=true) and ((i>x) and (i<y)) then
       begin
       write(i,' ');
       inc(dem2);
       end;
writeln;
writeln(dem2);
readln;
end.
