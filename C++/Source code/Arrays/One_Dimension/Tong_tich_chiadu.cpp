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
const int INF = 1e9+7;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int a[n];
    //for(int &x : a) cin >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll tong = 0, tich = 1;
	for(int i = 0; i < n; i++){
		tong = (tong + a[i]) % INF;
		tich = (tich * a[i]) % INF;
		cout << tong << " " << tich << endl;
	}
	cout << tong << endl << tich;

}