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
const int MOD = 1e9+7;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	sort(a, a + n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += (i * a[i]) % MOD;
	}
	cout << sum << endl;
}
