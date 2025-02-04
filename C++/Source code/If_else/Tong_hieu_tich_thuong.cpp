#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// int a, b, c;
	// cin >> a >> b >> c;
	// ll res = 1ll*a*(b + c) + 1ll*b*(a + c);
	// cout << res;

	int a, b; cin >> a >> b;
	cout << a + b << endl;
	cout << a - b << endl;
	cout << 1ll*a*b << endl;
	if(b == 0) cout << "INVALID"; else cout << fixed << setprecision(4) << 1.0*a/b << endl;
}