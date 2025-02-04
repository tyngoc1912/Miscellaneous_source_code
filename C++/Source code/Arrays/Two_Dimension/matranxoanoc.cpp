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

    //ma trận xoay ốc cấp n => công thức : (n + 1) / 2 vòng xung quanh -> số lần duyệt
    int d = 1;
    for(int step = 0; step < (n + 1) / 2; step++){
        //vòng ngoài cùng bên trên n pt
        for(int j = step; j < n - step; j++) a[step][j] = d++;
        //vòng bên phải ngoài cùng n - 1 pt
        for(int i = step + 1; i < n - step; i++) a[i][n - 1 - step] = d++;
        //vòng dưới cùng n - 1 pt
        for(int j = n - 2 - step; j >= step; j--) a[n - 1 - step][j] = d++;
        //vòng bên trái ngoài cùng
        for(int i = n - 2 - step; i > step; i--) a[i][step] = d++;
        //lặp vào các vòng bên trong
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}