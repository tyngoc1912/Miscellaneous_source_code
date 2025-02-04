#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Checkin sân bay
void solve(){
    int n; cin >> n;
    pair<int, int> a[n];
    for(auto &x : a) cin >> x.first >> x.second;
    sort(a, a + n);
    ll time = 0;
    for(int i = 0; i < n; i++){
        time = max(1ll * a[i].first, time) + a[i].second; // tìm ra thời điểm bắt đầu của người tiếp theo + thời gian cần để thực hiện
    }
    cout << time << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}