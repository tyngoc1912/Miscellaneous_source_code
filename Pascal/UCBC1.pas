uses crt;
var m,n,i,min:integer;

begin
    clrscr;
    readln(m,n);
    write('UC cua ',m,' va ',n,' la');
    if m<n then min:=n
    else min:=m;
    for i:=1 to min do
     if(m mod i=0) and (n mod i=0) then write(i:3,'');
    readln;
end.
