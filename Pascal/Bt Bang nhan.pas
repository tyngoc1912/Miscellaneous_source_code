uses crt;
var N,i:integer;

begin
        clrscr;
        write('Nhap so N: '); readln(N);
        writeln('Bang nhan ',N);
        for i:=1 to 10 do writeln(N,'x',i,'=',N*i);
        readln;
end.
