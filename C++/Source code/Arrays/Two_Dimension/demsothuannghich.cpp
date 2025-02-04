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

bool dx(int n){
    int t = n, res = 0;
    while(n != 0){
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res == t;
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, m; cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	int dem = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			if(dx(a[i][j])){
				cout << a[i][j] << " ";
				dem++;
			}
		}
		cout << endl;
	}
	cout << dem << endl;
}
