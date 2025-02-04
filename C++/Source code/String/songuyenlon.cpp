#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Số nguyên lớn => dùng string
//Tổng số nguyên lớn
string sum(string a, string b){
    //(a.size() > b.size() || a.size() == b.size() && a > b)
    reverse(a.begin(), a.end()); 
    reverse(b.begin(), b.end());
    int d1 = a.size();
    int d2 = b.size();
    string res = string(d1 + 1, '0');
    // làm đầy size sao cho bằng xâu kq
    a += "0"; 
    for(int i = d2; i <= d1; i++) b += "0";
    int num, mem = 0;
    for(int i = 0; i <= d1; i++){
        num = a[i] - '0' + b[i] - '0' + mem;
        mem = num / 10;
        num %= 10;
        res[i] += num; //res[i] = num + '0';
    }
    if(res[res.size() - 1] == '0') res.erase(res.size() - 1);
    reverse(res.begin(), res.end());
    return res;
}
void sumOfBigInt(){
    string a, b;
    cin >> a >> b;
    if(a.size() > b.size() || (a.size() == b.size() && a > b)) cout << sum(a, b) << endl;
    else cout << sum(b, a) << endl;
}

//Hiệu số nguyên lớn
string dif(string a, string b){
    //(a.size() > b.size() || a.size() == b.size() && a > b)
    reverse(a.begin(), a.end()); 
    reverse(b.begin(), b.end());
    int d1 = a.size();
    int d2 = b.size();
    string res = string(d1, '0');
    // làm đầy size sao cho bằng xâu kq
    for(int i = d2; i < d1; i++) b += "0";
    int num, carry = 0;
    for(int i = 0; i < d1; i++){
        num = a[i] - b[i] - carry;
        if(num < 0){
            num += 10;
            carry = 1;
        }
        else carry = 0;
        res[i] += num; //res[i] = num + '0';
    }
    int pos = res.size() - 1;
    while(pos >= 0 && res[pos] == '0') pos--;
    if(pos == -1) res = "0";
    else res.erase(pos + 1);
    return res;
}
void difOfBigInt(){
    string a, b;
    cin >> a >> b;
    if(a.size() > b.size() || (a.size() == b.size() && a > b)) cout << dif(a, b) << endl;
    else cout << dif(b, a) << endl;
}

//tính tổng tất cả các chữ số của n
void solve1(){
    string s; cin >> s;
    ll sum = 0;
    for(auto x : s){
        sum += x - '0';
    }
    cout << sum << endl;
}

//Số đẹp 1
bool prime(ll n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}
void solve2(){
    string s; cin >> s;
    ll sum = 0;
    for(char x : s){
        if(x != '2' && x != '3' && x != '5' && x != '7'){
            cout << "NO\n";
            break;
        }
        else sum += x - '0';
    }
    if(prime(sum)) cout << "YES\n";
    else cout << "NO\n";
}

//Số đẹp 2
void solve3(){
    string s; cin >> s;
    int i = 0, j = s.size() - 1;
    bool check = false;
    while(i <= j){
        if(s[i] != s[j]){
            cout << "NO\n";
            break;
        }
        if(s[i] == '6') check = true;
        i++; j--;
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
}

//Số đẹp 3
bool increase(string s){
    bool check = true;
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] > s[i + 1]){
            return false;
        }
    }
    return true;
}
bool decrease(string s){
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] < s[i + 1]){
            return false;
        }
    }
    return true;
}
void solve4(){
    string s; cin >> s;
    if(increase(s) || decrease(s)) cout << "YES\n";
    else cout << "NO\n";
}

//số chia hết cho 6 => chia hết cho 2 và 3
void solve5(){
    string s; cin >> s;
    if(s.size() == 1 && (s == "0" || s == "6")) cout << "YES\n";
    else{
        ll sum = 0;
        for(auto x : s) sum += x - '0';
        int tmp = stoi(string(1, s[s.size() - 1]));
        if(sum % 3 == 0 && tmp % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

//số chia hết cho 4 => nếu nó chia hết cho 4 hoặc 2 chữ số cuối của nó chia hết cho 4
void solve6(){
    string s; cin >> s;
    if(s.size() == 1 && (s == "0" || s == "4" || s == "8")) cout << "YES\n";
    else{
        string tmp = s.substr(s.size() - 2, 2);
        int num = stoi(tmp);
        if(num % 4 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

//Số chia hết cho 15 => chia hết cho 5 và 3
void solve7(){
    string s; cin >> s;
    ll sum = 0;
    for(auto x : s) sum = x - '0';
    if(sum % 3 == 0 && (s[s.size() - 1] == '0' || s[s.size() - 1] == '5')) cout << "YES\n";
    else cout << "NO\n";
}

//số chia hết cho 25 => 2 số tận cùng là 0 hoặc chia hết cho 25
void solve8(){
    string s; cin >> s;
    string tmp = s.substr(s.size() - 2, 2);
    if(tmp == "00") cout << "YES\n";
    else{
        int num = stoi(tmp);
        if(num % 25 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

void chiaHetCho25(){
    string s; cin >> s;
    int num = 0;
    if(s.size() == 1){
        num = s[0] - '0';
    }
    else{
        num = (s[s.size() - 2] - '0') * 10 + (s.back() - '0');
    }
    if(num % 25 == 0) cout << "YES\n";
    else cout << "NO\n"; 
}


//Số chia hết cho 11 => hiệu tổng chữ số ở vị trí chẵn và lẻ chia hết cho 11
void solve9(){
    string s; cin >> s;
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < s.size(); i++){
        if(i % 2 == 0) sum1 += s[i] - '0';
        else sum2 += s[i] - '0';
    }
    if(max(sum1 - sum2, sum2 - sum1) % 11 == 0) cout << "YES\n";
    else cout << "NO\n";
}

//Số nhị phân chia hết cho 5
void solve10(){
    string s; cin >> s;
    ll num = 0, pow = 1; // pow = 2^k (k = 0, 1, 2...)
    for(int i = s.size() - 1; i >= 0; i--){
        num += (s[i] - '0') * pow;
        pow *= 2;
        num %= 5;
        pow %= 5;
    }
    if(num == 0) cout << "YES\n";
    else cout << "NO\n";
}

//Số nhị phân chia hết cho 2^k
void solve11(){
    string s; cin >> s;
    //kiểm tra những bit đứng sau k tức là ko là bội của k có ít nhất 1 số 1 thì số đó ko chia hết cho 2^k
    int k; cin >> k;
    int cnt = 0;
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == '0') cnt++;
        else break;
    }
    if(cnt >= k) cout << "YES\n";
    else cout << "NO\n";
}

//Công thức tính chia dư cho các số
ll Mod(string s, ll b){
    ll mod = 0;
    for(auto a : s){
        mod = (mod * 10 + (a - '0')) % b;
    }
    return mod;
} 
void solve12(){
    string n; cin >> n; 
    ll m; cin >> m;
    cout << Mod(n, m) << endl;
}

//Tìm ước chung lớn của số nguyên lớn
ll gcd(ll a, ll b){
    ll r; 
    while(b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void solve13(){
    string n; cin >> n;
    ll m; cin >> m;
    ll mod = 0;
    for(auto x : n) mod = (mod * 10 + (x - '0')) % m;
    cout << gcd(m, mod) << endl;
}

//Lũy thừa cơ số lớn
const int MOD = 1e9 + 7;
ll powMod(ll a, ll b){
    ll res = 1;
    while(b){
        if(b % 2 == 1){
            res = ((res % MOD) * (a % MOD)) % MOD;
        }
        a = ((a % MOD) * (a % MOD)) % MOD;
        b /= 2;
    }
    return res;
}
void solve14(){
    string n; cin >> n;
    ll m; cin >> m;
    ll mod = 0;
    for(auto x : n) mod = (mod * 10 + (x - '0')) % MOD;
    //n^m % MOD = ((n % MOD)^m) % MOD
    cout << powMod(mod, m) << endl;
}

//Số may mắn => digital root
void solve15(){
    string s; cin >> s;
    ll tmp = 0;
    for(auto x : s) tmp += x - '0';
    ll res = tmp;
    while(res > 9){
        int sum = 0;
        while(tmp){
            sum += tmp % 10;
            tmp /= 10; 
        }
        res = sum;
    }
    if(res == 9) cout << "YES\n";
    else cout << "NO\n";
}

//Xóa số 111
void solve16(){
    string s; cin >> s;
    for(int i = 0; i < s.size() - 2; i++){
        cout << "dang xet vi tri : " << i << endl;
        if(s.size() < 3) break;
        if(s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '1'){
            cout << "Bat dau xoa tu : " << i << endl;
            s.erase(i, 3);
            cout << s << endl;
            //bắt buộc phải có bước này để tránh bị xóa thiếu
            i--;
        }
    }
    if(s.size() != 0) cout << s << endl;
    else cout << "EMPTY\n";
}

//Chữ số cuối cùng của 8^n
// 2008^1 = ....8
// 2008^2 = ....4
// 2008^3 = ....2
// 2008^4 = ....6
// 2008^5 = ....8
// Vậy chu kì lũy thừa của các số có chữ số tận cùng là 8 là 8,4,2,6 => n % 4 
void solve17(){
    string n; cin >> n;
    if(n == "0"){
        cout << 1 << endl;
        return;
    }
    ll mod = 0;
    for(auto x : n) mod = (mod * 10 + (x - '0')) % 4;
    if(mod == 0) cout << 6 << endl;
    else if(mod == 1) cout << 8 << endl;
    else if(mod == 2) cout << 4 << endl;
    else cout << 2 << endl;
}

//UCLN của 2 số đc bd x và y lần
void solve18(){
    ll a, b, c; cin >> a >> b >> c;
    ll cnt = __gcd(b, c);
    for(int i = 0; i < cnt; i++) cout << a;
    cout << endl;
}

//Tích giai thừa => phân tích giai thừa ở hợp số ko phân tích ở số nguyên tố
void solve19(){
    string s; cin >> s;
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0' || s[i] == '1') continue;
        else if(s[i] == '4') ans += "322";
        else if(s[i] == '6') ans += "53";
        else if(s[i] == '8') ans += "7222";
        else if(s[i] == '9') ans += "7332";
        else ans += s[i];
    }
    sort(ans.begin(), ans.end(), greater<char>());
    cout << ans << endl;
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
    solve16();
    solve17();
    solve18();
    solve19();
    sumOfBigInt();
    difOfBigInt();
}
