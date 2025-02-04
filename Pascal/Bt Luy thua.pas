uses crt;
var N,s,i:longint;

begin
        clrscr;
        write('Nhap so N: '); readln(N);
        writeln('Luy thua tu 1 den ',N);
        s:=1;
        for i:=1 to N do writeln(i,'^2','=',sqr(i));
        readln;
end.
