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
using namespace std;
#define ll long long 

ll f[100];
void fibo(){
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i <= 92; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	//for(int i = 0; i <= 92; i++) cout << f[i]<< ' ';
}

bool check(ll n){
	for(int i = 0; i <= 92; i++){
		if(n == f[i]) return true;
	}
	return false;
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, dem = 0; cin >> n;
    ll a[n];
    for(ll &x : a) cin >> x;
    fibo();
    for(int i = 0; i < n; i++){
    	if(check(a[i])){
    		cout << a[i] << " ";
    		dem++;
    	}
    }
    if(dem == 0) cout << "NONE";
    
}
