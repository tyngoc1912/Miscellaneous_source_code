uses crt;
var st,a,kq1,kq2,tu:string;
    i:integer;
    f:text;
begin
//write('st='); readln(st);
assign(f,'MAXXAU.inp'); reset(f); readln(f,st); close(f);

kq1:=st;
while kq1[1]=#32 do delete(kq1,1,1);
while kq1[length(kq1)]=#32 do delete(kq1,length(kq1),1);
while pos(#32#32,kq1)>0 do delete(kq1,pos(#32#32,kq1),1);

kq2:=kq1;
//Chuyen toan bo ve in hoa-Upcase
for i:=1 to length(kq2) do kq2[i]:=upcase(kq2[i]);
//kq2=THCS LE HONG PHONG
//Chuyen toan bo ve ki tu thuong = kthuat Acssi
//Ham ord(ki tu)= 1 con so la vi tri trong ban ma Acssi
//Ham chr(1 con so)= ki tu tuong ung trong Acssi
for i:=1 to length(kq2) do
  if kq2[i] in ['A'..'Z'] then kq2[i]:=chr(ord(kq2[i])+32);
//kq2=thcs le hong phong
//Hoan thien kq2
kq2[1]:=upcase(kq2[1]);
for i:=1 to length(kq2) do
   if kq2[i]=#32 then kq2[i+1]:=upcase(kq2[i+1]);

assign(f,'MAXXAU.out'); rewrite(f);
writeln(f,st); writeln(f,kq1); writeln(f,kq2);

//kq2:=kq2+#32;
//tu:='';
//for i:=1 to length(kq2) do
  //begin
   //if kq2[i]<>#32 then tu:=tu+kq2[i];
   //if kq2[i]=#32 then
    // begin
    // writeln(f,tu);
    // tu:='';
    // end;
 // end;

close(f);

//writeln('Xau chuan 1 la ',kq1);
//writeln('Xau chuan 2 la ',kq2);
//readln;
end.
