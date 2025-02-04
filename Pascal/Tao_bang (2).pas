var i,dem:longint;
begin
dem:=0;
for i:=1 to 100 do
   begin
   write(i,'   ');
   inc(dem);
   if dem mod 5=0 then writeln;
   end;
readln;
end.