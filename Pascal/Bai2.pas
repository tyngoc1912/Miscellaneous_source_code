var st,st1:string; i,dem:integer;
begin
repeat
readln(st); st1:=''; dem:=0;
for i:=1 to length(st) do
 begin
 if st[i] in ['0'..'9'] then
    begin
    st1:=st[i]+st1;
    inc(dem);
    end;
 end;
until (dem=9) and (length(st)-dem>=5);
st1:='0'+st1;
writeln(st1);
readln;
end.
