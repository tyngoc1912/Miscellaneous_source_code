var n,k,i,max,s:int32; a:array[1..10000000] of longint; f:text;

begin
assign(f,'TONGK.INP'); reset(f); read(f,n,k);
for i:=1 to n do read(f,a[i]); close(f);
assign(f,'TONGK.OUT'); rewrite(f);
s:=0;
for i:=1 to k do s:=s+a[i];
max:=s;
for i:=4 to n-k+1 do
    begin
    s:=s+a[i]-a[i-k];
    if s>max then max:=s;
    end;
writeln(f,max);
close(f);
end.
