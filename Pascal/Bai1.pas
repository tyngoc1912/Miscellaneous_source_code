var n,i,s1:longint; s2:real;

begin
repeat
readln(n);
until (n>5) and (n<=300);
//cau a
s1:=0;
s2:=0;
for i:=1 to 2*n-1 do
   begin
   if odd(i){i mod 2<>0} then s1:=s1+i;
   if i<=n then s2:=s2+(n*(n+1))/((n+2)*(n+3));
   end;
writeln('a)',s1);
writeln('b)',s2:0:1);
readln;
end.