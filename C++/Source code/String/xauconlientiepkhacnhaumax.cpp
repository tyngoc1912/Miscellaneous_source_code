#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //Xâu con liên tiếp khác nhau có độ dài lớn nhất
    string s; cin >> s;
    string cnt = string(1, s[0]);
    string ans = "";
    for(int i = 1; i < s.size(); i++){
        if(cnt.back() != s[i]) cnt += string(1, s[i]);
        else{
            if(cnt.size() > ans.size()) ans = cnt;
            else if(cnt.size() == ans.size()) ans = max(ans, cnt);
            cnt = string(1, s[i]);
        }
    }
    if(cnt.size() > ans.size()) ans = cnt;
    else if(cnt.size() == ans.size()) ans = max(ans, cnt);
    cout << ans << endl;
}