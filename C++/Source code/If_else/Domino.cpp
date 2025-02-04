#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m; cin >> n >> m;
	if(n % 2 == 0) cout << 1ll* n/2 * m;
	else cout << 1ll * ((n/2 * m) + (m/2));

	//kt xem số hàng có bị lẻ ko để xếp dọc thanh domino nếu bị lẻ 1 hàng thì xếp ngang ở hàng đó
}
