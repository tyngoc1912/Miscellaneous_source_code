#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	int n, q, x; cin >> n;
	//SET
	// set<int> se;
	// for(int i = 0; i < n; i++){
	// 	int temp; cin >> temp;
	// 	se.insert(temp);
	// }
	// cin >> q;
	// while(q--){
	// 	cin >> x;
	// 	auto it = se.find(x); //if(se.count(x)) ...
	// 	if(it != se.end()) cout << "YES" << endl;
	// 	else cout << "NO" << endl;
	// }


	//MAP
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		mp[temp]++;
	}
	cin >> q;
	while(q--){
		cin >> x;
		auto it = mp.find(x);
		if(it != mp.end()) cout << "YES" endl;
		else cout << "NO" << endl;
	}
}


