#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    string s; 
    getline(cin, s);
    stringstream ss(s);
    string tmp;
    vector<string> v;
    while(ss >> tmp){
        v.push_back(tmp);
    }
    for(int i = 0; i < v.size(); i++){
        if(v[i] != v[v.size() - 1]){
            v[i][0] = toupper(v[i][0]);
            for(int j = 1; j < v[i].size(); j++) v[i][j] = tolower(v[i][j]);
        }
        else{
            for(auto &x : v[i]) x = toupper(x); 
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i];
        if(i != v.size() - 1 && i != v.size() - 2) cout << " ";
        else if(i == v.size() - 2) cout << ", ";
    }
    cout << endl;
    cout << v[v.size() - 1] << ", ";
    for(int i = 0; i < v.size() - 1; i++){
        cout << v[i];
        if(i != v.size() - 2) cout << ' ';
    }
}