var n,tam:int64; i,sl:longint; kt:boolean;
    a:array[1..100] of integer;
    f:text;
begin
//write('n='); readln(n);
assign(f,'SBT.inp'); reset(f); readln(f,n); close(f);
i:=0; tam:=n;
while tam>0 do
   begin
   i:=i+1;
   a[i]:=tam mod 10;
   tam:=tam div 10;
   end;
sl:=i;
kt:=true;
for i:=1 to sl-1 do
   if a[i]<=a[i+1] then
     begin
     kt:=false;
     break;
     end;
//writeln(kt);
assign(f,'SBT.out'); rewrite(f); writeln(f,kt);
close(f);
end.