#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[500][500];
ll n, m;

//Kiểm tra có đường đi từ ô (s, t) sang (u, v) ko
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void Try(int i, int j){
    a[i][j] = 0;
    for(int k = 0; k < 4; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == 1){
            Try(i1, j1);
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    int s, t, u, v;
    cin >> s >> t >> u >> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    Try(s-1, t-1);
    if(a[u - 1][v - 1] == 1) cout << "NO\n";
    else cout << "YES\n";
    //ko thì phải chỉnh cách nhập cho đúng với chỉ số
}