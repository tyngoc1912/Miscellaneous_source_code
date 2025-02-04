var ten,st:string; tu,i:integer;
begin
write('ten='); readln(ten);
tu:=0;
st:='';
for i:=1 to length(ten) do if ten[i]=#32 then inc(tu);
for i:=length(ten) downto 1 do
   if ten[i]<>#32 then st:=ten[i]+st else break;
inc(tu);
writeln('ten co ',tu,' tu');
writeln(st);
readln;
end.
