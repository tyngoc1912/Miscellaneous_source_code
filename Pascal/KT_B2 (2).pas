var tong,x,kt,i,dem:integer; s:string; k,a:char;
begin
repeat
write('s='); readln(s);
until length(s)<=100;
write('k='); readln(k);
repeat
write('chu cai='); readln(a);
until (a in ['a'..'z']) or (a in ['A'..'Z']);
{tong:=0; i:=1;
while i<length(s) do
    begin
    while s[i] in ['0'..'9'] do begin val(s[i],x,kt); tong:=tong+x; inc(i); end;
    inc(i);
    end;}
tong:=0;
for i:=1 to length(s) do
   if s[i] in ['0'..'9'] then begin val(s[i],x,kt); tong:=tong+x; end;
writeln('Tong cac ktu so la:',tong);
dem:=0;
for i:=1 to length(s) do if s[i]=k then inc(dem);
writeln('so ktu ',k,' la:',dem);
while pos(a,s)>0 do delete(s,pos(a,s),1);
writeln(s);
readln;
end.
