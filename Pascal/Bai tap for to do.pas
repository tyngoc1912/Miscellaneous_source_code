//vct nhap vao 1 so nguyen n va tinh//
//a) S1=1+2+3+4+...+n//
//b) S2=1+3+5+...+n neu n le//
   //S2=2+4+6+...+n neu n chan//

uses crt;
var i,min,ucln,m,n:integer;

begin
    clrscr;
    readln(n,m);
    if m<n then min:=m else min:=n;
    for i:=min downto 1 do if (n mod i=0) and (m mod i=0) then
           begin
           ucln:=i;
           break;
           end;
    writeln(ucln);
    readln;
end.
