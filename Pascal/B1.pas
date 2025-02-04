var n,tam,cscuoi,csdau,dem,tong:longint;
begin
repeat
write('n='); readln(n);
until (n>0) and (n<=1000);
tam:=n;
cscuoi:=n mod 10;
dem:=0;
while tam>0 do
     begin
     if (tam>=0) and (tam<=9) then csdau:=tam;
     tong:=tong+tam mod 10;
     dem:=dem+1;
     tam:=tam div 10;
     end;
writeln('so chu so la: ',dem);
writeln('tong cac cs la: ',tong);
writeln('csdau la: ',csdau);
writeln('cscuoi la: ',cscuoi);
readln;
end.