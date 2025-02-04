#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void factorize(ll n){
    if(n == 1){
        cout << 0 << " " << 1 << endl;
        return;
    }
    else{
        int total = 1;
        for(int i = 2; i <= sqrt(n); i++){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            if(cnt != 0){
                cout << i;
                if(cnt > 1) cout << "^" << cnt;
                if(n > i) cout << " * ";
            }
            total *= cnt + 1;
        }
        if(n > 1) cout << n;
        cout << " " << total << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //Phân tích thừa số nguyên tố và Đếm số ước của 1 số nguyên dương
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        factorize(i);
    }
}