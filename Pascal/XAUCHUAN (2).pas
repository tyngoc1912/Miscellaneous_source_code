var i,dkt,demso:integer;
    st,kq:string;
    f:text;
begin
//write('st='); readln(st);
assign(f,'XAUCHUAN.inp'); reset(f); read(f,st); close(f);

demso:=0; dkt:=0;
for i:=1 to length(st) do
  begin
  if st[i] in ['0'..'9'] then inc(demso);
  if st[i]=#32 then inc(dkt);
  end;

kq:=st;
while kq[1]=#32 do delete(kq,1,1);
while kq[length(kq)]=#32 do delete(kq,length(kq),1);
while pos(#32#32,kq)>0 do delete(kq,pos(#32#32,kq),1);

assign(f,'XAUCHUAN.out'); rewrite(f);
writeln(f,demso);   writeln(f,dkt);  write(f,kq); close(f);

//writeln('So luong ki tu dang so la ',demso);
//writeln('So luong khoang trang la ',dkt);
//writeln('Xau ki tu chuan la ',st);
//readln;
end.
