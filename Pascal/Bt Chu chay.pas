uses crt;
var s,i,m,n:integer;
    a,b:string;

begin
clrscr;
readln(a);
readln(b);
for i:=1 to 40 do
  begin
   for s:=1 to i do write(' ');
   write(a);
   delay(50);
   clrscr;
   for n:=80 downto i do write(' ');
   write(b);
   delay(50);
   clrscr;
  end;
  readln;
end.
