#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(string a, string b){
    if(a.size() != b.size()) return a.size() > b.size();
    else return a > b;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;
    s += "@";
    vector<string> num;
    string tmp = "";
    for(auto x : s){
        if(isdigit(x)) tmp += x;
        else{
            while(tmp.size() > 1 && tmp[0] == '0') tmp.erase(0, 1);
            if(tmp != "") num.push_back(tmp);
            tmp = "";
        }
    }
    sort(num.begin(), num.end(), cmp);
    cout << num[0] << endl;
}