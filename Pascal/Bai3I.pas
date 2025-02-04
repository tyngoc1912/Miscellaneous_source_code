var st,tu,kq,tam:string; i:integer;
begin
repeat write('st='); readln(st); until length(st)<=225;
kq:='';
tam:=st+#32;
for i:=1 to length(tam) do
    begin
    if tam[i]<>#32 then tu:=tam[i]+tu;
    {if (tam[i] in ['a'..'z']) or (tam[i] in ['A'..'Z']) then tu:=tam[i]+tu
    else tu:=tu+tam[i];}
    if tam[i]=#32 then begin kq:=kq+#32+tu; tu:=''; end;
    end;
delete(kq,1,1);
writeln(kq);
readln;
end.
