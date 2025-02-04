#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //Xâu con liên tiếp có độ dài lớn nhất
    string s; cin >> s;
    int cnt = 1;
    int res = 1;
    char ans = s[0];
    s += '0';
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1]) cnt++;
        else{
            if(cnt > res){
                res = cnt;
                ans = s[i - 1];
            }
            else if(cnt == res){
                ans = max(ans, s[i - 1]); // kí tự có thứ tự từ điển lớn hơn
            }
            cnt = 1;
        }
    }
    string st = string(res, ans);
    cout << st << endl;
}