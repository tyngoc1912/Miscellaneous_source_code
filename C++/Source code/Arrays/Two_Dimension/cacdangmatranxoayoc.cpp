#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Duyệt ma trận xoáy ốc cỡ N*M dùng vector
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int h1 = 0, h2 = matrix.size() - 1, c1 = 0, c2 = matrix[0].size() - 1;
    if(matrix.empty() || matrix[0].empty()) return res;
    while (h1 <= h2 && c1 <= c2) {
            // hàng trên cùng
        for (int j = c1; j <= c2; j++) {
            res.push_back(matrix[h1][j]);
        }
        h1++;
            // hàng ngoài cùng bên phải
        for (int i = h1; i <= h2; i++) {
            res.push_back(matrix[i][c2]);
        }
        c2--;
            // hàng dưới cùng
        if (h1 <= h2) {
            for (int j = c2; j >= c1; j--) {
                res.push_back(matrix[h2][j]);
            }
            h2--;
        }

            // hàng đầu bên trái
        if (c1 <= c2) {
            for (int i = h2; i >= h1; i--) {
                res.push_back(matrix[i][c1]);
            }
            c1++;
        }
    }
    return res;
}

//xây dựng 100 số nguyên tố đầu tiên
int p[100];
bool prime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return n > 1;
}
void init(){
    int i = 0, num = 0;
    while(i < 100){
        if(prime(num)){
            p[i] = num;
            ++i;
        }
        ++num;
    }
}

//xây dựng 93 số nguyên fibonacci
ll fibo[93];
void init(){
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i <= 92; i++){
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int a[n][n];

    //Xây dựng ma trận xoáy ốc
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
    int d = 1;
    while(h1 <= h2 && c1 <= c2){
        //hàng trên cùng
        for(int j = c1; j <= c2; j++){
            a[h1][j] = d++;
        }
        h1++;
        //hàng ngoài cùng bên phải
        for(int i = h1; i <= h2; i++){
            a[i][c2] = d++;
        }
        c2--;
        //hàng dưới cùng
        if(c1 <= c2){
            for(int j = c2; j >= c1; j--){
                a[h2][j] = d++;
            }
            h2--;
        }
        
        //hàng đầu bên trái
        if(h1 <= h2){
            for(int i = h2; i >= h1; i--){
                a[i][c1] = d++;
            }
            c1++;
        }
    }

    //Xây dựng ma trận xoáy ốc ngược
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
    int d = n * n;
    while(h1 <= h2 && c1 <= c2){
        //hàng trên cùng
        for(int j = c1; j <= c2; j++){
            a[h1][j] = d--;
        }
        h1++;
        //hàng ngoài cùng bên phải
        for(int i = h1; i <= h2; i++){
            a[i][c2] = d--;
        }
        c2--;
        //hàng dưới cùng
        if(c1 <= c2){
            for(int j = c2; j >= c1; j--){
                a[h2][j] = d--;
            }
            h2--;
        }
        
        //hàng đầu bên trái
        if(h1 <= h2){
            for(int i = h2; i >= h1; i--){
                a[i][c1] = d--;
            }
            c1++;
        }
    }

    //Xây dựng ma trận xoáy ốc nguyên tố
    init();
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
    int d = 0;
    while(h1 <= h2 && c1 <= c2){
        for(int j = c1; j <= c2; j++){
            a[h1][j] = p[d++];
        }
        h1++;
        for(int i = h1; i <= h2; i++){
            a[i][c2] = p[d++];
        }
        c2--;
        if(c1 <= c2){
            for(int j = c2; j >= c1; j--){
                a[h2][j] = p[d++];
            }
            h2--;
        }
        if(h1 <= h2){
            for(int i = h2; i >= h1; i--){
                a[i][c1] = p[d++];
            }
            c1++;
        }
    }

    //Xây dựng ma trận xoáy ốc fibonacci
    init();
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
    int d = 0;
    while(h1 <= h2 && c1 <= c2){
        for(int j = c1; j <= c2; j++){
            a[h1][j] = fibo[d++];
        }
        h1++;
        for(int i = h1; i <= h2; i++){
            a[i][c2] = fibo[d++];
        }
        c2--;
        if(c1 <= c2){
            for(int j = c2; j >= c1; j--){
                a[h2][j] = fibo[d++];
            }
            h2--;
        }
        if(h1 <= h2){
            for(int i = h2; i >= h1; i--){
                a[i][c1] = fibo[d++];
            }
            c1++;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}