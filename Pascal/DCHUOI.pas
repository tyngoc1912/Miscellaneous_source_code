var i:longint;
    dema,demtu:integer;
    st:string;
    f:text;
begin
assign(f,'D:\A0PC2019\DCHUOI.INP');reset(f);
read(f,st); close(f);
dema:=0; demtu:=1;
for i:=1 to length(st) do
 begin
   if st[i]='a' then inc(dema);
   if st[i]=#32 then inc(demtu);
 end;
assign(f,'D:\A0PC2019\DCHUOI.OUT'); rewrite(f);
writeln(f,dema);
write(f,demtu); close(f);
end.