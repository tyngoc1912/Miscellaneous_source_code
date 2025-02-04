#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n];
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		// 2 < 3 || 3/2 > 1 => thua || 3/2 < 2
		if(mp.size() < k || 1.0 * mp.size() / 2 > k || 1.0 * n / 2 < k) cout << "NO" << endl;
		else{
			int dem = 0;
			for(auto it = mp.begin(); it != mp.end(); it++){
				if((*it).second > 1) ++dem;
			}
			if(dem >= 2 * k - mp.size()) cout << "YES" << endl;
			else cout << "NO" << endl; 
		}
	//	for(auto it = mp.begin(); it != mp.end(); it++){
	//		cout << (*it).first << " " << (*it).second << endl;
	//	}
	//	cout << mp.size() << endl;
	}
}