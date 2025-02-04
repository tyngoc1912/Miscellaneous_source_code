#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Xếp domino => Binary search on answer
void solve(){
    ll a, b, n; cin >> a >> b >> n;
    ll l = 0, r = max(a, b) * n;
    ll res = 0;
    while(l <= r){
        ll m = (l + r) / 2;
        ll x = m / a;
        ll y = m / b;
        if(x * y >= n){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res << endl;
} 

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}