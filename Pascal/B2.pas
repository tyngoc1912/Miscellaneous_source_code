var n:integer;

function ktcp(x:longint):boolean;
begin
ktcp:=false;
if (x>=0) and (frac(sqrt(x))=0) then exit (true);
end;

begin
repeat
write('nhap n=');readln(n);
until (n>=0) and (n<=9999);

if odd(n) then writeln('n la so le') else writeln('n la so chan');
if n mod 3 =0 then writeln('n chia het cho 3') else writeln('n khong chia het cho 3');
if ktcp(n)=true then writeln('n la so chinh phuong') else writeln('n khong phai la so chinh phuong');
readln;
end.
