#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Chuẩn hóa tên -> Viết hoa chữ đầu và mấy chữ sau viết thường
void modName(string &s){
    s[0] = toupper(s[0]);
    for(int i = 1; i < s.size(); i++) s[i] = tolower(s[i]);
}

//Chuẩn hóa ngày tháng năm sinh theo form dd/mm/yyyy => ứng dụng để viết comparator so sánh tuổi theo thứ tự từ điển
void modDate(string &s){
    if(s[2] != '/') s = "0" + s;
    if(s[5] != '/') s.insert(3, "0");
}

void convert(){
    string s, t; 
    getline(cin, s);
    getline(cin, t);
    stringstream ss(s);
    string tmp;
    vector<string> v;
    while(ss >> tmp){
        v.push_back(tmp);
    }
    for(int i = 0; i < v.size(); i++){
        modName(v[i]);
        cout << v[i];
        if(i != v.size() - 1) cout << " ";
    }
    cout << endl;
    modDate(t);
    cout << t << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    convert();
}