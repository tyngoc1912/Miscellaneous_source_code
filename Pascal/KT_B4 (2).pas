var  m,n,k,bcnn:integer;

function ucln(a,b:integer):integer;
begin
while a<>b do if a>b then a:=a-b else b:=b-a;
ucln:=a;
end;

begin
repeat
write('n='); readln(n);
write('m='); readln(m);
write('k='); readln(k);
until (n>0) and (m>0) and (k>0) and (m<n) and (k<n);
bcnn:=(m*k) div ucln(m,k);
writeln('so lan ban Nam va Lan truc cung nhau la: ',n div bcnn);
readln;
end.