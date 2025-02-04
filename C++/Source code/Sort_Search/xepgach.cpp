#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Xếp gạch
void solve(){
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a + n, greater<int>());
    int limit = a[n - 1];
    int res = 1;
    for(int i = 1; i < n; i++){
        if(a[i] < limit) break;
        else{
            res++;
            limit = min(limit - 1, a[i]);
        }
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