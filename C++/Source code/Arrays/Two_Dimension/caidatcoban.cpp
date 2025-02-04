#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll res[1000][1000];
int n, m, p;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //Nhập mảng 2 chiều
    cin >> m >> n >> p;
    ll a[n][p], b[p][m], sum[n][m], dif[n][m], product[n][m];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < p; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }

    //Cộng 2 ma trận
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sum[i][j] = a[i][j] + b[i][j]; 
        }
    }

    //Hiệu 2 ma trận
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dif[i][j] = a[i][j] - b[i][j]; 
        }
    }

    //Nhân 2 ma trận
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            product[i][j] = 0;
            for(int k = 0; k < p; k++){
                product[i][j] += 1ll * a[i][k] * b[k][j];
            }
        }
    }

    //Xuất ma trận
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << sum[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dif[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << product[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}