var st,tu,stt:string;  i,vt,dem:integer;

function ktdx(st:string):boolean;
var i:integer;
begin
ktdx:=false;
for i:=1 to length(st) div 2 do
    if st[i]<>st[length(st)-i+1] then exit;
ktdx:=true;
end;

begin
readln(st);
for i:=1 to length(st) do st[i]:=upcase(st[i]);
stt:=st+#32; tu:=''; dem:=0;
while stt<>'' do
    begin
    vt:=pos(#32,stt);
    tu:=copy(stt,1,vt-1);
    if ktdx(tu)=true then inc(dem);
    delete(stt,1,vt);
    end;
writeln('so tu doi xung la ',dem);
readln;
end.
