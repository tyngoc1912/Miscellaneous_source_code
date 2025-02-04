uses crt;
var a,b,c,d:integer;
    max,min:longint;

begin
        clrscr;
        write('Nhap 4 so: '); readln(a,b,c,d);
        max:=a; min:=a;
        if b>max then max:=b;
        if c>max then max:=c;
        if d>max then max:=d;
        if b<min then min:=b;
        if c<min then min:=c;
        if d<min then min:=d;
        writeln('So lon nhat la: ',max);
        writeln('So nho nhat la: ',min);
        readln;
end.