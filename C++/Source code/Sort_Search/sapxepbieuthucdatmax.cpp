#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Sắp xếp dãy số và thêm cộng trừ sao cho đạt biểu thức là max
void solve(){
    int n, k; cin >> n >> k;
    int a[n];
    for(auto &x : a) cin >> x;
    ll sum = a[0];
    sort(a + 1, a + n, greater<int>());
    for(int i = 1; i < n; i++){
        if(k > 0) sum += a[i]; // dùng đk i <= k vẫn đc
        else sum -= a[i];
        k--;
    }
    cout << sum << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}