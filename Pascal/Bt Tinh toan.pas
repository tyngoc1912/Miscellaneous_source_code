uses crt;
var N,s,i:longint;

begin
        clrscr;
        write('Nhap so N: '); readln(N);
        s:=1;
        for i:=1 to N do S:=s*i;
        writeln(i,'!','=',S);
        readln;
end.