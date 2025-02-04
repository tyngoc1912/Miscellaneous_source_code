var n,i,max,j,k,tong:longint; a:array[1..100] of integer; f:text;

begin
{repeat
write('n='); readln(n);
until (n>1) and (n<=1000);
for i:=1 to n do
    repeat
    write('a[',i,']='); readln(a[i]);
    until (a[i]>-1000) and (a[i]<1000);}
assign(f,'Bai2G.inp'); reset(f); readln(f,n);
for i:=1 to n do read(f,a[i]); close(f);
assign(f,'Bai2G.out'); rewrite(f);
if (n>1) and (n<1000) and (a[i]>-1000) and (a[i]<1000) then
   begin
   max:=-maxlongint;
   for i:=1 to n do
       for j:=i to n do
          begin
          tong:=0;
          for k:=i to j do tong:=tong+a[k];
          if tong>max then max:=tong;
          end;
   writeln(f,max);
   end
else writeln(f,'k phu hop');
//readln;
close(f);
end.
