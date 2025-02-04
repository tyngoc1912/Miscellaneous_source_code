//NhanVien.h
#pragma once
class NhanVien
{
protected:
	char HoTen[20];
	int NS, TS, NaS;
	float Luong;
	float LuongCoBan;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual float TinhLuong();
	char* LayHoTen();
};
//NhanVien.cpp
#include "NhanVien.h"
#include "iostream"
#include <conio.h>
using namespace std;
void NhanVien::Nhap()
{
	cout << "\nNhap Ho Ten";
	cin.ignore();
	cin.getline(HoTen, 20);
	cout << "\nNhap ngay thang nam sinh";
	cin >> NS >> TS >> NaS;
	cout << "\nNhap Luong co ban";
	cin >> LuongCoBan;
}
void NhanVien::Xuat()
{
	cout << "\nHo ten: ";
	puts(HoTen);
	cout << "\nNgay thang nam sinh:";
	cout << NS << "/" << TS << "/" << NaS;
	cout << "\nLuong co ban=";
	cout << LuongCoBan;
	cout << "\nLuong =";
	cout << Luong;
}
char* NhanVien::LayHoTen()
{
	return HoTen;
}
float NhanVien::TinhLuong()
{
	return 0;
}

//NVSanXuat.h
#pragma once
#include "NhanVien.h"
class NVSanXuat :public NhanVien
{
private:
	int SoSanPham;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
};

//NVSanXuat.cpp
#include "NVSanXuat.h"
#include "NhanVien.h"
#include "iostream"
using namespace std;
void NVSanXuat::Nhap()
{
	NhanVien::Nhap();
	cout << "\nNhap so san pham";
	cin >> SoSanPham;
}
void NVSanXuat::Xuat()
{
	NhanVien::Xuat();
	cout << "\nSo san pham" << SoSanPham;
}
float NVSanXuat::TinhLuong()
{
	Luong = LuongCoBan + SoSanPham * 2000;
	return Luong;
}
//NVVanPhong.h
#pragma once
#include "NhanVien.h"
class NVVanPhong :public NhanVien
{
private:
	int SoNgayLamViec;
	float TroCap;
public:
	void Nhap();
	void Xuat();

	float TinhLuong();
};

//NVVanPhong.cpp
#include "NVVanPhong.h"
#include "iostream"
using namespace std;
void NVVanPhong::Nhap()
{
	NhanVien::Nhap();
	cout << "\nNhap so ngay lam viec";
	cin >> SoNgayLamViec;
	cout << "\nNhap tro cap";
	cin >> TroCap;
}
void NVVanPhong::Xuat()
{
	NhanVien::Xuat();
	cout << "\nSo ngay lam viec" << SoNgayLamViec;
	cout << "\nTro cap" << TroCap;
}
float NVVanPhong::TinhLuong()
{
	Luong = LuongCoBan + SoNgayLamViec * 100 + TroCap;
	return Luong;
}
//NVQuanLy.h
#pragma once
#include "NhanVien.h"
class NVQuanLy :public NhanVien
{
private:
	float HeSoChucVu;
	float Thuong;
public:
	void Nhap();
	void Xuat();
	float TinhLuong();
};
//NVQuanLy.cpp
#include "NVQuanLy.h"
#include "NhanVien.h"
#include "iostream"
using namespace std;

void NVQuanLy::Nhap()
{
	NhanVien::Nhap();
	cout << "\nNhap he so chuc vu";
	cin >> HeSoChucVu;
	cout << "\nNhap thuong";
	cin >> Thuong;
}
void NVQuanLy::Xuat()
{
	NhanVien::Xuat();
	cout << "\nHe so chuc vu" << HeSoChucVu;
	cout << "\nThuong" << Thuong;
}
float NVQuanLy::TinhLuong()
{
	Luong = LuongCoBan*HeSoChucVu + Thuong;
	return Luong;
}

//Main.cpp
#include "iostream"
#include <conio.h>
#include <stdio.h>
#include "NhanVien.h"
#include "NVQuanLy.h"
#include "NVSanXuat.h"
#include "NVVanPhong.h"
using namespace std;
void main()
{
	NhanVien *A[50];
	int i, n, t;
	cout << "Nhap so nhan vien";
	cin >> n;
	for (i = 0; i<n; i++)
	{
		cout << "\nChon \n 1 de nhap Nhan vien van phong";
		cout << "\n 2 de nhap Nhan vien san xuat ";
		cout<<"\n 3 de nhap Nhan vien quan ly";
		cin >> t;
		switch (t)
		{
		case 1: A[i] = new NVVanPhong();
			break;
		case 2: A[i] = new NVSanXuat();
			break;
		case 3: A[i] = new NVQuanLy();
			break;
		}
		A[i]->Nhap();

	}
	float TongLuong = 0;
	for (i = 0; i<n; i++)
		TongLuong += A[i]->TinhLuong();
	cout << "\nTong luong=" << TongLuong;
/*
char strHoTen[20];
cout << "\nNhap ten nhan vien can tim";
//fflush(stdin);
//gets_s(strHoTen);
for (i = 0; i<n; i++)
if (strcmp(strHoTen, A[i]->LayHoTen()) == 0)
A[i]->Xuat();

*/
}