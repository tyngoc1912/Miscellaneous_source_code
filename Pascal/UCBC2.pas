uses crt;
var m,n,s,bcnn,ucln:integer;

begin
    clrscr;
    textbackground(5);
    readln(m,n);
    bcnn:=m*n;
    writeln;
    while m<>n do
    if m>n then m:=m-n else n:=n-m;
    ucln:=m;
    s:=bcnn div ucln;
    writeln('UCLN ',m);
    writeln('BCNN ',s);
    readln;

end.
