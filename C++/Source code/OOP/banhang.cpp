// CẦN ĐƯỢC FIX

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Product{
    string maSP;
    int soNhap;
    string getMa(){
        return maSP;
    }
    void setMa(string t){
        maSP = t;
    }
    int getSoNhap(){
        return soNhap;
    }
    void setSoNhap(int t){
        soNhap = t;
    }
};

int main(){
    cout << "Nhap so luong san pham nhap : ";
    int n; cin >> n;
    cout << endl; 
    Product **p = new Product*[n];
    for(int i = 0; i < n; i++){
        p[i] = new Product();
        cout << "Ma san pham : "; 
        string tmp; cin >> tmp;
        cout << endl;
        cout << "So hang nhap : ";
        int hang; cin >> hang;
        cout << endl; 
        if(i == 0){
            p[i]->setMa(tmp);
            p[i]->setSoNhap(hang);
        }
        for(int j = 0; j < i; j++){
            if(p[j]->getMa() == tmp){
                p[j]->setSoNhap(p[j]->getSoNhap() + hang); 
            }
            else{
                p[i]->setMa(tmp);
                p[i]->setSoNhap(hang);
            }
        }
    }
    int cnt = n;
    while(1){
        cout << "Nhap hang : 1\n";
        cout << "Xuat hang : 2\n";
        cout << "Thoat : 3\n";
        cout << "Chon lua chon : ";
        int q; cin >> q;
        if(q == 1){
            p[cnt] = new Product();
            cout << "Ma san pham : "; 
            string tmp; cin >> tmp;
            cout << endl;
            cout << "So hang nhap : ";
            int hang; cin >> hang;
            cout << endl; 
            for(int j = 0; j < cnt; j++){
                if(p[j]->getMa() == tmp){
                    p[j]->setSoNhap(p[j]->getSoNhap() + hang); 
                }
                else{
                    p[cnt]->setMa(tmp);
                    p[cnt]->setSoNhap(hang);
                }
            }
            cnt++;
            for(int i = 0; i < cnt; i++){
                cout << "Ma san pham : " << p[i]->getMa() << " " << "So luong : " << p[i]->getSoNhap() << endl; 
            } 
        }
        else if(q == 2){
            cout << "Ma san pham : ";
            string tmp; cin >> tmp;
            cout << endl; 
            cout << "So hang xuat : ";
            int hang; cin >> hang;
            cout << endl; 
            for(int j = 0; j < cnt; j++){
                if(p[j]->getMa() == tmp && p[j]->getSoNhap() >= hang){
                    p[j]->setSoNhap(p[j]->getSoNhap() + hang); 
                    break; 
                }
                else if(p[j]->getMa() == tmp && p[j]->getSoNhap() < hang){
                    cout << "Khong du so luong hang \n";
                    break; 
                }
                else if(p[j]->getMa() != tmp){
                    cout << "Khong co hang \n";
                    break;
                }
            }
            for(int i = 0; i < cnt; i++){
                cout << "Ma san pham : " << p[i]->getMa() << " " << "So luong : " << p[i]->getSoNhap() << endl; 
            } 
        }   
        else if(q == 3) break;
    } 
}