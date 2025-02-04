#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cnt[1000001] = {0};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	//DEM PHAN PHOI DUOC SAP XEP
	// int n, min_val = INT_MAX, max_val = INT_MIN; cin >> n;
	// int a[n];
	// for(int i = 0; i < n; i++){
	// 	cin >> a[i];
	// 	cnt[a[i]]++;
	// 	min_val = min(a[i], min_val);
	// 	max_val = max(a[i], max_val);
	// }
	// for(int i = min_val; i <= max_val; i++){
	// 	if(cnt[i] != 0) cout << i << ' ';
	// }

	//DEM PHAN PHOI THEO THU TU XUAT HIEN
	// int n; cin >> n;
	// int a[n];
	// for(int i = 0; i < n; i++){
	// 	cin >> a[i];
	// 	cnt[a[i]]++;
	// }
	// for(int i = 0; i < n; i++){
	// 	if(cnt[a[i]] != 0) cout << a[i] << ' ';
	// 	cnt[a[i]] = 0;
	// }

	//SET
	int n; cin >> n;
	set<int> se;
	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		if(se.count(temp) == 0){
			cout << temp << ' ';
			se.insert(temp);
		}
		else se.insert(temp);
	}
}