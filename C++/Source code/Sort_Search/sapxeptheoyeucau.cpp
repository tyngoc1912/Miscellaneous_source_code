#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//sắp xếp theo yêu cầu
void solve(){
    map<int, int> mp;
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;
    for(int i = 0; i < n; i++){
        v1.push_back({a[i], mp[a[i]]});
        v2.push_back({a[i], mp[a[i]]});
    }
    sort(v1.begin(), v1.end(), [](pair<int, int> a, pair<int, int> b)->bool{
        if(a.second != b.second) return a.second > b.second;
        else return a < b;
    });
    for(auto x : v1) cout << x.first << " ";
    cout << endl;
    stable_sort(v2.begin(), v2.end(), [](pair<int, int> a, pair<int, int> b)->bool{
        return a.second > b.second;
    });
    for(auto x : v2){
        while(mp[x.first] != 0){
            cout << x.first << ' ';
            mp[x.first]--;
        }
    }
}

//Sắp xếp theo yêu cầu => cách giải này bị sai chỉ tham khảo cách khác để sử dụng cmp
map<int, int> mp;
void solve(){
    int n; cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
        mp[a[i]]++;
    }
    sort(a, a + n, [](int a, int b)->bool{
        if(mp[a] != mp[b]) return mp[a] > mp[b];
        else return a < b;
    });
    for(int x : a) cout << x << ' ';
    cout << endl;
    stable_sort(b, b + n, [](int a, int b)->bool{
        return mp[a] > mp[b];
    });
    for(int x : b) cout << x << ' ';
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}