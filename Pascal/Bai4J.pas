var tam,st,a:string; tong,so,i,kt:integer;
begin
readln(st);
i:=1;
a:='';
tong:=0;
while i<length(st) do
     begin
     while st[i] in ['0'..'9'] do begin a:=a+st[i]; inc(i); end;
     if a<>'' then
             begin
             val(a,so,kt); writeln(so); tong:=tong+so; a:='';
             end;
     inc(i);
     end;
{for i:=1 to length(tam) do
    if tam[i] in ['0'..'9'] then a:=a+tam[i];
    if (tam[i] in ['0'..'9']) and (not(tam[i+1] in ['0'..'9'])) then begin val(a,so,kt); tong:=tong+so; writeln(so); a:=''; end;}
writeln(tong);
readln;
end.