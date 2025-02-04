#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Máy photo => binary search on answer
void solve(){
    ll n;
    int x, y;
    cin >> n >> x >> y;
    ll MIN = min(x, y);
    ll l = 0, r = min(x, y) * n;
    ll res = 0;
    while(l <= r){
        ll m = (l + r) / 2;
        ll t1 = m / x;
        ll t2 = m / y;
        if(t1 + t2 >= n - 1){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res + MIN << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}