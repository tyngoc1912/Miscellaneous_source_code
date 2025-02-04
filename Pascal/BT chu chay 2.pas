uses crt;
var a,b:string;
    s,i:integer;
begin
clrscr;
readln(a);
readln(b);
for i:=1 to 40-length(a) do
   begin
   gotoxy(i,1); write(a);
   delay(100);
   gotoxy(70-i,1); write(b);
   delay(50);
   clrscr;
   end;
writeln('Day la nhan vo cua em'); delay(1000);
writeln('...');delay(1000);
textcolor(yellow);
writeln('******************************');
write('*');
textcolor(red);
write(' Truong: THCS Le Hong Phong ');
textcolor(yellow);
writeln('*');
write('*');
textcolor(red);
write(' Ten: Nguyen Tran Ngoc Ty   ');
textcolor(yellow);
writeln('*');
write('*');
textcolor(red);
write(' Lop: 8/1                   ');
textcolor(yellow);
writeln('*');
write('*');
textcolor(red);
write(' Tap: Lap trinh Pascal      ');
textcolor(yellow);
writeln('*');
write('*');
textcolor(red);
write(' Nam hoc: 2018-2019         ');
textcolor(yellow);
writeln('*');
writeln('******************************');
readln;
end.
