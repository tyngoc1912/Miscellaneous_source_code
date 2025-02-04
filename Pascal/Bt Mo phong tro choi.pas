uses crt;
var me,computer:string;
begin
textcolor(green);
clrscr;
randomize;
writeln('Chao mung ban den voi tro one two three');textcolor(red);delay(1000);
writeln('Now lets get started!');textcolor(yellow);delay(1000);
writeln('Ban ra cai gi ?');textcolor(blue);delay(1000);
write('Toi ra cai '); readln(me);textcolor(white);delay(100);
if random(3)=0 then computer:='keo';
if random(3)=1 then computer:='bua';
if random(3)=2 then computer:='bao';
writeln('Computer ra cai: ',computer);textcolor(blue);delay(100);
if me=computer then writeln('Hoa nhau')
else if (me='bao') and (computer='keo') then writeln('Toi thua')
else if (me='keo') and (computer='bua') then writeln('Toi thua')
else if (me='bua') and (computer='bao') then writeln('Toi thua')
else if (me='bua') and (computer='keo') then writeln('Toi thang')
else if (me='bao') and (computer='bua') then writeln('Toi thang')
else if (me='keo') and (computer='bao') then writeln('Toi thang');
readln;
end.
