#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;
    map<char, int> mp;
    for(auto x : s) mp[x]++;
    ll res = s.size();
    for(auto x : mp){
        res += 1ll * x.second * (x.second - 1) / 2;
    }
    cout << res << endl;
}