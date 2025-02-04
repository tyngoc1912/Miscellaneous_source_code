var i:integer;

function ktcp(x:integer):boolean;
begin
ktcp:=false;
if (x>=0) and (frac(sqrt(x))=0) then exit(true);
end;

function schuso(x:longint):longint;
var tong:integer;
begin
tong:=0;
while x>0 do
     begin
     tong:=tong+x mod 10;
     x:=x div 10;
     end;
schuso:=tong;
end;

begin
for i:=2000 to 5000 do
    if schuso(i) mod 3=0 then write(i,' ');
writeln;
for i:=1 to 100 do if ktcp(i) then write(i,' ');
readln;
end.
