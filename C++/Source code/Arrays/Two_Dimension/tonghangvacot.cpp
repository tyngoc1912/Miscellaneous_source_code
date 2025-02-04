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

	for(int i = 0; i < n; i++){
		ll sum = 0;
		for(int j = 0; j < m; j++){
			sum += a[i][j];
		}
		cout << sum << " ";
	}
	cout << endl;

	for(int i = 0; i < n; i++){
		ll sum = 0;
		for(int j = 0; j < m; j++){
			sum += a[j][i];
		}
		cout << sum << " ";
	}
	cout << endl;
}
