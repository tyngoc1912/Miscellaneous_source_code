#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//sàng số nguyên tố --> kt nhiều lần trong 1 khoảng n<=10^7
const int k = 100000;
bool nt[k + 1];
void sang(){
    //cho tất cả các giá trị bằng true
    for(int i = 0; i <= k; i++){
        nt[i] = true;
    }
    //cho số 0 và 1 false
    nt[0] = nt[1] = false;

    //kt số nào là nguyên tố
    for(int i = 2; i <= sqrt(k); i++){
        if(nt[i]){
            //loại tất cả các bội < n của nó
            for(int j = i*i; j <= k; j += i){ 
            // j phải bắt đầu từ bình phương của số nguyên tố sau đó tăng bước nhảy lên i lần
                nt[j] = false;
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
    int dem = 0;
    sang();
    for(int i = 2; i <= sqrt(n); i++){
        if(nt[i] && 1ll * i * i <= n){
            cout << 1ll * i * i << ' ';
            dem++;
        }
    }
    cout << endl;
    cout << dem;
}