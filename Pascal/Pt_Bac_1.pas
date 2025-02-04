var a,b:longint;
begin
readln(a,b);
if a<>0 then writeln('PT co nghiem la: ',-b/a:0:1)
else if b=0 then writeln('PT vo so nghiem')
     else writeln('PT vo nghiem');
readln;
end.