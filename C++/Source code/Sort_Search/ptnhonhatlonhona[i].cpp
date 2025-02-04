#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Tìm số nhỏ nhất trong mảng lớn hơn a[i]
void solve(){
    int n; cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    } 
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        auto it = upper_bound(a, a + n, b[i]);
        if(it == a + n) cout << "_ ";
        else cout << *it << " ";
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}