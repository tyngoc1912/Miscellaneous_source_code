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

// 	4 4
// 1 2 3 6
// 2 4 6 9
// 9
// 10 6 2 16 2 9 10 3 2
// 8 8
// 9 3 5 5 6 20 1 2
// 20 6 16 2 11 18 10 12

	//Code fail 
	int dem1[100001] = {0};
	for(int i = 0; i < m; i++){
		int temp; cin >> temp;
		dem1[temp] = -1;
	}
	for(int i = 0; i < k; i++){
		int temp; cin >> temp;
		if(dem1[temp] == -1) dem1[temp] = 2;
		else if(dem1[temp] != 2) dem[temp] = 1;
	}
	vector<int> giao1, hop1;
	for(int i = 0; i < 100001; i++){
		if(dem1[i] == 2){
			giao1.push_back(i);
			hop1.push_back(i);
		}
		if(dem1[i] == 1) hop1.push_back(i);
	}
	for(int i = 0; i < giao1.size(); i++) cout << giao1[i] << " ";
	cout << endl;
	for(int i = 0; i < hop1.size(); i++) cout << hop1[i] << " ";
	cout << endl;
	cout << endl;


	// Code thành công:

	// Giao và hợp 2 mảng bất kì lộn xộn, ko sx, ko khác nhau
	// int m, k; cin >> m >> k;
	// int min1 = INT_MAX, max1 = INT_MIN;
	// int giao1[100001], hop1[100001];

	// for(int i = 0; i < m; i++){
	// 	int temp; cin >> temp;
	// 	hop1[temp] = 1;
	// 	giao1[temp] = 1;
	// 	min1 = min(min1, temp);
	// 	max1 = max(max1, temp);
	// }

	// for(int i = 0; i < k; i++){
	// 	int temp; cin >> temp;
	// 	hop1[temp] = 1;
	// 	if(giao1[temp] == 1) giao1[temp] = 2;
	// 	min1 = min(min1, temp);
	// 	max1 = max(max1, temp);
	// }

	// for(int i = min1; i <= max1; i++){
	// 	if(giao1[i] == 2) cout << i << " ";
	// }
	// cout << endl;

	// for(int i = min1; i <= max1; i++){
	// 	if(hop1[i] == 1) cout << i << " ";
	// }
	// cout << endl;
	// cout << endl;

	// int count[100001] = {0}, dem[100001] = {0}, used[100001] = {0};
	// int m, k, min1 = INT_MAX, max1 = INT_MIN; cin >> m >> k;

	// Giao và hợp của 2 mảng có pt khác nhau và sx tăng dần
	// int c[m], d[k];
	// for(int i = 0; i < m; i++){
	// 	cin >> c[i];
	// 	count[c[i]]++;
	// 	min1 = min(min1, c[i]);
	// 	max1 = max(max1, c[i]);
	// }
	// for(int i = 0; i < k; i++){
	// 	cin >> d[i];
	// 	count[d[i]]++;
	// 	min1 = min(min1, d[i]);
	// 	max1 = max(max1, d[i]);
	// }
	// vector<int> giao, hop;
	// for(int i = min1; i <= max1; i++){
	// 	if(count[i] > 1){
	// 		giao.push_back(i);
	// 		hop.push_back(i);
	// 	}
	// 	if(count[i] == 1) hop.push_back(i);
	// }
	// for(int i = 0; i < giao.size(); i++) cout << giao[i] << " ";
	// cout << endl;
	// for(int i = 0; i < hop.size(); i++) cout << hop[i] << " ";
	// cout << endl;
	// cout << endl;

	// Đếm tần suất
	// int n, min_val = INT_MAX, max_val = INT_MIN; cin >> n;
	// int a[n];
	// for(int i = 0; i < n; i++){
	// 	cin >> a[i];
	// 	dem[a[i]]++;
	// 	max_val = max(max_val, a[i]);
	// 	min_val = min(min_val, a[i]);
	// }
	// for(int i = 0; i < n; i++){
	// 	if(used[a[i]] == 0){
	// 		cout << a[i] << " " << dem[a[i]] << endl;
	// 		used[a[i]] = 1;
	// 	}
	// }
	// cout << endl;

	// for(int i = min_val; i <= max_val; i++){
	// 	if(dem[i] != 0) cout << i << " " << dem[i] << endl; 
	// }
}
