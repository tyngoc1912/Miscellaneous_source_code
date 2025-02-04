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
	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		a[i] = 1ll * temp * temp;
	}
	sort(a, a + n);
	for(int i = n - 1; i >= 2; i--){
		int l = 0, r = i - 1;
		while(l < r){
			if(a[l] + a[r] == a[i]){
				cout << "YES"; 
				return 0;
			}
			else if(a[l] + a[r] < a[i]) l++;
			else r--;
		}
	}
	cout << "NO" << endl;
}
