#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;

	if(n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) cout "YES";
	else cout << "NO";
}

