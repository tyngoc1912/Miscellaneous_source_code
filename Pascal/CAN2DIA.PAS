const fi='CAN2DIA.INP';
      fo='CAN2DIA.OUT';
      nmax=100;
      hmax=1000000;
var a:array[1..nmax] of integer; h:array[1..hmax] of boolean;
    n,k,i,j:longint;
    f:text;

begin
assign(f,fi); reset(f); readln(f,n);
for i:=1 to n do read(f,a[i]); close(f);
assign(f,fo); rewrite(f);
fillchar(h,sizeof(h),false);
for i:=1 to n do h[a[i]]:=true;
for i:=1 to n-1 do
    for j:=i+1 to n do h[a[i]+a[j]]:=true;
for i:=1 to n-2 do
    for j:=i+1 to n-1 do
        for k:=j+1 to n do h[a[i]+a[j]+a[k]]:=true;
for i:=1 to hmax do if h[i]=true then write(f,i,' ');
close(f);
end.