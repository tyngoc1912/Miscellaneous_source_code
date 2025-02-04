var n,i,j,tong,k,dem:longint; a:array[1..100] of integer;
begin
readln(n); readln(k);
for i:=1 to n do readln(a[i]);
for i:=1 to n do
    for j:=i to n do
        begin
        tong:=0;
        dem:=0;
        for k:=i to j do begin tong:=tong+a[k]; inc(dem); end;
        if tong mod k=0 then begin writeln(dem); write(i); end;
        end;
readln;
end.
