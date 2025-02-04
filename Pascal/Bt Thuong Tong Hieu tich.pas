uses crt;
var a,b: integer;

begin
        clrscr;
        write('Nhap so a: '); readln(a);
        write('Nhap so b: '); readln(b);
        writeln('Tong cua a va b la = ',a+b);
        writeln('Hieu cua a va b la = ',a-b);
        writeln('Tich cua a va b la = ',a*b);
        writeln('Thuong cua a va b la = ',a/b:4:2);
        readln;
end.