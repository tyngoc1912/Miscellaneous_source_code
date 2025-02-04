#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Đếm số cặp các pt chênh lệch = k
int firstPos(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x){
            res = m;
            r = m - 1;
        }
        else if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return res;
}
int lastPos(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x){
            res = m;
            l = m + 1;
        }
        else if(a[m] > x) r = m - 1;
        else l = m + 1;
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
        int p1 = firstPos(a, i + 1, n - 1, k - a[i]);
        int p2 = lastPos(a, i + 1, n - 1, k - a[i]);
        if(p1 != -1) res += p2 - p1 + 1;
    }
    cout << res << endl;
}

//Đếm số cặp các pt chênh lệch = k
//dùng lower_bound và upper_bound
void solve(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a + n);
    int res = 0;
    for(int i = 0; i < n; i++){
        auto it1 = lower_bound(a + i + 1, a + n, k - a[i]);
        auto it2 = upper_bound(a + i + 1, a + n, k - a[i]);
        res += it2 - it1;
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