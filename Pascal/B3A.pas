var  x,y,i,d,d1:byte;

function ktcp(x:integer):boolean;
begin
ktcp:=false;
if (x>0) and (frac(sqrt(x))=0) then exit(true);
end;

begin
repeat
readln(x,y);
until (x>=0) and (y>=100) and (x<100) and (y<200);
d:=0;
d1:=0;
for i:=x to y do
   if (not(odd(i))) and (i mod 3=0) then
      begin
      write(i,' '); inc(d);
      end;
writeln;
writeln('co ',d,' so');
for i:=x to y do
   if (ktcp(i)) and (x<i) and (i<y) then
      begin
      write(i,' '); inc(d1);
      end;
writeln;
writeln('co ',d1,' so');
readln;
end.
