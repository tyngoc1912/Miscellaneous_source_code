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

	int n, m; cin >> n >> m;
	int a[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	//Giá trị min và max trong mảng 2 chiều
	int max_val = INT_MIN, min_val = INT_MAX;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			max_val = max(a[i][j], max_val);
			min_val = min(a[i][j], min_val);
		}
	}
	cout << min_val << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(min_val == a[i][j]) cout << i + 1 << " " << j + 1 << endl;
		}
	}
	cout << max_val << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(max_val == a[i][j]) cout << i + 1 << " " << j + 1 << endl;
		}
	}
}
