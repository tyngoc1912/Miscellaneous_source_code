var n,tam,tong,nut:longint; f:text;
begin
//repeat
//write('n='); readln(n);
//until (n>=10000) and (n<=99999);
assign(f,'SOXE.inp'); reset(f); readln(f,n); close(f);
tam:=n;
tong:=0;
while tam>0 do
    begin
    tong:=tong+tam mod 10;
    tam:=tam div 10;
    end;
nut:=tong mod 10;
//writeln('Nut so xe=',nut);
//if (nut=7) or (nut=9) then writeln('so dep')
//else if (nut=1) or (nut=0) then writeln('ko dep')
//else writeln('binh thuong');
//case nut of
//7,9:writeln('dep');
//1,0:writeln('ko dep');
//else writeln('binh thuong');
//end;
assign(f,'SOXE.out'); rewrite(f); writeln(f,nut);
case nut of
7,9:writeln(f,'dep');
1,0:writeln(f,'ko dep');
else writeln(f,'binh thuong');
end;
//readln;
close(f);
end.