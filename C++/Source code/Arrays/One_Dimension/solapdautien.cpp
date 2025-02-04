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

int dem[1000001] = {0};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;
	int a[n];

	//Cách 1
	// for(int &x : a){
	// 	cin >> x;
	// 	dem[x]++;
	// 	if(dem[x] > 1){
	// 		cout << x << endl;
	// 		return 0;
	// 	}
	// }
	// cout << -1 << endl;

	//Cách 2
	for(int &x : a) cin >> x;
	for(int i = 0; i < n; i++){
		if(dem[a[i]] == 1){
			cout << a[i] << endl;
			return 0;
		}
		dem[a[i]] = 1;
	}
	cout << -1 << endl;
}
