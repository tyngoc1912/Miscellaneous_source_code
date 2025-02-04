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

bool check1(int a[], int n){
	for(int i = 1; i < n; i++){
		if(a[i - 1] >= a[i]) return false;
	}
	return true;
}

bool check2(int a[], int n){
	int i = 1;
	while(a[i - 1] < a[i] && i < n){
		i++;
	}
	if(i == n) return true;
	else return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, i = 1; cin >> n;
	int a[n];
	for(int &x : a) cin >> x;
	while(a[i - 1] < a[i] && i < n){
		i++;
	}
	if(check2(a, n)) cout << "YES";
	else cout << "NO";
	cout << endl;

	if(check1(a, n)) cout << "YES";
	else cout << "NO";

}
