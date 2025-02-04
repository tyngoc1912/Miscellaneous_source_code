uses crt;
var m,n,i:longint;

begin
   clrscr;
   write('Nhap so m,n: '); readln(m,n);
   for i:=1 to m do
   if n*i mod m=0 then
   begin
   writeln('BCNN la ',n*i);
   break;
   end;
  readln;
end.
