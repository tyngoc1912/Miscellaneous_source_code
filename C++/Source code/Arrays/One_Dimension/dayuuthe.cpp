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

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int x, le = 0, chan = 0;
	while(cin >> x){
		if(x % 2 == 0) chan++;
		else le++;
	}
	if(((le + chan) % 2 == 0 && chan > le) || ((le + chan) % 2 == 1) && le > chan) cout << "YES";
	else cout << "NO";
}
