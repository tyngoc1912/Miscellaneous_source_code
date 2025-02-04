#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void modName(string &s){
    for(auto &x : s) x = tolower(x);
}

string getNum(string s){
    string res = "";
    stringstream ss(s);
    string num;
    while(getline(ss, num, '/')){
        int tmp = stoi(num);
        res += to_string(tmp);
    }
    return res; 
}

//có thể giải theo solve này
void solve(){
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; getline(cin, s);

        stringstream ss(s);
        string tmp;
        vector<string> v;
        while(ss >> tmp) v.push_back(tmp);

        int n = v.size() - 1;
        for(int i = 0; i < n; i++){
            for(auto &x : v[i]) x = tolower(x);
        }
        string email = v[n - 1];
        for(int i = 0; i < n - 1; i++) email += v[i][0];
        email += "@xyz.edu.vn";
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

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    cin.ignore();
    while(t--){
        string s; 
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        vector<string> v;
        while(ss >> tmp) v.push_back(tmp);
        int n = v.size() - 1;
        for(int i = 0; i < n; i++) modName(v[i]);
        string email = v[n - 1];
        for(int i = 0; i < n - 1; i++) email += v[i][0];
        email += "@xyz.edu.vn";
        string password = getNum(v[n]);
        cout << email << endl << password << endl;
    }

}