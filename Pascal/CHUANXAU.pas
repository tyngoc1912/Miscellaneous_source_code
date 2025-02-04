var st,kq1,kq2,tu:string;
    i,vt:integer;
    f:text;
begin
assign(f,'CHUANXAU.inp'); reset(f); readln(f,st); close(f);

kq1:=st;
while kq1[1]=#32 do delete(kq1,1,1);
while kq1[length(kq1)]=#32 do delete(kq1,length(kq1),1);
while pos(#32#32,kq1)>0 do delete(kq1,pos(#32#32,kq1),1);

kq2:=kq1;
for i:=1 to length(kq2) do kq2[i]:=upcase(kq2[i]);
for i:=1 to length(kq2) do
   if kq2[i] in ['A'..'Z'] then kq2[i]:=chr(ord(kq2[i])+32);
kq2[1]:=upcase(kq2[1]);
for i:=1 to length(kq2) do
    if kq2[i]=#32 then kq2[i+1]:=upcase(kq2[i+1]);

assign(f,'CHUANXAU.out'); rewrite(f);
writeln(f,st); writeln(f,kq1); writeln(f,kq2);

kq2:=kq2+#32;
while kq2<>'' do
    begin
    tu:='';
    vt:=pos(#32,kq2);
    tu:=copy(kq2,1,vt-1);
    writeln(f,tu);
    delete(kq2,1,vt);
    end;

close(f);
end.
