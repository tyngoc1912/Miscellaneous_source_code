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

void tron(int a[], int b[], int m, int n){
	//Trộn 2 mảng tăng dần
	int i = 0, j = 0;
	while(i < m && j < n){
		if(a[i] <= b[j]){
			cout << a[i] << " ";
			i++;
		}
		else{
			cout << b[j] << " ";
			j++;
		}
	}
	while(i < m){
		cout << a[i] << ' ';
		i++;
	}
	while(j < n){
		cout << b[j] << ' ';
		j++;
	}
}

void giaoHop(int a[], int b[], int m, int n){
	//Giao và hợp 2 mảng tăng dần
	int i = 0, j = 0;
	vector<int> giao, hop;
	while(i < m && j < n){
		if(a[i] == b[j]){
			giao.push_back(a[i]);
			hop.push_back(a[i]);
			i++; j++;
		}
		if(a[i] < b[j]){
			hop.push_back(a[i]);
			i++;
		}
		if(a[i] > b[j]){
			hop.push_back(b[j]);
			j++;
		}
	}
	while(i < m){
		hop.push_back(a[i]);
		i++;
	}
	while(j < n){
		hop.push_back(b[j]);
		j++;
	}

	for(auto x : giao) cout << x << " ";
	cout << endl;
	for(auto x : hop) cout << x << " ";
}

void reverse(int a[], int n){
	int temp, l = 0, r = n - 1;
	while(l <= r){
		temp = a[l];
		a[l] = a[r];
		a[r] = temp;
		l++; r--;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int m, n; cin >> m >> n;
	int a[m], b[n];
	for(int &x : a) cin >> x;
	for(int &x : b) cin >> x;

	//Tron 2 mang tang dan
	tron(a, b, m ,n); cout << endl;

	//Mảng giao và hợp
	giaoHop(a, b, m, n);

	//Đảo mảng a, b
	cout << endl;
	reverse(a, m); reverse(b, n);
	for(int x : a) cout << x << " ";
	cout << endl;
	for(int x : b) cout << x << " ";
}
