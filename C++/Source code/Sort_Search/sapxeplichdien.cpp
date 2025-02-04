#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Sắp xếp lịch diễn nhiều nhất => ko bị trùng => Scheduling problems
void solve(){
    int n; cin >> n;
    pair<int, int> a[n];
    for(auto &x : a) cin >> x.first >> x.second;
    sort(a, a + n, [](auto a, auto b)->bool{
        return a.second < b.second;
    });
    int res = 1, endTime = a[0].second;
    for(int i = 1; i < n; i++){
        if(a[i].first > endTime){
            res++;
            endTime = a[i].second;
        }
    }
    cout << res << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    solve();
}