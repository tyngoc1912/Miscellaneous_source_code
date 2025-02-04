#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//suffix and query
void query(){
    int n; cin >> n;
    int a[n]; 
    for(int &x : a) cin >> x;
    set<int> se;
    int dp[n - 1];
    //duyệt ngược lại vs mỗi dp[i] = se.size() => số lượng pt từ i -> n - 1;
    for(int i = n - 1; i >= 0; i--){
        se.insert(a[i]);
        dp[i] = se.size();
    }
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        cout << dp[x] << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    query();
}