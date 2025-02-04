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

	int n, d; cin >> n >> d;
	int a[n];
	for(int &x : a) cin >> x;
	int res = 0;
	for(int i = 1; i < n; i++){
		if(a[i] <= a[i - 1]){
			int dem = a[i - 1] - a[i] + 1;
			int add;
			if(dem % d == 0) add = dem / d;
			else add = dem / d + 1;
			res += add;
			a[i] = add * d;
		}
	}
	cout << res <<endl;
}
