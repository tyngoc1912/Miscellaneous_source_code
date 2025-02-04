#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int inSNTmin(ll n){
    if(n == 1) return 1;//nếu n = 1
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return i;
    }// ước nguyên tố min
    return n; //n là số nguyên tố
}

//sàng ước số nguyên tố nhỏ nhất -> nhanh hơn
int prime[1000001];
void sang2(){
    for(int i = 1; i <= 1000000; i++) prime[i] = i; // coi mỗi số là 1 ước SNT nhỏ nhất của chính nó
    for(int i = 2; i <= sqrt(1000000); i++){
        if(prime[i] == i){ // i là SNT
            for(int j = i * i; j <= 1000000; j += i){ // duyệt bội của i
                if(prime[j] == j){//tránh bị trùng vd như 12 = 2^2 * 3 -> cập nhập số 2 ko cập nhập só 3
                    prime[j] = i;// ước NT nhỏ nhất của j là i
                }
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    sang2();
    for(int i = 1; i <= n; i++){
        cout << inSNTmin(i) << endl;
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        cout << prime[i] << endl;
    }
}