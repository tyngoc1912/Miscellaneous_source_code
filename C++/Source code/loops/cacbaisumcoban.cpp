#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// S = 1+2+3+..+n --> S = n(n + 1)/2
ll sum1(int n){
	ll s = 0;
	for(int i = 1; i < n; i++){
		s += i;
	}
	return s;
}

// S = 1^2+2^2+3^2+4^2+..+n^2 --> S = n(n + 1)(2n + 1)/6
ll sum2(int n){
	ll s = 0; 
	for(int i = 1; i < n; i++){
		s += i * i;
	}
	return s;
}

//S = 1^3+2^3+3^3+..+n^3 --> S = (n * (n + 1)/2)^2
ll sum3(int n){
	ll s = 0; 
	for(int i = 1; i < n; i++){
		s += i * i * i;
	}
	return s;
}

//S=-1+2-3+4-5+6+..+(-1)^n * n --> S = n/2 (n chẵn) = (n - 1)/2 - n (n lẻ)
ll sum4(int n){
	ll s = 0;
	for(int i = 1; i < n; i++){
		if(i % 2 == 0) s += i;
		else s += -i;
		//s = (int)pow(-1, i) * i;
	}
	return s;
}

//S = 1/1 + 1/2 + 1/3 + ... + 1/n
double sum5(int n){
   double s = 0;
   for(int i = 1; i < n; i++){
      s += 1.0 / i;
   }
   return s;
}

//Tổng chia hết cho 3 có thể dùng CT 3ll*m(m+1)/2 vs m=n/3
ll sum6(int n){
	ll s = 0;
	for(int i = 3; i <= n; i += 3){
      s += i;
   }
   return s;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);
}