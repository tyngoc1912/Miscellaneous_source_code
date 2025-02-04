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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    //snake
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i % 2 == 0) cout << a[i][j] << ' ';
            else cout << a[i][n - 1 - j] << ' ';
        }
    }
    cout << endl;
    //in ra viền của ma trận
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || i == n - 1){
                cout << a[i][j] << " ";
            }
            else{
                if(j == 0 || j == n - 1) cout << a[i][j] << ' ';
                else continue;
            }
        }
    }
}