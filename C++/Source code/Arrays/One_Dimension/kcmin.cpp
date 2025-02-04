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
    int max = INT_MIN, min = INT_MAX; 
    int a[n]; 
    for(int &x : a) cin >> x;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(abs(a[i] - a[j]) < min) min = abs(a[i] - a[j]);
            if(abs(a[i] - a[j]) > max) max = abs(a[i] - a[j]);
        }
    }
    cout << min <<" " << max << endl;
}
