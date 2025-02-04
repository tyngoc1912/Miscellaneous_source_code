//vct nhap so nguyen m,n
//a) Xuat ra cac uoc m,n
//b) Xuat ra cac UC m,n
//c) Xuat ra UCLN m,n
//d) Xuat ra BCNN m,n

uses crt;
var m,n,i:integer;

begin
    clrscr;
    readln(m);
    for i:=1 to m do
     if m mod i =0 then write(i:3,' ');
     writeln;
     readln(n);
    for i:=1 to n do
     if n mod i =0 then write(i:3,' ');
    readln;
end.
