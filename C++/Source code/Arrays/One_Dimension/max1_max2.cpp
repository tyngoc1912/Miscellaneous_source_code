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

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    int max1 = INT_MIN, max2 = INT_MIN;
	for(int i = 0; i < n; i++){
		if(a[i] >= max1){
			max2 = max1;
			max1 = a[i];
			cout << max1 << ' '<< max2 << endl;
		}
		if(a[i] < max1 && a[i] > max2) max2 = a[i];

	}
	cout << max1 << " " << max2;
}
