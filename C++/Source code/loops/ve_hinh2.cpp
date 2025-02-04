#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n; cin >> n;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n ; j++){
			if(j <= n - i + 1) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(j <= n - i) cout << " ";
			else cout << "*";	
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(j < i) cout << " ";
			else cout << "*";	
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(j == 1 || i == n || j == i) cout << "*";
			else cout << " ";	
		}
		cout << endl;
	}
	cout << endl;

}

