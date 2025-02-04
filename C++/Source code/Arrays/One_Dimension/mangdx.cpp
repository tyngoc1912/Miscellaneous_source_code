#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <climits>
using namespace std;
#define ll long long 

bool check1(int a[], int n){
    int l = 0, r = n - 1;
    while(l <= r){
        if(a[l] != a[r]) return false;
        l++; r--;
    }
    return true;
}

check2(int a[], int n){
    for(int i = 0; i < n/2; i++){
        if(a[i] != a[n - i - 1]) return false;
    }
    return true;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int a[n]; 
    for(int &x : a) cin >> x;

    if(check1(a, n)) cout << "YES";
    else cout << "NO";
    cout << endl;
    if(check2(a, n)) cout << "YES";
    else cout << "NO";

}
