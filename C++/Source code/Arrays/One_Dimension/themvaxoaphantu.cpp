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

	ll n, k, x, vt; cin >> n >> k >> x >> vt;
	ll a[n];
	for(ll &x : a) cin >> x;
	//Thêm phần tử tại vị trí k
	for(ll i = n - 1; i >= k; i--){
		a[i + 1] = a[i];
	}
	n++;
	a[k] = x;

	for(ll i = 0; i < n; i++) cout << a[i] << " ";

	cout << endl;

	//Xóa phần tử tại vị trí vt
	for(ll i = vt; i < n; i++){
		a[i] = a[i + 1];
	}
	n--;

	for(ll i = 0; i < n; i++) cout << a[i] << " ";
}
