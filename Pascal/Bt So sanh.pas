uses crt;
var a,b:integer;

begin
        clrscr;
        write('Nhap 2 so: '); readln(a,b);
        if a>b then writeln('So ',a,' lon hon so ',b) else
        if a<b then writeln('So ',a,' be hon so ',b)
        else writeln('So ',a,' bang so ',b);
        readln;
end.