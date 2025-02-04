uses crt;
var s:real;
    i,n:integer;

begin
 clrscr;
 write('Nhap so N: '); readln(n);
 s:=0;
 for i:=1 to n do s:=s+i/(i+1);
 writeln('Tong S1 = ',s:0:2);
 readln;
end.
