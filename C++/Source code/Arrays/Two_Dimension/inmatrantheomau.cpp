#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    //Ma trận chuyển vị
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    //kiểu 2
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    //Kiểu 3
    for(int j = n - 1; j >= 0; j--){
        for(int i = 0; i < n; i++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //Kiểu 4
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    //kiểu 5
    for(int j = n - 1; j >= 0; j--){
        for(int i = n - 1; i >= 0; i--){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}