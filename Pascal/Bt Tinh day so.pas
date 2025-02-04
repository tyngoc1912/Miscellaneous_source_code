uses crt;
var s:real;
    n,i:integer;

begin
 clrscr;
 write('Nhap so N: '); readln(n);
 s:=0;
 for i:=1 to n do
 if n mod 2=0 then s:=s+i*i/(i+1)
 else s:=s+(i+1)/i*i;
 writeln('Tong S3 ',s:0:3);
 readln;
end.
