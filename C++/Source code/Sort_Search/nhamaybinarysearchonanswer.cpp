#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//factory machine => Binary search on answer
bool check(ll a[], ll n, ll m, ll t){
    ll cnt = 0;
    for(int i = 0; i < n; i++) cnt += m / a[i];
    if(cnt >= t) return true;
    else return false;
}
void solve(){
    ll n, t; cin >> n >> t;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll res = 0;
    ll l = 0, r = *min_element(a, a + n) * t;
    while(l <= r){
        ll m = (l + r) / 2;
        if(check(a, n, m, t)){
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

