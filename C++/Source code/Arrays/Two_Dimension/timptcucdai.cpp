#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;   cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool check = true;
            for(int k = 0; k < 8; k++){
                int i1 = i + dx[k], j1 = j + dy[k];
                if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m){
                    if(a[i][j] <= a[i1][j1]){
                        check = false;
                        break;
                    } 
                }
            }
            if(check) cnt++;
        }
    }
    cout << cnt << endl;
}
