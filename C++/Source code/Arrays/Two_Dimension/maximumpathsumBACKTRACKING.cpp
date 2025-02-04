#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//hoặc là khai báo bên ngoài
ll a[500][500], res = 0;
ll n, m;

void Try(int i, int j, ll sum){
    if(i == n && j == m) res = max(res, sum);
    else{
        if(j + 1 <= m) Try(i, j + 1, sum + a[i][j + 1]);
        if(i + 1 <= n) Try(i + 1, j, sum + a[i + 1][j]);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    //maximum path sum
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    Try(1, 1, a[1][1]);
    cout << res << endl;
}