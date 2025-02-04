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
	// int mark[100001] = {0}, used[100001];
	// for(int i = 0; i < n; i++) mark[a[i]]++;

	// for(int i = 0; i < 100001; i++){
	// 	if(mark[i] != 0) cout << i << " " << mark[i] << endl;
	// }

	//Cách 1
	// for(int i = 0; i < n; i++){
	// 	if(mark[a[i]] != 0){
	// 		cout << a[i] << ' ';
	// 		mark[a[i]] = 0;
	// 	}
	// }
	// cout << endl;

	//Cách 2
	// for(int i = 0; i < n; i++){
	// 	if(used[a[i]] == 0){
	// 		cout << a[i] << " ";
	// 		used[a[i]] = 1;
	// 	}
	// }
	// cout << endl;

	//Cách 3 chạy lâu
	for(int i = 0; i < n; i++){
		bool check = true;
		for(int j = 0; j < i; j++){
			if(a[i] == a[j]){
				check = false;
				break;
			}
		}
		if(check) cout << a[i] << " ";
	}
}
