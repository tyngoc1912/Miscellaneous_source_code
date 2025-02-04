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
    int mark[1001] = {0}, used[1001] = {0};
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
    	mark[a[i]]++;
    }

    for(int i = 0; i < n; i++){
    	if(used[a[i]] == 0){
    		cout << a[i] << " " << mark[a[i]] << endl;
    		used[a[i]] = 1;
    	}
    }

    cout << endl;

    for(int i = 0; i < 1001; i++){
    	if(mark[i] != 0) cout << i << ' ' << mark[i] << endl;
    }
    cout << endl;

    for(int i = 0; i < n; i++) cout << a[i] << " " << mark[a[i]] << endl;

   	cout << endl;

    int res1 = INT_MIN, res2 = INT_MAX, max1 = INT_MIN, min1 = INT_MAX;
    for(int i = 0; i < n; i++){
    	if(mark[a[i]] > max1 || (mark[a[i]] == max1 && a[i] > res1)){
    		max1 = mark[a[i]];
    		res1 = a[i];
    	}
    	if(mark[a[i]] < min1 || (mark[a[i]] == min1 && a[i] < res2)){
    		min1 = mark[a[i]];
    		res2 = a[i];
    	}
    }
    cout << res1 << " " << res2 << endl;
}
