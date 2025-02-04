uses crt;
var a,x,b:integer;

begin
  clrscr;
  readln(a,b);
  if (a=0) and (b=0) then writeln('phuong trinh co vo so nghiem')
  else if (a=0) and (b<>0) then writeln('phuong trinh co vo nghiem')
       else if (a<>0) then writeln('Phuong trinh co nghiem la : ',-b/a:4:2);
  readln;
end.