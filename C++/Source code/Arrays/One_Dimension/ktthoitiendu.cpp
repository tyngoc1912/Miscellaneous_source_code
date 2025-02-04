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


bool check(int a[], int n){
	int d25 = 0, d50 = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 25) d25++;
		else if(a[i] == 50){
			if(d25 == 0) return false;
			else{
				d25--; d50++;
			}
		}
		else{
			if(d50 > 0 && d25 > 0){
				d50--; d25--;
			}
			else if(d25 >= 3) d25 --;
			else return false;
		}
	}
	return true;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;
	int a[n];
	for(int &x : a) cin >> x;

	if(check(a, n)) cout << "YES";
	else cout << "NO";

}
