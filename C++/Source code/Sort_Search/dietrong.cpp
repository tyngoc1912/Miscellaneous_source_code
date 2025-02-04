#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//diệt rồng
void solve(){
    int n, s; cin >> n >> s;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(s <= a[i].first){
            cout << "NO\n";
            return;
        }
        else s += a[i].second;
    }
    cout << "YES\n";
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}