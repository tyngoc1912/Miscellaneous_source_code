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

	int n; cin >> n;
	int a[n], b[n];
	for(int &x : a) cin >> x;
	for(int &x : b) cin >> x;
	sort(a, a + n); sort(b, b + n, greater<int>());
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ' << b[i] << " ";
	}
	// vector<int> res;
	// int i = 0, j = 0;
	// while(i < n && j < n){
	// 	res.push_back(a[i++]);
	// 	res.push_back(b[j++]);
	// }
	// for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
}
