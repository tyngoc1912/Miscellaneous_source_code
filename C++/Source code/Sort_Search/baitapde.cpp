#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//sắp xếp
int n;
//sắp xếp theo trị tuyệt đối tăng dần
void sort1(){
    cin >> n; 
    int a[n];
    for(int &x : a) cin >> x;
    stable_sort(a, a + n, [](int a, int b) -> bool{
        return abs(a) < abs(b);
    });
    for(int x : a) cout << x << ' ';
}

//sắp xếp theo tổng chữ số tăng dần
int sumDigit(int n){
    int s = 0;
    while(n){
        s += n % 10;
        n /= 10;
    }
    return s;
}
void sort2(){
    cin >> n; 
    int a[n];
    for(int &x : a) cin >> x;
    stable_sort(a, a + n, [](int a, int b)->bool{
        int x = sumDigit(a);
        int y = sumDigit(b);
        if(x != y) return a < b;
        else return x < y;
    });
    for(int x : a) cout << x << ' ';
}

//độ chênh lệch 2 pt là nhỏ nhất
void kcmin(){
    cin >> n; 
    int a[n];
    for(int &x : a) cin >> x;
    if(n == 1){
        cout << 0 << endl;
        return; 
    }
    sort(a, a + n);
    int res = INT_MAX;
    for(int i = 1; i < n; i++){
        res = min(res, a[i] - a[i - 1]);
    }
    cout << res << endl;
}

//số xuất hiện nhiều nhất trong mảng => số nào có cùng tần suất xuất hiện thì in số nhỏ nhất
const int MAXN = 1e7 + 1;
void maxFreq(){
    map<int, int> mp;
    vector<pair<int, int>> res;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    for(auto x : mp) res.push_back(x);
    sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b)->bool{
        if(a.second != b.second) return a.second > b.second;
        else return a.first < b.first;
    });
    cout << res[0].first << " " << res[0].second;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    maxFreq();
}