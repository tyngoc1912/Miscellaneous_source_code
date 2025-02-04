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

	//Vét cạn:

	//for(int i = 0; i < n; i++){
	// 	int max1 = INT_MIN, min1 = INT_MAX;
	// 	for(int j = 0; j < n; j++){
	// 		if(i != j && a[i] >= a[j]){
	// 			max1 = max(max1, abs(a[i] - a[j]));
	// 			min1 = min(min1, abs(a[i] - a[j]));
	// 		}
	// 		if(i != j && a[i] < a[j]){
	// 			max1 = max(max1, abs(a[j] - a[i]));
	// 			min1 = min(min1, abs(a[j] - a[i]));
	// 		}
	// 	}
	// 	cout << min1 << ' ' << max1 << endl;
	// }

	// If else

	for(int i = 0; i < n; i++){
		if(i == 0) cout << a[i + 1] - a[i] << " " << a[n - 1] - a[0] << endl; 
		else if(i == n - 1) cout << a[n - 1] - a[n - 2] << " " << a[n - 1] - a[0] << endl;
		else{
			cout << min(a[i] - a[i - 1], a[i + 1] - a[i]) << " " << max(a[i] - a[0], a[n - 1] - a[i]) << endl;
		} 
	}
}
