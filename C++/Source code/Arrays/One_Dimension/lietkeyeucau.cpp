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
#define ll long long 

bool nt(int n){
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

bool dx(int n){
	if(n < 10) return true;
	int temp = 0, res = n;
	while(n != 0){
		temp = temp * 10 + n % 10;
		n /= 10;
	}
	if(temp == res) return true;
	else return false;
}

bool cp(int n){
	int c = sqrt(n);
	if(n == c*c) return true;
	else return false;
}

int tongcs(int n){
	int sum = 0;
	while(n != 0){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int a[n];
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
    for(int &x : a) cin >> x;
    for(int i = 0; i < n; i++){
    	if(nt(a[i])) d1++;
    	if(dx(a[i])) d2++;
    	if(cp(a[i])) d3++;
    	if(nt(tongcs(a[i]))) d4++;
    }
    cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
}
