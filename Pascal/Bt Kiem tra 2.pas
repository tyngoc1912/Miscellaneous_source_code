uses crt;
var x,y,z:real;

begin
        clrscr;
        write('Nhap ba canh tam giac: '); readln(x,y,z);
        if (x+y>z) and (y+z>x) and (x+z>y) then
                begin
                 writeln('Day la ba canh cua tam giac');
                  if (x=y) and (y=z) then writeln('Va day la tam giac deu')
                 else if(x=y) or (y=z) or (z=x) then
                 writeln('Va day la tam giac can')
                 else if (z*z=y*y+x*x) or (x*x=y*y+z*z) or (y*y=x*x+z*z) then
                 writeln('Va day la tam giac vuong')
                 else if (z*z=y*y+x*x) or (x*x=y*y+z*z) or (y*y=x*x+z*z)
                     or (x=y) or (y=z) or (z=x) then
                     writeln('Va day la tam giac vuong can')
                 else writeln('Va day la tam giac thuong');
                end
        else writeln('Day khong phai la ba canh cua tam giac');
        readln;
end.
