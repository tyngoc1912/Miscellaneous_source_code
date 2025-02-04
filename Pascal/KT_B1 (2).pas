{1.Viet CT nhap vao 1 so nguyen k(0<k<10^10)
a/In ra man hinh tat ca uoc tu nhien chan cua k
b/In ra man hinh tat ca uoc chinh phuong cua k
c/In ra man hinh tat ca uoc nguyen to cua k
 2.Viet CT nhap 1 chuoi S(k qua 100 ktu)
a/Tinh tong cac ki tu dang so
b/Dem xem trong chuoi S co bn ktu k biet k la 1 ktu trong bang ma Ascci
c/Nhap vao 1 chu cai nao do trong bang chu cai co phan biet in thuong in hoa va xoa sach chu cai trong chuoi S
 3.Viet CT nhap vao 1 day A gom cac con so co do dai do dai toi da khong qua 225 ktu.
xuat ra man hinh cac day con cua A la day lien tuc cac so duoc sap xp theo thu tu tu be den lon.(dai nhat)
A=0125714035679125
xuat 01257
     35679
 4.Hai ban Lan va Nam dc phan cong truc 1 lan.Ban Lan sau k ngay thi truc 1 lan.Ban Nam cu m ngay truc 1 lan.Gia su
 ban dau 2 ban truc cung nhau.Thi sau n ngay 2 ban se co them bao nhieu lan dc truc
 cung nhau
 *du lieu vao m,n,k(0<k,m<n)
 *xuat so lan 2 ban tryc chung
  N=80
  k=6 n=8
  kqua 3}
var i,k:longint;

function ktnt(x:longint):boolean;
var i:longint;
begin
ktnt:=false;
if x<2 then exit;
for i:=2 to trunc(sqrt(x)) do if x mod i=0 then exit;
exit(true);
end;

begin
repeat
write('k='); readln(k);
until (k>0) and (k<10000000000);
write('Cac uoc tu nhien chan cua ',k,' la: ');
for i:=1 to k do
   if (k mod i=0) and (not(odd(i))) then write(i,' ');
writeln;
write('Cac uoc chinh phuong cua ',k,' la: ');
for i:=1 to k do
   if (k mod i=0) and (frac(sqrt(i))=0) then write(i,' ');
writeln;
write('Cac uoc tu nguyen to cua ',k,' la: ');
for i:=1 to k do
   if (k mod i=0) and (ktnt(i)) then write(i,' ');
readln;
end.
