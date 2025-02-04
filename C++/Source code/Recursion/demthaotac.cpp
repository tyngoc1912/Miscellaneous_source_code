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

ll step(int n){ //sinh ra cấu hình
	int x = 1e9, y = 1e9, z = 1e9;
	if(n == 1) return 0;
	if(n % 3 == 0) x = 1 + step(n / 3);
	if(n % 2 == 0) y = 1 + step(n / 2);
	if(n > 1) z = 1 + step(n - 1);
	return min(x, min(y, z));
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;
	cout << step(n);
}
