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

ll sum_digit(ll n){
	if(n < 10) return n;
	else return n % 10 + sum_digit(n / 10);
}

ll count_digit(ll n){
	if(n < 10) return 1;
	else return 1 + count_digit(n / 10);
} 

ll first_num(ll n){
	if(n < 10) return n;
	else return first_num(n / 10);
}

ll max_num(ll n){
	if(n < 10) return n;
	else return max(n % 10, max_num(n / 10));
}

ll min_num(ll n){
	if(n < 10) return n;
	else return min(n % 10, min_num(n / 10));
}

void inphai(ll n){
	if(n < 10){
		cout << n << ' '; return;
	}
	inphai(n / 10);
	cout << n % 10 << " ";
}

void intrai(ll n){
	if(n < 10){
		cout << n << ' '; return;
	}
	cout << n % 10 << " ";
	intrai(n / 10);

}

ll even_sum(ll n){
	if(n < 10){
		if(n % 2 == 0) return n;
		else return 0;
	}
	else{
		if(n % 10 % 2 == 0) return n % 10 + even_sum(n / 10);
		else return even_sum(n / 10);
	}
}

ll odd_sum(ll n){
	if(n < 10){
		if(n % 2 != 0) return n;
		else return 0;
	}
	else{
		if(n % 10 % 2 != 0) return n % 10 + odd_sum(n / 10);
		else return odd_sum(n / 10);
	}
}

bool even_check(ll n){
	if(n < 10){
		if(n % 2 == 0) return true;
		else return false;
	}
	else{
		if(n % 10 % 2 != 0) return false;
		return even_check(n / 10);
	}
}

bool odd_check(ll n){
	if(n < 10){
		if(n % 2 == 0) return false;
		else return true;
	}
	else{
		if(n % 10 % 2 == 0) return false;
		return odd_check(n / 10);
	}
}

bool dx(int a[], int l, int r){
	if(l > r) return true;
	if(a[l] != a[r]) return false;
	return dx(a, l + 1, r - 1);
}

void in1(int a[], int n){
	//Cách 1
	if(n == 1){
		cout << a[0] << " ";
		return;
	}
	//Cách 2:
	//if(n == 0) return;
	in1(a, n - 1);
	cout << a[n - 1] << ' ';
}

void in2(int a[], int n){
	// if(n == 1){
	// 	cout << a[0] << " ";
	// 	return;
	// }
	if(n == 0) return;
	cout << a[n - 1] << ' ';
	in2(a, n - 1);
}

bool check(int a[], int n){
	if(n == 1){
		if(a[0] % 2 != 0) return false;
		else return true;
	}
	else{
		if(a[n - 1] % 2 != 0) return false;
		else return check(a, n - 1);
	}
}

bool increase_check(int a[], int n){
	if(n == 1) return true;
	if(a[n - 1] <= a[n - 2]) return false;
	return increase_check(a, n - 1);
}


 void fmax(ll n){
 	if(n < 10) cout << n;
 	int max1 = 0;
 	if(n % 10 > max1){
 		max1 = n % 10;
 		fmax(n / 10);
 	}
 	cout << max1 << endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	ll n; cin >> n;
	cout << sum_digit(n) << endl;
	cout << count_digit(n) << endl;
	cout << first_num(n) << endl;
	cout << max_num(n) << endl;
	cout << min_num(n) << endl;
	inphai(n); cout << endl; intrai(n); cout << endl;
	cout << even_sum(n) << endl;
	cout << odd_sum(n) << endl;
	cout << even_check(n) << endl;
	cout << odd_check(n) << endl;
	int a[n];
	for(int &x : a) cin >> x;
	cout << dx(a, 0, n - 1) << endl;
	in1(a, n); cout << endl; in2(a, n); cout << endl;
	cout << check(a, n) << endl;
	cout << increase_check(a, n) << endl;
	//fmax(n);
}
