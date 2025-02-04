#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <utility>
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

	int n, k; cin >> n >> k;
	int a[n];
	for(int &x : a) cin >> x;
	sort(a, a + n);
	int min_val = min(k, n - k);
	for(int x : a) cout << x << " ";
	cout << endl;
	ll sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; i++){
		if(i < min_val) sum1 += a[i];
		else sum2 += a[i];
	} 
	cout << sum2 - sum1 << endl;
}
