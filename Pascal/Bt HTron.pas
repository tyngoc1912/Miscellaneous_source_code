uses crt;
var d,r,bk,cvhcn,shcn,cvht,sht:real;
const pi=3.14;

begin
        clrscr;
        Write('Nhap ban kinh: '); readln(bk);
        write('Nhap chieu dai: '); readln(d);
        write('Nhap chieu rong: '); readln(r);
        cvhcn:=(d+r)*2;
        shcn:=d*r;
        cvht:=2*pi*bk;
        sht:=bk*bk*pi;
        writeln('Chu vi HCN = ',cvhcn:0:2,'cm') ;
        writeln('Dien tich HCN = ',shcn:0:2,'cm^2');
        writeln('Chu vi Htron = ',cvht:0:2,'cm');
        writeln('Dien tich Htron = ',sht:0:2,'cm^2');
        readln;
end.