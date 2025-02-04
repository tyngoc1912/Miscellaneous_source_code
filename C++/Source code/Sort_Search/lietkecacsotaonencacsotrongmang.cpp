#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//liệt kê các chữ số tạo nên các số trong mảng
void solve(){
    int n; cin >> n;
    set<char> se;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); i++){
            se.insert(s[i]);
        }
    }
    for(auto x : se) cout << x << ' ';
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}