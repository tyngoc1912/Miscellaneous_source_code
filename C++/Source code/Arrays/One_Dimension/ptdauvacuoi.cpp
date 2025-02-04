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
#include <cstring>
using namespace std;
using ll = long long; 

int mark[1000001] = {0};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, x, first = -1, last = -1; cin >> n >> x;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == x){
			if(first == -1) first = i + 1;
			last = i + 1;
		}
	}
	// if(first != -1 && last != -1) cout << first + 1 << " " << last + 1;
	// else cout << first << " " << last << endl;
	cout << first << " " << last;
	//memset(mark, 0, sizeof(mark));

}
