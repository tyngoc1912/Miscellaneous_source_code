#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    cin.ignore();
    map<string, int> mp;
    while(t--){
        string s; getline(cin, s);
        for(auto &x : s) x = tolower(x);

        stringstream ss(s);
        string tmp;
        vector<string> v;
        while(ss >> tmp) v.push_back(tmp);

        int n = v.size() - 1;
        string email = v[n - 1];
        for(int i = 0; i < n - 1; i++) email += v[i][0];
        
        mp[email]++;
        if(mp[email] == 1) email += "@xyz.edu.vn";
        else email += to_string(mp[email]) + "@xyz.edu.vn";
        
        cout << email << endl;

        stringstream ss2(v[n]);
        string num;
        while(getline(ss2, num, '/')){
            int tmp = stoi(num);
            cout << tmp;
        }
        cout << endl;
    }
}