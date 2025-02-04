#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	int m, n; cin >> m >> n;
	set<int> se;
	for(int i = 0; i < m; i++){
		int temp; cin >> temp;
		se.insert(temp);
	}
	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		if(se.count(temp)) se.erase(temp);
	}
	for(int x : se) cout << x << " "; 

}
