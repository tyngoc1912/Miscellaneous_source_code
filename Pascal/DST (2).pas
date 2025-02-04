var i,demb,demtu:integer;
    st:string;
    f:text;
begin
//write('st= '); readln(st);
assign(f,'DST.inp'); reset(f);
read(f,st); close(f);
demb:=0; demtu:=1;
for i:=1 to length(st) do
   begin
   if st[i]='b' then inc(demb);
   if st[i]=#32 then inc(demtu);
   end;
assign(f,'DST.out'); rewrite(f);
writeln(f,demb);
write(f,demtu);
close(f);
//writeln('So luong ki tu b la ',demb);
//writeln('So luong tu la ',demtu);
//readln;
end.
