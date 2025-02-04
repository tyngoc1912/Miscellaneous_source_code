#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;
    string t = "python";
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(cnt >= 6) break;
        if(s[i] == t[cnt]) cnt++;
    }
    if(cnt == 6) cout << "YES\n"; 
    else cout << "NO\n";
}