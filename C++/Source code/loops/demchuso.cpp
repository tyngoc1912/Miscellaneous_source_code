#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	ll n; cin >> n;
	int dem = 0;
	if(n == 0){
		cout << 1;
		return;
	}
	while(n){
		dem++;
		n /= 10;
	}
	cout << dem;
}