#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;
    s += "@";
    ll sum = 0;
    ll num = 0;
    for(auto x : s){
        if(isdigit(x)) num = num * 10 + (x - '0');
        else{
            sum += num;
            num = 0;
        }
    }
    cout << sum << endl;

    //C2
    string s; cin >> s;
    s += "@";
    ll sum = 0;
    string num = "0";
    for(auto x : s){
        if(isdigit(x)) num += x;
        else{
            ll tmp = stoll(num);
            sum += tmp;
            num = "0";
        }
    }
    cout << sum << endl;
}