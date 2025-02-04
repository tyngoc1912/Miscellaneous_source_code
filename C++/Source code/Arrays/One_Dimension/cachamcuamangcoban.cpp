#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <climits>
using namespace std;
using ll = long long; 

int d1[100001] = {0}, d2[100001] = {0};

bool oddNum(int n){
	while(n){
		if(n % 10 % 2 == 0) return false;
		n /= 10;
	}
	return true;
}

double avg(int a[], int n){
	ll s = 0; int dem = 0;
	for(int i = 0; i < n; i++){
		s += a[i];
		dem++;
	}
	return (double) s / dem;
}


void reverse(int a[], int n){
	int temp, l = 0, r = n - 1;
	while(l <= r){
		//swap(a[l], a[r]);
		temp = a[l];
		a[l] = a[r];
		a[r] = temp;
		l++; r--;
	}
}

bool mangdx(int a[], int n){
	int l = 0, r = n - 1;
	while(l <= r){
		if(a[l] != a[r]) return false;
		l++; r--;
	}
	return true;
}

void bubbleSort(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j]) swap(a[i], a[j]);
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, dem = 0; cin >> n;
	int a[n], b[n];
	for(int &x : a) cin >> x;

	for(int i = 0; i < n; i++){
		if(oddNum(a[i])){
			b[dem] = a[i];
			dem++;
		}
	}
	cout << dem << endl;
	for(int i = 0; i < dem; i++) cout << b[i] << " ";
	cout << endl;
	cout << endl;

	for(int i = 0; i < n; i++){
		d1[a[i]]++; d2[a[i]]++;
	}
	for(int i = 0; i < n; i++){
		if(d1[a[i]] != 0){
			cout << a[i] << ' ' << d1[a[i]] << endl;
			d1[a[i]] = 0;
		}
	}
	cout << endl;

	for(int i = 0; i < 100001; i++){
		if(d2[i] != 0) cout << i << " " << d2[i] << endl;
	}
	cout << endl;

	cout << avg(a, n) << endl;
	if(mangdx(a, n)) cout << "YES";
	else cout << "NO";
	cout << endl;

	reverse(a, n);
	for(int i = 0; i < n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;

	bubbleSort(a, n);
	for(int x : a) cout << x << ' ';
}
