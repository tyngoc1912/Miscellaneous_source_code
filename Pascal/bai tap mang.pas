uses crt;
var a:array[1..100] of integer;
    n,i,S,Sc,Sl,Sd,Sa,Sbp:integer;
begin
clrscr;
write('N='); readln(n);
for i:=1 to n do readln(a[i]);
//cau a
for i:=1 to n do write(a[i],';','');
writeln;
//cau b
s:=0;
for i:=1 to n do S:=S+a[i];
writeln('Tong=',S);
//cau c
Sc:=0; Sa:=0; Sl:=0; Sd:=0;
for i:=1 to n do
    begin
    if a[i] mod 2=0 then Sc:=Sc+a[i]
    else Sl:=Sl+a[i];
    if a[i]>0 then Sd:=Sd+a[i]
    else Sa:=Sa+a[i];
    end;
 writeln('Tong chan la: ',Sc);
 writeln('Tong le la: ',Sl);
 writeln('Tong duong la: ',Sd);
 writeln('Tong am la: ',Sa);
//cau d
 sbp:=0;
 write('Cac so chia het cho 5 la: ');
 for i:=1 to n do
 if a[i] mod 5=0 then
     begin
     write(a[i],' ');
     Sbp:=Sbp+sqr(a[i]);
     end;
     writeln;
 writeln('Tong binh phuong la: ',Sbp);
readln
end.
