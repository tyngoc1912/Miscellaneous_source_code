#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//vé hòa nhạc
int last(pair<int, int> a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m].second == 0 && a[m].first <= x){
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    if(res != -1 && res != r + 1) a[res].second = 1;
    return res;
}
void solve(){
    int n, m; cin >> n >> m;
    pair<int, int> a[n];
    int b[m];
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = {x, 0};
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a, a + n);
    for(int i = 0; i < m; i++){
        int pos = last(a, 0, n - 1, b[i]);
        if(pos == -1) cout << -1 << endl;
        else cout << a[pos].first << endl;
    }
}
//vé hòa nhạc => cách tối ưu
void solve(){
    int n, m; cin >> n >> m;
    multiset<int> se;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        se.insert(x);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        auto it = upper_bound(se.begin(), se.end(), x);
        if(it != se.begin()){
            --it;
            cout << *it << endl;
            se.erase(it);
        }
        else cout << -1 << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}