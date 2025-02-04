#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;
	int dem = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << dem << " "; 
			dem++;
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		int dem = i;
		for(int j = 1; j <= n; j++){
			cout << dem << " ";
			dem++;
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		int dem = i;
		for(int j = 1; j <= n; j++){
			if(j <= n - i) cout << "~";
			else cout << dem;
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		int dem = i;
		for(int j = 1; j <= i; j++){
			cout << dem << " ";
			dem += n - j;
		}
		cout << endl;
	}
}
