var a,b,c,d,min:longint;
begin
readln(a,b,c,d);
min:=a;
if b<min then min:=b;
if c<min then min:=c;
if d<min then min:=d;
writeln('GTNN trong 4 so la:',min);
readln;
end.