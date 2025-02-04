uses crt;
var s,i,n:integer;

begin
    clrscr;
    readln(n);
    s:=0;
    for i:=1 to n do
     begin
     if i mod 2<>0 then S:=s+i;
     end;
    writeln(S);
    readln;

end.
