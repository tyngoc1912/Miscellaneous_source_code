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

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    set<int> se;
    for(int i = 0; i < n; i++){
        if(prime(a[i][i])) se.insert(a[i][i]);
        if(i != n - 1 - i && prime(a[i][n - 1 - i])) se.insert(a[i][n - 1 - i]);
    }

    cout << se.size() << endl;
}