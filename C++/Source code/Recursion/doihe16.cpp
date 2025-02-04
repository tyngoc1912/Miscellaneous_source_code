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

void convert(ll n){
	if(n == 0) return;
	convert(n / 16);
	int r = n % 16; // r = (0, 15)
	if(r < 10) cout << r;
	else cout << (char)(r + 55); // A B C D ... = 65 66 67 68 ...
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	ll n; cin >> n;
	convert(n);

}
