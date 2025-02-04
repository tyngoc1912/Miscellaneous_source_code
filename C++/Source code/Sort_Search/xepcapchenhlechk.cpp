#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Đếm số nhóm các pt chênh lệch <= k
void solve(){
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a + n);
    int res = 1;
    for(int i = 1; i < n; i++){
        if(a[i] - a[i - 1] <= k) continue;
        res++;
    }
    cout << res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}