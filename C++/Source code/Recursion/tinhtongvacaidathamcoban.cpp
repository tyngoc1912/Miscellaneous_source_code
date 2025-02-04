#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <climits>
using namespace std;
using ll = long long; 
const int MOD = 1e9 + 7;

// S = 1+2+3+..+n --> S = n(n + 1)/2
ll sum1(int n){
	if(n == 1) return 1;
	else return n + sum1(n - 1);
}

// S = 1^2+2^2+3^2+4^2+..+n^2 --> S = n(n + 1)(2n + 1)/6
ll sum2(int n){
	if(n == 1) return 1;
	else return n * n + sum2(n - 1);
}

//S = 1^3+2^3+3^3+..+n^3 --> S = (n * (n + 1)/2)^2
ll sum3(int n){
	if(n == 1) return 1;
	else return n * n * n + sum3(n - 1);
}

//S=-1+2-3+4-5+6+..+(-1)^n * n --> S = n/2 (n chẵn) = (n - 1)/2 - n (n lẻ)
ll sum4(int n){
	if(n == 1) return -1;
	if(n % 2 == 0) return n + sum4(n - 1);
	else return -n + sum4(n - 1);
}

//S = 1/1 + 1/2 + 1/3 + ... + 1/n
double sum5(int n){
	if(n == 1) return 1;
	return 1.0 / n + sum5(n - 1);
}

//Tổng chia hết cho 3 có thể dùng CT 3ll*m(m+1)/2 vs m=n
ll sum6(int n){
	ll s = 0;
	for(int i = 3; i <= n; i += 3){
      s += i;
   }
}


//Giai thua chia dư cho MOD
ll gt(int n){
	if(n == 0) return 1;
	else return ((n%MOD) * (gt(n - 1)%MOD))%MOD;
}

ll fibo(int n){ //0 1 1 2 3 5 8 ...
	if(n == 1 || n == 0) return n;
	else return fibo(n - 1) + fibo(n - 2); 
}


ll fibo3(int n){ // 1 1 2 3 5 8 13 ...
	if(n == 1) return 0;
	if(n == 2) return 1;
	return fibo3(n - 1) + fibo3(n - 2);
}

ll C(int n, int k){ // nCk CT truy hồi: C(n, k)=C(n - 1, k - 1) + C(n - 1, k)
	if(k == 0 || k == n) return 1;
	return C(n - 1, k - 1) + C(n - 1, k);
}

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}
        
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

ll du(ll a, ll b){
	return ((a % MOD) * (b % MOD)) % MOD;
}

ll binpow(ll a, ll b){ // Lũy thừa nhị phân
	if(b == 0) return 1;
	ll x = binpow(a, b / 2);
	if(b % 2 == 0) return du(x, x); // a^b/2 * a^b/2
	else{
		ll res = du(x, x);
		return du(res, a); // a^b/2 * a^b/2 * a;
	}
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;
	// cout << sum1(n) << endl;
	// cout << sum2(n) << endl;
	// cout << sum3(n) << endl;
	// cout << sum4(n) << endl;
	// cout << gt(n) << endl;
	// cout << fibo(n) << endl;
	// cout << fibo3(n) << endl;
	cout << fixed << setprecision(3) << sum5(n) << endl;

}
