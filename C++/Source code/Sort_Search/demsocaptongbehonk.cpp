#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Đếm số cặp các pt có tổng < k
int last(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] < x){
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    return res;
}
void solve(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a + n);
    ll res = 0;
    for(int i = 0; i < n; i++){
        int pos = last(a, i + 1, n - 1, k - a[i]);
        if(pos != -1) res += pos - i;
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