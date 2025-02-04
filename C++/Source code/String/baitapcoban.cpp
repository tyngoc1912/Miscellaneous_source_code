#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//hàm cơ bản
ll sumOfNum(string s){
    ll sum = 0;
    for(int i = 0; i < s.size(); i++){
        sum += s[i] - '0';
    }
    return sum;
}

//s.find(t) => trả về vị trí đầu tiên của xâu con đầu tiên trong xâu s nếu ko có thì trả về vị trí npos
bool checkSubString(string s, string t){
    if(s.find(t) != string::npos) return true;
    else return false;
}

string Upper(string s){
	for(int i = 0; i < s.size(); i++){
		s[i] = toupper(s[i]);
	}
	return s;
}

string Lower(string s){
	for(int i = 0; i < s.size(); i++){
		s[i] = tolower(s[i]);
	}
	return s;
}

void checkChar(char c){
	if(c >= 65 && c <= 90){
		cout << "UPCASE : ";
		cout << (char)(c + 32) << endl;
	} 
	else if(97 <= c <= 122){
		cout << "DOWNCASE : ";
		cout << (char)(c - 32);
	} 
}

//Công thức tính chia dư cho các số xấu hoặc có độ dài chữ số lớn
ll Mod(string s, ll b){
    ll mod = 0;
    for(auto a : s){
        mod = (mod * 10 + (a - '0')) % b;
    }
    return mod;
} 

//đếm kí tự
void solve1(){
    string s;
    getline(cin, s);
    int num = 0, character = 0, special = 0;
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])) num++;
        else if(isalpha(s[i])) character++;
        else special++;
    }
    cout << character << " " << num << " " << special << endl;
}

//chuyển đổi in hoa và in thường
void upper(string &s){
    for(int i = 0; i < s.size(); i++){
        s[i] = toupper(s[i]);
    }
}
void lower(string &s){
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }
}
void solve2(){
    string s; 
    getline(cin, s);
    upper(s);
    cout << s << endl;
    lower(s);
    cout << s << endl;
}

//đếm tần xuất xuất hiện của các từ
void solve3(){
    string s;
    getline(cin, s);
    //cin.ignore();
    //C1
    int cnt[256] = {0};
    for(int i = 0; i < s.size(); i++){
        cnt[s[i]]++;
    }
    //chỉ duyệt 0 - 255 hoặc bé hơn 256 nếu dùng <= 256 sẽ sai ngay
    for(int i = 0; i < 256; i++){
        if(cnt[i] != 0){
            cout << (char)i << " " << cnt[i] << endl;
        }
    }
    cout << endl;
    for(int i = 0; i < s.size(); i++){
        if(cnt[s[i]] != 0){
            cout << s[i] << " " << cnt[s[i]] << endl;
            cnt[s[i]] = 0;
        }  
    }
    cout << endl;
    //C2
    map<char, int> mp;
    for(auto x : s) mp[x]++;
    for(auto it : mp) cout << it.first << ' ' << it.second << endl;
    cout << endl;
    for(auto x : s){
        if(mp[x] != 0){
            cout << x << " " << mp[x] << endl;
            mp[x] = 0;
        }
    }
    cout << endl;
}

//kí tự có số lần xuất hiện nhiều nhất và thứ tự xuất hiện ít nhất nếu trùng tần xuất thì in theo thứ tự từ điển lớn nhất
bool cmp(pair<char, int> a, pair<char, int> b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first; 
}
void solve4(){
    string s;
    cin >> s;

    map<char, int> mp;
    for(auto x : s) mp[x]++;

    vector<pair<char, int>> v;
    for(auto it : mp) v.push_back(it);
    sort(v.begin(), v.end(), cmp);
    
    for(auto x : v) cout << x.first << " " << x.second << endl;
    cout << endl;

    cout << v[v.size() - 1].first << " " << v[v.size() - 1].second << endl;
    char res = v[0].first; 
    int cnt = v[0].second;
    for(int i = 1; i < s.size(); i++){
        if(cnt == v[i].second) res = v[i].first;
    } 
    cout << res << " " << cnt << endl;
}

//ký tự xuất hiện ở cả 2 xâu và xuất hiện 1 trong 2 xâu
void solve5(){
    //C1
    string s; cin >> s;
    string t; cin >> t;
    set<char> se1, se2, se3;
    for(int i = 0; i < s.size(); i++){
        se1.insert(s[i]);
        se2.insert(s[i]);
    }
    for(int i = 0; i < t.size(); i++){
        if(se1.count(t[i]) != 0) se3.insert(t[i]);
        else se2.insert(t[i]);
    }
    for(auto x : se3) cout << x;
    cout << endl;
    for(auto x : se2) cout << x;
    cout << endl;

    //C1
    string s, t; cin >> s >> t;
    int cnt[256] = {0};
    for(char x : s) cnt[x] = 1;
    for(char x : t){
        if(cnt[x] == 1) cnt[x] = 2;
        else if(cnt[x] == 0) cnt[x] = -1;
    }
    for(int i = 0; i < 256; i++){
        if(cnt[i] == 2) cout << (char)i;
    }
    cout << endl;
    for(int i = 0; i < 256; i++){
        if(cnt[i] != 0) cout << (char)i;
    }
}

//ký tự chỉ xuất hiện trong xâu 1 mà ko có trong xâu 2 và ngược lại
void solve6(){
    string s1; cin >> s1;
    string s2; cin >> s2;
    set<char> se1, se2;
    for(auto x : s1) se1.insert(x);
    for(auto x : s2) se2.insert(x);
    for(auto x : se1){
        if(!se2.count(x)) cout << x;
    }
    cout << endl;
    for(auto x : se2){
        if(!se1.count(x)) cout << x;
    }
    cout << endl;
}

//Xâu đối xứng
void solve7(){
    string s; cin >> s;
    string t = "";
    for(int i = s.size() - 1; i >= 0; i--){
        t += s[i];
    }
    if(t == s) cout << "YES\n";
    else cout << "NO\n";
}

//Thêm
void solve8(){
    char c; cin >> c;

   //in ra chữ cái liền sau
    if(c == 'z') cout << 'a' << endl;
    else cout << (char)(c + 1) << endl;

   //in ra chữ liền sau nhưng luôn luôn là chữ thường
    if(c == 'z' || c == 'Z') cout << 'a' << endl;
    else if(c >= 'A' && c <= 'Z') cout << (char)(c + 33) << endl;
    else cout << (char)(c + 1);
}

//Xâu có đầy đủ 26 kí tự hay ko (Pangram)
void solve9(){
    string s; cin >> s;
    set<char> se;

    for(int i = 0; i < s.size(); i++) s[i] = tolower(s[i]); 
    for(auto x : s) se.insert(x);

    if(se.size() == 26) cout << "YES\n";
    else cout << "NO\n";
}

//Đếm số lượng từ 
void solve10(){
    string s; 
    getline(cin, s); 
    cin.ignore();
    stringstream ss(s);
    string w;
    int cnt = 0;
    while(ss >> w){
        cnt++;
    }
    cout << cnt << endl;
}

//Liệt kê các từ khác nhau trong xâu
void solve11(){
    string s; 
    getline(cin, s);
    set<string> se;
    vector<string> v;
    map<string, int> mp;
    stringstream ss(s);
    string w;
    while(ss >> w){
        //C1
        if(!se.count(w)) v.push_back(w);
        se.insert(w);
        //C2
        mp[w]++;
        v.push_back(w);
        se.insert(w);
    }
    //C1
    for(auto it : se) cout << it << " "; cout << endl;
    for(auto x : v) cout << x << ' ';

    //C2
    for(auto x : se) cout << x << " "; cout << endl;
    for(auto x : v){
        if(mp[x] != 0){
            cout << x << " ";
            mp[x] = 0;
        }
    }
}

//Sắp xếp xâu theo thứ tự từ điển và độ dài xâu
void solve12(){
    string s; 
    getline(cin, s);
    vector<string> v;
    stringstream ss(s);
    string w;
    while(ss >> w) v.push_back(w);

    sort(v.begin(), v.end());
    for(auto x : v) cout << x << " "; 
    cout << endl;
    sort(v.begin(), v.end(), [](string a, string b)->bool{
        if(a.size() != b.size()) return a.size() < b.size();
        else return a < b;
    });
    for(auto x : v) cout << x << ' ';
}

//Sắp xếp xâu đối xứng khác nhau theo độ dài và theo thứ tự xuất hiện
bool palindrome(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
void solve13(){
    string s; 
    getline(cin, s);
    vector<string> v;
    set<string> se;
    stringstream ss(s);
    string w;
    while(ss >> w){
        if(!se.count(w) && palindrome(w)){
            v.push_back(w);
            se.insert(w);
        }
    }
    stable_sort(v.begin(), v.end(), [](string a, string b)->bool{
        return a.size() < b.size();
    });
    for(auto x : v) cout << x << ' ';
}

//Tần xuất các từ trong xâu
void solve14(){
    string s; 
    getline(cin, s);
    map<string, int> mp;
    vector<string> v;
    stringstream ss(s);
    string w;
    while(ss >> w){
        mp[w]++;
        v.push_back(w);
    }
    for(auto x : mp) cout << x.first << " " << x.second << endl;
    cout << endl;
    for(auto x : v){
        if(mp[x] != 0){
            cout << x << ' ' << mp[x] << endl;
            mp[x] = 0;
        }
    }
}

//Từ xuất hiện nhiều nhất, ít nhất
void solve15(){
    //C1
    string s; 
    getline(cin, s);
    map<string, int> mp;
    vector<pair<string, int>> v;
    stringstream ss(s);
    string w;
    while(ss >> w) mp[w]++;
    for(auto x : mp) v.push_back(x);
    sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b)->bool{
        if(a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    });
    
    cout << v[v.size() - 1].first << " " << v[v.size() - 1].second << endl;
    string res = v[0].first;
    int cnt = v[0].second;
    for(int i = 1; i < v.size(); i++){
        if(v[i].second == cnt) res = v[i].first;
    }
    cout << res << " " << cnt << endl;

    //C2
    string s; getline(cin, s);
    map<string, int> mp;
    stringstream ss(s);
    string w;
    while(ss >> w){
        mp[w]++;
    }
    string st1, st2;
    int fre1 = 0, fre2 = 1e9;
    for(auto it : mp){
        if(it.second >= fre1){
            st1 = it.first; 
            fre1 = it.second;
        }
        if(it.second <= fre2){
            st2 = it.first;
            fre2 = it.second;
        }
    }
    cout << st1 << " " << fre1 << endl;
    cout << st2 << " " << fre2 << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve1();
    solve2();
    solve3();
    solve4();
    solve5();
    solve6();
    solve7();
    solve8();
    solve9();
    solve10();
    solve11();
    solve12();
    solve13();
    solve14();
    solve15();

    // abcd123 $%^ a
    // abcd ABCD
    // abcdabcdA
    // aBjMzzKKll
    // nTOhOGvRBk
    // bUJtZSoONh
    // fAOxTUeAIs
    // aVUkULeRYw
    // cBGkXXqKWqqWKqXXkGBc  
    // T 
}

