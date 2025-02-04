#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool prime(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int a[n][n];
    int b[n][n];
    int c[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    //C1
    for(int j = 0; j < n; j++){
        vector<int> v;
        for(int i = 0; i < n; i++) v.push_back(a[i][j]); 
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) c[i][j] = v[i]; 
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    //C2
    for(int i = 0; i < n; i++) sort(b[i], b[i] + n);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}