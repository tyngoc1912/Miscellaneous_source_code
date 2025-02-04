#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	bool check = false;
	int n; cin >> n;
	for(int i = 0 ; i < n; i++){
		int x; cin >> x;
		if(x == 2022) check = true;
	}
	if(check) cout << "YES"; 
	else cout << "NO";
}