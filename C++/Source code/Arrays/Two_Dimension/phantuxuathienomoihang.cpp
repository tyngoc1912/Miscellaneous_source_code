#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[500][500];
ll n, m;


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n ;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    //đếm số xuất hiện ở mọi hàng trong ma trận
    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mp[a[i][j]] == i - 1){
                mp[a[i][j]] = i;
            }
        }
    }
    bool check = false;
    for(auto x : mp){
        if(x.second == n){ 
            cout << x.first << ' ';
            check = true;
        }
    }
    if(check == false) cout << "NOT FOUND\n";
}