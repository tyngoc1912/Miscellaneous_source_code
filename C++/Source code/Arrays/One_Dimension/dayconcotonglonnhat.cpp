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

	//Cách 1
	int n; cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	int s = a[0], max = INT_MIN, dem = 1, res = 0, vt;
	
	for(int i = 1; i < n; i++){
		if(a[i - 1] != a[i]){
			dem++;
			s += a[i];
		}
		else{
			dem = 1;
			s = a[i];

		}
		if(dem > res){
			res = dem;
			vt = i;
			max = s;
		}
		else if(dem == res && s > max){
			vt = i;
			max = s;
		}
	}
	cout << res << endl;
	for(int i = vt - res + 1; i <= vt; i++) cout << a[i] << " ";

	//Cách 2: ko quan tâm tổng max vì dãy tăng dần
	int n; cin >> n;
	int a[n];
	for(int &x : a) cin >> x;

	int dem = 1, res = 0, vt;
	for(int i = 1; i < n; i++){
		if(a[i - 1] != a[i]) dem++;
		else{
			dem = 1;
			vt = i;
		}
		if(dem > res){
			res = dem;
			vt = i;
		}
	}
	cout << res << endl;
	for(int i = vt - res + 1; i <= vt; i++) cout << a[i] << " ";
}
