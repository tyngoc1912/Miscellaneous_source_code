var i,n,b:longint; s:string;  f:text;

begin
{repeat
write('n='); readln(n);
until (n>=2) and (n<=10);}
assign(f,'Bai1E.inp'); reset(f); readln(f,n); close(f);
assign(f,'Bai1E.out'); rewrite(f);
if (n>=2) and (n<=10) then
begin
{st:='';
for i:=1 to n do st:=st+'9';
val(st,tam,kt);
for i:=1 to tam div 11 do write(f,i*11,' '); }

{max:=9; x:=9;
for i:=1 to n-1 do
    begin
    x:=x*10;
    max:=max+x;
    end;
for i:=1 to max div 11 do write(f,i*11,' ');}

i:=0;  str(i,s);
writeln(f,'Boi cua 11 la ');
while length(s)<=n do
      begin
      inc(i);
      b:=i*11;
      str(b,s);
      if length(s)<=n then write(f,b,' ');
      end;
end
else writeln(f,'du lieu k phu hop');
close(f);
//readln;
end.
