var a,b,st,kq:string; x,y,nho,kt,i,z:byte;  f:text;
begin
{repeat
write('a='); readln(a);
write('b='); readln(b);
until (length(a)<100) and (length(b)<100);  }
assign(f,'Bai1I.inp'); reset(f); readln(f,a); readln(f,b); close(f);
assign(f,'Bai1I.out'); rewrite(f);
if (length(a)<100) and (length(b)<100) then
  begin
  if length(a)>length(b) then fillchar(a,length(a)-length(b),'0')
  else  fillchar(b,length(b)-length(a),'0');
  nho:=0; kq:='';
  for i:=length(a) downto 1 do
      begin
      val(a[i],x,kt); val(b[i],y,kt);
      z:=(nho+x+y) mod 10;
      str(z,st);
      kq:=st+kq;
      nho:=(nho+x+y) div 10;
      end;
   if nho=1 then kq:='1'+kq;
   writeln(f,kq);
   end
 { hieu:=abs(length(a)-length(b));
  if length(a)>length(b) then for i:=1 to hieu do b:='0'+b
  else for i:=1 to hieu do a:='0'+a;
  writeln(f,a,b);
  nho:=0; kq:='';
  for i:=length(a) downto 1 do
      begin
      val(a[i],x,kt); val(b[i],y,kt);
      z:=(nho+x+y) mod 10;
      str(z,st);
      kq:=st+kq;
      nho:=(nho+x+y) div 10;
      end;
  if nho=1 then kq:='1'+kq;
  writeln(f,kq);
  end }
else writeln(f,'k phu hop');
//readln;
close(f);
end.
