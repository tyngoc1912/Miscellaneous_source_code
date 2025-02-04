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

	//mảng cộng dồn: tính tổng từ l --> k
	// 1 2 3 4 6 7 8
	// 1 3 6 10 16 23 31 --> s từ l --> k = dp[r] - dp[l - 1]
	int n; cin >> n;
	int a[n]; 
	ll dp[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i == 0) dp[i] = a[i];
		else dp[i] = dp[i - 1] + a[i];
	}
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r; --l; --r;
		if(l == 0) cout << dp[r];
		else cout << dp[r] - dp[l - 1];
	}

}