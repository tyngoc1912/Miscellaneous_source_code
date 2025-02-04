#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Kiểm tra trong mảng có cặp số mà hiệu = k ko
bool check(int a[], int l, int r, int x){
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x) return true;
        else if(a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return false;
}
void solve(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a + n);
    bool ok;
    ll res = 0;
    for(int i = 0; i < n; i++){
        if(check(a, i + 1, n - 1, k + a[i])){
            ok = true;
            break;
        }
    }
    if(ok) cout << 1 << endl;
    else cout << -1 << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}