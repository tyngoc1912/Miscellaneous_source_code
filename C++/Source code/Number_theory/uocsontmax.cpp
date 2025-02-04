#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//ước nguyên tố lớn nhất
ll uocMax(ll n){
    ll res;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            res = i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) res = n;
    return res;
}

void Check(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cout << uocMax(n) << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    Check();
}


