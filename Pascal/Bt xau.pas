var i:integer;
    st,std: string;
begin
write('st='); readln(st);
for i:=length(st) downto 1 do std:=std+st[i];
write('Xau nguoc la ',std);
readln;
end.
