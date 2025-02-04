var tram,chuc,dv:integer;
begin
for tram:=1 to 9 do
  for chuc:=0 to 9 do
    for dv:=0 to 9 do
      if (tram*100+chuc*10+dv)=(sqr(tram)*tram+sqr(chuc)*chuc+sqr(dv)*dv)
      then writeln(tram,chuc,dv,'=',tram,'^3+',chuc,'^3+',dv,'^3');
readln;
end.