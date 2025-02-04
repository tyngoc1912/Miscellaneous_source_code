{cho so nguyen duong n (3<n<1000000)
a) tinh s=1.2.3+2.3.4+...+(n-2).(n-1).n
b) tinh p= 1/1!+1/3!+1/5!+...+1/n! neu n le
        p= 1/2!+1/4!+1/6!+...+1/n! neu n chan}
var n,i,k:integer; s,gt:int64; p:real;
begin
repeat
write('n='); readln(n);
until (n>=3) and (n<=1000000);
s:=0;
p:=0;
gt:=1;
for i:=1 to n do
   begin
   s:=s+(i-2)*(i-1)*i;
   if odd(n) then
      if odd(i) then
         begin
         for k:=1 to i do gt:=gt*k;
         p:=p+1/gt;
         end;
   if not(odd(n)) then
       if not(odd(i)) then
         begin
         for k:=1 to i do gt:=gt*k;
         p:=p+1/gt;
         end;
   end;
writeln('s=',s);
writeln('p=',p:0:1);
readln;
end.
