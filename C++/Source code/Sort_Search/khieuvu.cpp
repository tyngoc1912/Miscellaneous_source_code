#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//khiêu vũ
void solve(){
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0, res = 0;
    while(i < n && j < m){
        if(a[i] > b[j]){
            res++;
            i++; j++; // tìm cặp tiếp theo
        }
        else i++; // tìm bạn nam nào cao hơn bạn nữ
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