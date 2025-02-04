var  n,i,j,tong:longint; a:array[1..100] of integer; f:text;
begin
{repeat write('n='); readln(n); until (n>=1) and (n<=1000000000);}
assign(f,'Bai5H.inp'); reset(f); readln(f,n); close(f);
assign(f,'Bai5H.out'); rewrite(f);
if (n>=1) and (n<=1000000000) then
    begin
a[1]:=1; a[2]:=4; a[3]:=6; a[4]:=3;
j:=0;
if n>4 then for i:=5 to n do begin j:=j+1; a[i]:=a[j]; end;
for i:=1 to n do tong:=tong+a[i];
writeln(f,tong);
    end
else writeln(f,'k phu hop');
//readln;
close(f);
end.
