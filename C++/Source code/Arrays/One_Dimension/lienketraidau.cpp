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

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int a[n]; 
    for(int &x : a) cin >> x;
    if(a[0] * a[1] < 0) cout << a[0] << " ";
    for(int i = 1; i < n - 1; i++){
        if(a[i] * a[i - 1] < 0 || a[i] * a[i + 1] < 0)
            cout << a[i] << " ";
    }
    if(a[n - 2] * a[n - 1] < 0) cout << a[n - 1];
}
