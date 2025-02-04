var st,st1,st2:string; n,i:integer;

begin
readln(st);
readln(n);
n:=n mod 26;
st1:='';
st2:='';
{for i:=1 to length(st) do
    begin
    if st[i]=#32 then write(#32) else
    if ord(st[i])+n>90 then write(chr(ord(st[i])-26+n))
    else write(chr(ord(st[i])+n));
    end; }
for i:=1 to length(st) do
    begin
    if st[i]=#32 then write(#32) else
    if ord(st[i])-n<65 then write(chr(ord(st[i])+26-n))
    else write(chr(ord(st[i])-n));
    end;

{for i:=1 to length(st1) do
    begin
    if (st[i]<>#32) and (ord(st[i])+n<90) then st2:=st2+chr(ord(st1[i])+26-n)
    else if st[i]<>#32 then st2:=st2+chr(ord(st1[i])-n);
    if st[i]=#32 then write(st2); st2:='';
    end;}
readln;
end.