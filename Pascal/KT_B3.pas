var a,s:string; i,max,dem:integer; kt:boolean;
begin
repeat
write('a='); readln(a);
kt:=true;
for i:=1 to length(a) do if not(a[i] in ['0'..'9']) then begin kt:=false; break; end;
until (length(a)<=225) and (kt=true);
i:=1; max:=0;
while i<length(a) do
     begin
     dem:=1;
     while (a[i]<a[i+1]) and (i<length(a)) do begin inc(i); inc(dem); end;
     if dem>max then max:=dem;
     inc(i);
     end;
if max>1 then
begin
i:=1; s:='';
while i<length(a) do
     begin
     dem:=1;
     while (a[i]<a[i+1]) and (i<length(a)) do begin s:=s+a[i]; inc(i); inc(dem); end;
     s:=s+a[i];
     if dem=max then writeln(s);
     s:='';
     inc(i);
     end;
end
else writeln('day k tang k giam');
readln;
end.