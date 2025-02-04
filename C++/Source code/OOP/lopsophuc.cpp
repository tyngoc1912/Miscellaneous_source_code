#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SoPhuc {
private:
    float a, b;
public:
        // constructor
    SoPhuc(){}
    SoPhuc(int c, int d): a(c), b(d){}
    SoPhuc(SoPhuc* SoPhuc) : a(SoPhuc->a), b(SoPhuc->b){}

    int absolute(){
        return sqrt(a * a + b * b);
    }

        // overload the >> operator (std::cin object)
    friend istream& operator >> (istream& in, SoPhuc& other) {
        in >> other.a >> other.b;
        return in;
    }

        //overload the << operator (std::cout object)
    friend ostream& operator << (ostream& out, SoPhuc other) {
        out << other.a;
        if(other.b >= 0) {
            out << "+" << other.b << "i" << endl; 
        }
        else if(other.b < 0){
            out << other.b << "i" << endl;
        }
        return out;
    }
        //Cách 1 ko dùng hàm friend
    soPhuc operator + (soPhuc other){
        soPhuc tong;
        tong.a = this->a + other.a;
        tong.b = this->b + other.b;
        return tong;
    }
    //Khi nạp chồng toán tử so sánh rồi => sort() ko cần viết cmp mà nó sẽ tự sort theo toán tử nạp chồng
    bool operator < (soPhuc other){
        return sqrt(this->a * this->a + this->b * this->b) > sqrt(other.a * other.a + other.b * other.b);
    }

    //Cách 2 dùng hàm friend
    friend SoPhuc operator + (SoPhuc x, SoPhuc y) {
        SoPhuc res;
        res.a = x.a + y.a;
        res.b = x.b + y.b;
        return res;
    }

    friend SoPhuc operator - (SoPhuc x, SoPhuc y) {
        SoPhuc res;
        res.a = x.a - y.a;
        res.b = x.b - y.b;
        return res;
    }

    friend SoPhuc operator * (SoPhuc x, SoPhuc y) {
        SoPhuc res;
        res.a = x.a * y.a - x.b * y.b;
        res.b = x.a * y.b + y.a * x.b;
        return res;
    }

    friend SoPhuc operator / (SoPhuc x, SoPhuc y) {
        SoPhuc res;
        int POW = y.a * y.a + y.b * y.b;
        res.a = 1.0 * (x.a * y.a + x.b * y.b) / POW;
        res.b = 1.0 * (x.b * y.a - x.a * y.b) / POW;
        return res;
    }

        // destructor
    ~SoPhuc() {
        a = 0;
        b = 0;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    
    SoPhuc* x = new SoPhuc;
    cin >> *x;
    
    SoPhuc* y = new SoPhuc;
    cin >> *y;
    
    cout << "{+} " <<*x + *y << '\n';
    cout << "{-} " <<*x - *y << '\n';
    cout << "{*} " <<*x * *y << '\n';
    cout << "{/} " <<*x / *y << '\n';
}
