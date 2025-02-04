#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class PhanSo{
private:
    ll tu, mau;
public:
    PhanSo(){}
    PhanSo(ll a) : tu(a), mau(1){}
    PhanSo(ll a, ll b) : tu(a), mau(b){}
    void nhap();
    void xuat();
    void rutGon();
    friend istream& operator >> (istream& in, PhanSo& a);
    friend ostream& operator << (ostream& out, PhanSo a);
    PhanSo operator + (PhanSo other);
    friend PhanSo operator - (PhanSo a, PhanSo b);
    PhanSo operator * (PhanSo other);
    PhanSo operator / (PhanSo other);
    bool operator == (PhanSo other);
    bool operator > (PhanSo other);
    bool operator < (PhanSo other);
    ~PhanSo(){}
};
void PhanSo::nhap(){
    cin >> this->tu >> this->mau;
}
void PhanSo::xuat(){
    cout << this->tu << "/" << this->mau << endl;
}
void PhanSo::rutGon(){
    ll ucln = __gcd(this->tu, this->mau);
    this->tu /= ucln;
    this->mau /= ucln;
}
istream& operator >> (istream& in, PhanSo& a){
    in >> a.tu >> a.mau;
    return in;
}
ostream& operator << (ostream& out, PhanSo a){
    out << a.tu << "/" << a.mau << endl;
    return out;
}
ll lcm(ll a, ll b){return 1ll * a / __gcd(a, b) * b;}
PhanSo PhanSo::operator + (PhanSo other){
    PhanSo res;
    ll x = lcm(this->mau, other.mau);
    res.tu = 1ll * this->tu * x / this->mau + 1ll * other.tu * x / other.mau;
    res.mau = x;
    res.rutGon();
    return res;
}
PhanSo operator - (PhanSo a, PhanSo b){
    PhanSo res;
    ll x = lcm(a.mau, b.mau);
    res.tu = 1ll * a.tu * x / a.mau - 1ll * b.tu * x / b.mau;
    res.mau = x;
    res.rutGon();
    return res;
}
PhanSo PhanSo::operator * (PhanSo other){
    PhanSo res;
    res.tu = 1ll * this->tu * other.tu;
    res.mau = 1ll * this->mau * other.mau;
    res.rutGon();
    return res;
}
PhanSo PhanSo::operator / (PhanSo other){
    PhanSo res;
    res.tu = 1ll * this->tu * other.mau;
    res.mau = 1ll * this->mau * other.tu;
    res.rutGon();
    return res;
}
bool PhanSo::operator == (PhanSo other){
    return 1.0 * this->tu/this->mau == 1.0 * other.tu/other.mau; 
} 
bool PhanSo::operator > (PhanSo other){
    return 1.0 * this->tu/this->mau > 1.0 * other.tu/other.mau; 
} 
bool PhanSo::operator < (PhanSo other){
    return 1.0 * this->tu/this->mau < 1.0 * other.tu/other.mau; 
} 

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    PhanSo a; 
    cin >> a;
    a.rutGon();
    cout << a;
    PhanSo b(3, 4);
    PhanSo c(2, 5);
    cout << b - c;
    cout << b + c;
    cout << b * c;

    PhanSo* a = new PhanSo;
    PhanSo* b = new PhanSo;

    std::cin >> *a >> *b;
    
    std::cout << "{+} " <<*a + *b << '\n';
    std::cout << "{-} " <<*a - *b << '\n';
    std::cout << "{*} " <<*a * *b << '\n';
    std::cout << "{/} " <<*a / *b << '\n';
}






  
