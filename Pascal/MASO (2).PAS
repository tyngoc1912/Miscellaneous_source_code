const fi='MASO.INP';
      fo='MASO.OUT';

var st:string; s,x,i,k,kt:integer; f:text;

begin
//readln(st);
assign(f,fi); reset(f); readln(f,st); close(f);
assign(f,fo); rewrite(f);
s:=0;
for i:=1 to length(st) do
    if st[i] in ['0'..'9'] then
       begin
       val(st[i],x,kt);
       s:=s+x*i;
       end;
for k:=0 to 9 do if (s+pos('*',st)*k) mod 11=0 then begin writeln(f,k); end;
//readln;
close(f);
end.