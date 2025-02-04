//vct giai phuong trinh bac nhat//
uses crt;
var a,b:integer;

begin
clrscr;
write('a= '); readln(a);
write('b= '); readln(b);
if a<>0 then writeln('Phuong trinh co nghiem la = ',-b/a:0:3)
else if b=0 then writeln('Phuong trinh co vo so nghiem')
     else writeln('Phuong trinh co vo nghiem');
readln;
end.
