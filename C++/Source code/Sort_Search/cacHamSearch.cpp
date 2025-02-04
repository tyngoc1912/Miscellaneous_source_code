#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool linearSearch(int a[], int n, int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x) return true;
    }
    return false;
}
//áp dụng vs mảng đã sx tăng dần
bool binarySearch(int a[], int n, int x){
    int l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r)/2;
        if(a[m] == x) return true; //tìm thấy
        else if(a[m] < x) l = m + 1; //tìm bên phải mid
        else r = m - 1; // tìm bên trái mid
    }
    return false; // ko tìm thấy 
}

//Tìm vị trí đầu tiên của x trong mảng đã sx
int firstPos(int a[], int n, int x){
    int res = -1, l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x){
            res = m;
            r = m - 1;
        }
        else if(a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return res;
}

//Tìm vị trí cuối cùng của x trong mảng đã sx
int lastPos(int a[], int n, int x){
    int res = -1, l = 0, r = n - 1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == x){
            res = m;
            l = m + 1;
        }
        else if(a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return res;
}

//Tìm vị trí đầu tiên của pt >= x
int lowerBound(int a[], int n, int x){
    int l = 0, r = n - 1, res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] >= x){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return res;
}

//Tìm vị trí đầu tiên của pt > x
int upperBound(int a[], int n, int x){
    int l = 0, r = n - 1, res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] > x){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
}