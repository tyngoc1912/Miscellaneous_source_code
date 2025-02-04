var x,giay,phut1,phut2,gio:longint;
begin
readln(x);
giay:=x mod 60;
phut1:=x div 60;
gio:= phut1 div 60;
phut2:= phut1 mod 60;
writeln('TG la:',gio,' gio ',phut2,' phut ',giay,' giay');
readln;
end.
