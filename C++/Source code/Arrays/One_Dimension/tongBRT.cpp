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

	int n, dem = 0, min_val = INT_MAX; 
	cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	// for(int i = 0; i < n - 1; i++){
	// 	for(int j = i + 1; j < n; j++){
	// 		if(min_val == abs(a[i] - a[j])) dem++;
	// 		min_val = min(min_val, abs(a[i] - a[j]));
	// 	}
	// }
	// cout << min_val << " " << dem << endl;

	// for(int i = 0; i < n - 1; i++){
	// 	for(int j = i + 1; j < n; j++){
	// 		if(abs(a[i] - a[j]) < min_val){
	// 			min_val = abs(a[i] - a[j]);
	// 			dem = 1;
	// 		}
	// 		else if(abs(a[i] - a[j]) == min_val){
	// 			dem++;
	// 		}
	// 	}
	// }
	// cout << min_val << " " << dem << endl;

	//Tối ưu
	sort(a, a + n);
	for(int i = 0; i < n - 1; i++){	
		if(abs(a[i + 1] - a[i]) < min_val){
			min_val = abs(a[i + 1] - a[i]);
			dem = 1;
		}
		else if(abs(a[i + 1] - a[i]) == min_val){
			dem++;
		}
	}
	cout << min_val << " " << dem << endl;
}
