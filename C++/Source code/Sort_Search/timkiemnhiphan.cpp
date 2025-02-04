#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool BinarySearch(int a[], int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x) return true;
        else if(a[m] > x) l = m + 1;
        else r = m - 1;
    }
    return false;
}

void solve(){
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    int t; cin >> t;
    while(t--){
        int tmp; cin >> tmp;
        if(BinarySearch(a, n, tmp)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}