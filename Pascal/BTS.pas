var n,i:longint; st:string; kt:boolean; f:text;
begin
//write('n='); readln(n);
assign(f,'BTS.inp'); reset(f); readln(f,n); close(f);
str(n,st);
kt:=true;
for i:=1 to length(st)-1 do
    if st[i]>st[i+1] then kt:=false;
//writeln(kt);
//readln;
assign(f,'BTS.out'); rewrite(f); writeln(f,kt); close(f);
end.
