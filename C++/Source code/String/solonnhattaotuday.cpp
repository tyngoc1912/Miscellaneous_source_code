#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;
    vector<string>  v;
    string num = "";
    s += "@";
    for(auto x : s){
        if(isdigit(x)) num += x;
        else{
            while(num.size() > 1 && num[0] == 0) num.erase(0, 1);
            if(num != "") v.push_back(num);
            num = "";
        }
    }
    sort(v.begin(), v.end(), [](string a, string b)->bool{
        string ab = a + b;
        string ba = b + a;
        return ab > ba;
    });
    string res = "";
    for(auto x : v) res += x;
    cout << res << endl;
}