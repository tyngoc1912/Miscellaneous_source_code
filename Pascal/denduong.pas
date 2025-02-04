var f:text;h1,h2,h3,a,n,x:longint;
begin
assign(f,'denduong.inp');reset(f);
read(f,a,n);close(f);
assign(f,'denduong.out');rewrite(f);
h1:=a-0;
h2:=n-0;
h3:=h2-h1;
if h1=h3 then writeln(f,'0') else
x:=h2 div h1;
if x<=a then dec(x)
 else x:=x-2;
if x>0 then writeln(f,x);
close(f);
end.