var a,b,c,sodau,sogiua,socuoi,hieu1,hieu2:integer;
begin
repeat
readln(a,b,c);
until (a>=-100) and (b>=-100) and (c>=-100) and
      (a<=100) and (b<=100) and (c<=100);
sodau:=a;
socuoi:=a;
if sodau>b then sodau:=b;
if sodau>c then sodau:=c;
if socuoi<b then socuoi:=b;
if socuoi<c then socuoi:=c;
if (a>sodau) and (a<socuoi) then sogiua:=a
else if (b>sodau) and (b<socuoi) then sogiua:=b
     else sogiua:=c;
hieu1:=sogiua-sodau;
hieu2:=socuoi-sogiua;
if hieu1=hieu2 then writeln(sodau-hieu1)
else if hieu1=2*hieu2 then writeln(socuoi-hieu1)
     else if 2*hieu1=hieu2 then writeln(socuoi-hieu1)
          else writeln('k the lap');
readln;
end.
