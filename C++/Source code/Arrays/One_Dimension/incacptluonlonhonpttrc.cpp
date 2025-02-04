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
	ll a[n];
	for(ll &x : a) cin >> x;
	for(int i = 0; i < n; i++){
		bool check = true;
		for(int j = 0; j < i; j++){
			if(a[j] >= a[i]){
				check = false;
				break;
			}
		}
		if(check) cout << a[i] << " ";
	}
}
