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
	int a[n];
	for(int &x : a) cin >> x;
	sort(a, a + n);
	ll first = 0, second = 0;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0) first = first * 10 + a[i];
		else second = second * 10 + a[i];
	}
	cout << first << " " << second << endl;
	cout << first + second << endl;
}
