uses crt;
var a,b,c,cv,s,p:real;

begin
        clrscr;
        write('Nhap ba canh tam giac: '); readln(a,b,c);
        if (a+b>c) and (a+c>b) and (b+c>a) then
                begin
                 p:=(a+b+c)/2;
                 cv:=p*2;
                 s:=sqrt(p*(p-a)*(p-b)*(p-c));
                 writeln('Day la ba canh cua tam giac');
                 writeln('Chu vi cua hinh tam giac = ',cv:0:2,'cm');
                 writeln('Dien tich cua hinh tam giac = ',s:0:2,'cm^2');
                end
        else writeln('Day khong phai la ba canh cua tam giac');

        readln;
end.
