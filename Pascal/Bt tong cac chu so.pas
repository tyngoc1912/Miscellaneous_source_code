//vct nhap vao 1 so co 4 chu so, xuat ra man hinh tong cac chu so cua so do//

uses crt;
var a,b,c,d,e,N:integer;

begin
   clrscr;
   readln(N);
   a:=N mod 10;
   b:=N div 10;
   c:=a+b mod 10;
   d:=b div 10;
   e:=c+d mod 10+d div 10;
   writeln('Tong cac chu so la = ',e);
   readln;
end.
