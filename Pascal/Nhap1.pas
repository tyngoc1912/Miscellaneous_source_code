uses crt;
var S,N:integer;

begin
        clrscr;
        readln(N);
        S:=0;
        S:=S+N mod 10;
        N:=N div 10;
        S:=S+N mod 10;
         N:=N div 10;
        S:=S+N mod 10;
         N:=N div 10;
        S:=S+N mod 10;
        Writeln('Tong cac chu so la = ',S);
        readln;
end.
