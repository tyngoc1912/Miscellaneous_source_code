#include <bits/stdc++.h>
using namespace std;

class Ve{
protected:
    int Gia;
    int SoDoAn, SoThucUong;
public:
    void Nhap() {
        cout << "Nhap vao so do an: ";
        cin >> SoDoAn;
        cout << "Nhap vao so thuc uong: ";
        cin >> SoThucUong;
    }
    int getGia() {
        return Gia;
    }
    int getSoDoAn() {
        return SoDoAn;
    }
    int getSoThucUong() {
        return SoThucUong;
    }
    virtual bool LaVeSV() {
        return false;
    }
    virtual bool LaVeThuong() {
        return false;
    }
    virtual void TinhGiaVe() = 0;
};

class VeCombo : public Ve {
public:
    void TinhGiaVe() {
        Gia = 200000;
    }
};

class VeThuong : public Ve {
public:
    bool LaVeThuong() {
        return true;
    }
    void TinhGiaVe() {
        Gia = 60000 + 30000 * (SoDoAn + SoThucUong);
    }
};

class VeSV : public Ve {
public:
    bool LaVeSV() {
        return true;
    }
    void TinhGiaVe() {
        Gia = 30000 + 30000 * (SoDoAn + SoThucUong);
    }
};


int main() {
    int n, sum = 0, cnt = 0, tmp = 0;
    double avg = 0;

    cout <<"Nhap vao so ve: ";
    cin >> n;
    Ve** ds = new Ve*[n];
    for(int i = 0; i < n; i++) {
        int tmp;
        cout <<"1:Ve combo\n2:Ve thuong\n3:Ve sinh vien\nChon loai ve: ";
        cin >> tmp;

        if(tmp == 1) {
            ds[i] = new VeCombo();
        }
        else if(tmp == 2) {
            ds[i] = new VeThuong();
        }
        else ds[i] = new VeSV();

        ds[i]->Nhap();
        ds[i]->TinhGiaVe();
    }
    for(int i = 0; i < n; i++) {
        if(ds[i]->LaVeSV()) {
            sum+=ds[i]->getGia();
        }
    }
    cout << "Tong so tien ve sinh vien da ban la: " << sum << endl;;
    for(int i = 0; i < n; i++) {
        if(ds[i]->LaVeThuong()) {
            cnt++;
            tmp += ds[i]->getSoDoAn() + ds[i]->getSoThucUong();
        }
    }
    if(cnt != 0) avg = tmp * 1.0 / cnt;
    cout << "Trung binh moi ve thuong khach hang se mua " << avg <<" phan do an va thuc uong.";
}
