#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//tìm bán kính nhỏ nhất để đèn lồng phủ sáng hết con phố
void solve(){
    int n, l; cin >> n >> l;
    int a[n];
    for(auto &x : a) cin >> x;
    sort(a, a + n);
    double d = max(a[0] - 0, l - a[n - 1]);
    for(int i = 1; i < n; i++){
        d = max(d, (a[i] - a[i - 1]) / 2.0);
    }
    cout << fixed << setprecision(10) << d << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}