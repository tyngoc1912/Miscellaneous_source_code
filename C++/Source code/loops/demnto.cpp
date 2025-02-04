#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool nt(int a){
    if(a<2) return false;
    else{
        for(int i = 2; i <= sqrt(a); i++){
            if(a % i == 0) return false;
        }
    }
    return true;
} 

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	ll n; cin >> n;
	int dem = 0;
	while(n){
		//if(nt(n % 10)) dem++;
		int r = n % 10;
		if(r == 2 || r == 3 || r == 5 || r == 7) dem++;
		n /= 10;
	}
	cout << dem;
}