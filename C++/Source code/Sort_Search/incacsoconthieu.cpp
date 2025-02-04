#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//đếm chữ số còn thiếu trong đoạn [l, r]
int cnt[1000001];
void solve(){
    int n; cin >> n;
    // int a[n];
    // for(auto &x : a) cin >> x;
    int l = INT_MAX, r = INT_MIN;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
        l = min(l, x);
        r = max(r, x);
    } 
    int res = 0;
    vector<int> v;
    for(int i = l; i <= r; i++){
        if(cnt[i] == 0){
            res++;
            v.push_back(i);
        }
    }
    cout << res << endl;
    for(auto x : v) cout << x << ' ';
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}