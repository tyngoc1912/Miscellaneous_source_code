uses crt;
var a,b,c:integer;
    max,min:longint;

begin
        clrscr;
        write('Nhap ba so: '); readln(a,b,c);
        max:=a; min:=a;
        if b>max then max:=b;
        if c>max then max:=c;
        if b<min then min:=b;
        if c<min then min:=c;
        writeln('So lon nhat la: ',max);
        writeln('So nho nhat la: ',min);
        readln;
end.