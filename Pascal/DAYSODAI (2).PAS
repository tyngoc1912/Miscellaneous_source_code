const fi='DAYSODAI.INP';
      fo='DAYSODAI.OUT';

var m,n,i,max,vt:longint;
    tong,st,tbp:string;
    f:text;
    a:array[1..100] of string;

function sbp(x:string):string;
var tong,i,so,kt:longint; st:string;
begin
tong:=0;
for i:=1 to length(x) do begin val(x[i],so,kt); tong:=tong+sqr(so); end;
str(tong,st);
sbp:=st;
end;

begin
assign(f,fi); reset(f); readln(f,m,n); close(f);
assign(f,fo); rewrite(f);
max:=0;
for i:=m to n do
   begin
   tong:='';
   str(i,st);
   tong:=st+' ';
   repeat
   tbp:=sbp(st);
   vt:=pos(#32+tbp+' ',tong);
   tong:=tong+tbp+#32;
   st:=sbp(st);
   until vt>0;
a[i]:=tong;
if length(a[i])>max then max:=length(a[i]);
   end;
for i:=m to n do if length(a[i])=max then
    begin writeln(f,i); write(a[i]); break; end;
close(f);
end.
