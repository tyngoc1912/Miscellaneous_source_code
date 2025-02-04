#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//hoặc là khai báo bên ngoài
ll a[500][500];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, m; cin >> n >> m;
    //2 là khai báo bên trong và cho toàn bộ = 0
    ll a[n + 1][m + 1] = {0};
    //maximum path sum
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1) a[i][j] += a[i][j - 1];
            else if(j == 1) a[i][j] += a[i - 1][j];
            else a[i][j] += max(a[i - 1][j], a[i][j - 1]);
        }
    }
    cout << a[n][m] << endl;
}