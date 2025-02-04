#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool nt(ll n){
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

// bool tongcs(ll n){
// 	int sum = 0;
// 	while(n != 0){
// 		sum += n % 10;
// 		n /= 10;
// 	}
// 	return nt(sum);
// }

// bool check(ll n){
// 	while(n){
// 		int r = n % 10;
// 		if(r != 2 && r != 3 && r != 5 && r != 7) return false;
// 		n /= 10; 
// 	}
// 	return true;
// }

//Chạy rất nhanh
bool csnt(ll n){
	int sum = 0;
	while(n){
		int r = n % 10;
		if(r != 2 && r != 3 && r != 5 && r != 7) return false;
		sum += r;
		n /= 10; 
	}
	return nt(sum);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	int a, b; cin >> a >> b;
	ll dem = 0;
	for(int i = a; i <= b; i++){
		if(csnt(i) && nt(i)) dem++; 
	}
	cout << dem;
}