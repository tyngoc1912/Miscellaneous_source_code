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
using ll = long long; 

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;
	int a[n]; 
	for(int &x : a) cin >> x;
	ll res = 0;
	for(int i = 1; i < n; i++){
		if(a[i - 1] >= a[i]){
			res += a[i - 1] - a[i] + 1;
			a[i] += a[i - 1] - a[i] + 1;
		}
	}
	cout << res << endl;
}
