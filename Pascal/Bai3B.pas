var  a,b,c,sdau,scuoi,sgiua:integer;   hieu1,hieu2,kq:integer;
begin
repeat
write('a='); readln(a);
write('b='); readln(b);
write('c='); readln(c);
until (a>=-100) and (b>=-100) and (c>=-100)
      and (a<=100) and (b<=100) and (c<=100);
sdau:=a;
scuoi:=a;
if b<sdau then sdau:=b;
if c<sdau then sdau:=c;
if b>scuoi then scuoi:=b;
if c>scuoi then scuoi:=c;
if (sdau<a)and(a<scuoi) then sgiua:=a else if (sdau<b)and(b<scuoi) then sgiua:=b else sgiua:=c;
kq:=0;
hieu1:=sgiua-sdau;
hieu2:=scuoi-sgiua;
if hieu1=hieu2 then kq:=sdau-hieu1
else if hieu1=2*hieu2 then kq:=sdau+hieu2
     else if 2*hieu1=hieu2 then kq:=scuoi-hieu1
          else writeln('k to hop');
writeln(kq);
readln;
end.
