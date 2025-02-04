//a) Nhap xau-khong qua 100 ki tu[repeat-until]
//           -khong chuan
//b) Xu li cac khoang trang thua
//c) Dem xem xau co bao nhieu ki tu dang so
//d) Xu li ve sau chuan
//e) Tach xau thanh nhieu tu
//f) Xuat dang nghich dao cua xau chuan
var st,kq1,kq2,tu,std:string;
    i,demso,vt:integer;
    f:text;

begin
//cau a
repeat
assign(f,'KTXAU.inp'); reset(f); readln(f,st); close(f);
until length(st)<=100;
//cau b
kq1:=st;
while kq1[1]=#32 do delete(kq1,1,1);
while kq1[length(kq1)]=#32 do delete(kq1,length(kq1),1);
while pos(#32#32,kq1)>0 do delete(kq1,pos(#32#32,kq1),1);
//cau c
kq2:=kq1;
demso:=0;
for i:=1 to length(kq2) do
    if kq2[i] in ['0'..'9'] then inc(demso);
//cau d
for i:=1 to length(kq2) do kq2[i]:=upcase(kq2[i]);
for i:=1 to length(kq2) do
    if kq2[i] in ['A'..'Z'] then kq2[i]:=chr(ord(kq2[i])+32);
kq2[1]:=upcase(kq2[1]);
for i:=1 to length(kq2) do
    if kq2[i]=#32 then kq2[i+1]:=upcase(kq2[i+1]);

assign(f,'KTXAU.out'); rewrite(f);
writeln(f,kq1); writeln(f,demso); writeln(f,kq2);
//cau e
kq2:=kq2+#32;
tu:='';
while kq2<>'' do
    begin
    vt:=pos(#32,kq2);
    tu:=copy(kq2,1,vt-1);
    writeln(f,tu);
    std:=' '+tu+std;
    delete(kq2,1,vt);
    end;
delete(std,1,1);
writeln(f,std);
close(f);

end.
