#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;
	for(int i = 0; i <= sqrt(n); i++){
		cout << 1ll * i * i << ' ';
	}
}