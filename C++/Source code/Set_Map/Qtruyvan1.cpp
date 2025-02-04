#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	multiset<int> se;
	int n, q;
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		se.insert(temp);
	}
	cin >> q;
	while(q--){
		int t, x;
		cin >> t >> x;
		if(t == 1) se.insert(x);
		else if(t == 2){
			auto it = se.find(x);
			if(it != se.end()) se.erase(it);
		} 
		else{
			auto it = se.find(x);
			if(it != se.end()) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}