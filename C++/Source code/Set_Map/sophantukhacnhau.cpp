#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	// int a[6] = {0, 1, 2, 3, 4, 5};
	// vector<int> v (a, a + 6);
	// for(int x : v) cout << x << " ";

	// vector<int> y (v.begin(), v.end());
	// for(int x : y) cout << x << " ";

	int n; cin >> n;
	//SET
	// set<int> se;
	// for(int i = 0; i < n; i++){
	// 	int temp; cin >> temp;
	// 	se.insert(temp);
	// }
	// cout << se.size() << endl;

	//MAP
	// map<int, int> mp;
	// for(int i = 0; i < n; i++){
	// 	int temp; cin >> temp;
	// 	mp[temp]++;
	// }
	// cout << mp.size() << endl;
	// for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
	// 	cout << (*it).first << ' ' <<(*it).second << endl;
	// }

	//SORT
	int dem = 1, a[n];
	for(int &x : a) cin >> x;
	sort(a, a + n);
	for(int i = 1; i < n; i++){
		if(a[i] != a[i - 1]) dem++;
	}
	cout << dem << endl;
}