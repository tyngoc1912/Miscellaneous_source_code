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

    int n, pos1, pos2; cin >> n;
    int a[n];
    int max = INT_MIN, min = INT_MAX;
    for(int &x : a) cin >> x;
    //for(int x : a) cout << x << " "; 

    for(int i = 0; i < n; i++){
    	if(a[i] > max){
    		pos1 = i;
    		max = a[i];
    	}
    	if(a[i] <= min){
    		pos2 = i;
    		min = a[i];
    	}
    }
    cout << pos2 << ' ' << pos1;
    cout << endl;

}
