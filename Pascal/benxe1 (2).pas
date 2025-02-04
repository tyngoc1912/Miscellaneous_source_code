const fi='benxe1.inp';
      fo='benxe1.out';
type xe=record
     di,den:byte;
     so:word;
end;

var i,n,x,j,tong:byte; f:text; a:array[1..20] of xe; b:array[1..23] of byte; st,s:string;

begin
assign(f,fi); reset(f); readln(f,n);
for i:=1 to n do readln(f,a[i].so,a[i].den,a[i].di); readln(f,x); close(f);
assign(f,fo); rewrite(f);
tong:=0;
j:=0;
for i:=1 to n do
    if (a[i].den<=x) and (a[i].di>=x) then
    begin
    inc(j);
    inc(tong);
    b[j]:=a[i].so;
    end;

writeln(f,tong);
for i:=1 to j do
write(f,b[i],' ');
{for i:=0 to 23 do b[i]:=0;
for i:=1 to n do
    for j:=a[i].den to a[i].di do b[j]:=b[j]+1;}

close(f);
end.
