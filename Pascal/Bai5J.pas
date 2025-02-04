var doben,n:longint;

function tichcs(x:longint):longint;
var tich,so,kt,i:longint; st:string;
begin
if x>9 then
   begin
   str(x,st); tich:=1;
   for i:=1 to length(st) do
       begin
       val(st[i],so,kt); tich:=tich*so;
       end;
   end;
tichcs:=tich;
end;

begin
repeat
write('n='); readln(n);
until (n>=0) and (n<=2000000000);
if n<10 then doben:=0
else begin
     doben:=1;
     while tichcs(n)>9 do begin inc(doben); n:=tichcs(n); end;
     end;
writeln(doben);
readln;
end.