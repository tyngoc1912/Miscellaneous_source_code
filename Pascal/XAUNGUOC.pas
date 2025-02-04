var st,tu,kq:string;
    i:integer;
begin
write('st='); readln(st);
st:=#32+st;
kq:='';
tu:='';
for i:=length(st) downto 1 do
   begin
   if st[i]<>#32 then tu:=st[i]+tu;
   if st[i]=#32 then
      begin
      kq:=kq+tu+' ';
      tu:='';
      end;
   end;
writeln('Xau nguoc la ',kq);
readln;
end.